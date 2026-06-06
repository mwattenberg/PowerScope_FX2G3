/***************************************************************************//**
* \file main.c
* \version 1.0
*
* \brief Main source file of the FX2G3 device - UART and SPI test application with USB streaming.
*
* Tests basic UART and SPI functionality by outputting test signals
* and streaming them over High-Speed USB bulk endpoint 0x81 (Bulk IN).
*
*******************************************************************************
* \copyright
* (c) (2026), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#include "cy_pdl.h"
#include <string.h>
#include <math.h>
#include "app_version.h"
#include "cybsp.h"
#include "cy_debug.h"

/* USB and HBDMA Headers */
#include "cy_usb_common.h"
#include "cy_usb_usbd.h"
#include "usb_descriptors.h"
#include "cy_usbhs_cal_drv.h"
#include "cy_hbdma.h"
#include "cy_hbdma_mgr.h"

/* Frame layout: 2-byte sync (0xAA 0xAA) + 8 channels × 2 bytes = 18 bytes per frame.
 * At HS, each DMA buffer is 512 bytes; pack as many complete frames as fit. */
#define FRAME_SIZE          18
#define FRAMES_PER_PACKET   (512 / FRAME_SIZE)   /* 28 frames × 18 = 504 bytes */

/* Global variables associated with High BandWidth DMA setup. */
cy_stc_hbdma_context_t HBW_DrvCtxt;     /* High BandWidth DMA driver context. */
cy_stc_hbdma_dscr_list_t HBW_DscrList;  /* High BandWidth DMA descriptor free list. */
cy_stc_hbdma_buf_mgr_t HBW_BufMgr;      /* High BandWidth DMA buffer manager. */
cy_stc_hbdma_mgr_context_t HBW_MgrCtxt; /* High BandWidth DMA manager context. */

cy_stc_usb_usbd_ctxt_t usbdCtxt;
cy_stc_usb_cal_ctxt_t hsCalCtxt;
cy_stc_hbdma_channel_t ep1InDmaChannel;

volatile bool usbConfigured = false;
volatile bool streamingEnabled = false;

/* Debug logging via USBFS CDC (appears as a COM port; driven by cy_debug / CyUsbFsCdc). */
#define DEBUG_LEVEL  (3u)
#define LOGBUF_SIZE  (1024u)
uint8_t logBuff[LOGBUF_SIZE];
cy_stc_debug_config_t dbgCfg = {
    .pBuffer   = logBuff,
    .traceLvl  = DEBUG_LEVEL,
    .bufSize   = LOGBUF_SIZE,
    .dbgIntfce = CY_DEBUG_INTFCE_USBFS_CDC,
    .printNow  = true
};

/* 256-point sine lookup table. Values are uint16, centered at 2048 with amplitude 2000
 * (range 48..4048), compatible with both int16 and uint16 parsers on the host. */
static uint16_t sineTable[256];

static void SineTable_Init(void)
{
    for (int i = 0; i < 256; i++) {
        sineTable[i] = (uint16_t)(2048 + (int)(2000.0f * sinf(2.0f * 3.14159265f * i / 256.0f)));
    }
}

/* Function prototypes */
void SetupEp1Dma(void);
extern void Ep1InDma_ISR(void);
void InEpDma_ISR(uint8_t endpNum);
void Cy_USB_HS_ISR(void);
void HbDma_Callback(cy_stc_hbdma_channel_t *handle, cy_en_hbdma_cb_type_t type, cy_stc_hbdma_buff_status_t *pbufStat, void *userCtx);
void SetupCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg);
void SetConfigCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg);
void BusResetCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg);
void Cy_Fx2g3_OnResetInit(void);
void Cy_OnResetUser(void);
void Cy_Fx2g3_InitPeripheralClocks(bool adcClkEnable, bool usbfsClkEnable);
void USB_Init(void);
bool USB_Stream_Write(const uint8_t* data, uint32_t length);

/**
* \brief Initialize application UART (SCB1) for MCU telemetry and the USBFS CDC debug port.
*/
void UART_Init(void)
{
    extern const cy_stc_scb_uart_config_t UART_config;
    Cy_SCB_UART_Init(UART_HW, &UART_config, NULL);
    Cy_SCB_UART_Enable(UART_HW);

    /* Stand up the USBFS CDC debug port (UART_DEBUG / second COM port). */
    Cy_Debug_LogInit(&dbgCfg);
}

/**
* \brief Initialize SPI (SCB5) as Master
* Uses device configurator-generated config
*/
void SPI_Init(void)
{
   extern const cy_stc_scb_spi_config_t SPI_config;
    
   /* Using low-level API, pass NULL for context */
   Cy_SCB_SPI_Init(SPI_HW, &SPI_config, NULL);
   Cy_SCB_SPI_Enable(SPI_HW);
}

/**
* \brief Initialize application
* Handles system initialization, peripheral clocking, and watchdog
*/
void AppInit(void)
{
   /* Initialize the PDL driver library and set the clock variables */
   Cy_PDL_Init(&cy_deviceIpBlockCfgFX3G2);
    
   /* Initialize the device and board peripherals */
   cybsp_init();
    
   /* Unlock and disable the watchdog */
   Cy_WDT_Unlock();
   Cy_WDT_Disable();
    
   /* Enable interrupts */
#if (CY_CPU_CORTEX_M4)
   __set_BASEPRI(0);
#endif
   __enable_irq();
    
   /* Initial delay to allow peripherals to stabilize */
   Cy_SysLib_Delay(100);
    
   /* Build sine lookup table */
   SineTable_Init();

   /* Initialize UART and SPI */
   UART_Init();
   SPI_Init();

   /* Initialize USB Interface */
   USB_Init();
}

/**
* \brief Entry to the application
*/
int main(void)
{
   uint32_t loopCount = 0;
    
   /* Initialize application */
   AppInit();
    
   DBG_APP_INFO("=== FX2G3 UART/SPI Test Started ===\r\n");
   Cy_SysLib_Delay(100);

   /* Phase accumulators — one per channel. Wrap naturally at 256 (uint8_t overflow).
    * Different phaseInc values produce distinct frequencies: freq = Fs * inc / 256.
    * At ~437 kSa/s: inc=1→1.7 kHz, inc=2→3.4 kHz, inc=3→5.1 kHz, inc=5→8.5 kHz,
    *                inc=7→12 kHz, inc=11→19 kHz, inc=13→22 kHz, inc=17→29 kHz. */
   static uint8_t phase[8] = {0};
   static const uint8_t phaseInc[8] = {1, 2, 3, 5, 7, 11, 13, 17};

   /* Main test loop — runs as fast as the DMA pipeline allows. */
   while (1) {
       if (loopCount % 100 == 0) {
           DBG_APP_INFO("LOOP_%d\r\n", (int)loopCount);
       }

       /* Send SPI test pattern */
       Cy_SCB_SPI_Write(SPI_HW, 0xAA);
       Cy_SCB_SPI_Write(SPI_HW, (uint8_t)loopCount & 0xFF);
       while (Cy_SCB_SPI_IsBusBusy(SPI_HW)) {}

       /* Pack FRAMES_PER_PACKET frames into one 512-byte USB packet.
        * Each frame: 2-byte sync 0xAAAA + 8 channels as uint16 LE. */
       if (streamingEnabled && usbConfigured) {
           uint8_t usb_packet[512];

           for (int f = 0; f < FRAMES_PER_PACKET; f++) {
               uint8_t *p = &usb_packet[f * FRAME_SIZE];
               p[0] = 0xAA;
               p[1] = 0xAA;
               for (int ch = 0; ch < 8; ch++) {
                   uint16_t val = sineTable[phase[ch]];
                   phase[ch] += phaseInc[ch];
                   p[2 + ch * 2]     = (uint8_t)(val & 0xFF);
                   p[2 + ch * 2 + 1] = (uint8_t)(val >> 8);
               }
           }

           USB_Stream_Write(usb_packet, sizeof(usb_packet));
       }

       loopCount++;
   }
    
   return 0;
}

/**
 * \name Cy_USB_HS_ISR
 * \brief Handler for USB-HS Interrupts.
 */
void Cy_USB_HS_ISR(void)
{
    Cy_USBHS_Cal_IntrHandler(&hsCalCtxt);
}

/**
 * \name SysTick_Handler
 * \brief SysTick interrupt service routine for 1ms ticks.
 */
void SysTick_Handler(void)
{
    Cy_USBD_TickIncrement(&usbdCtxt);
}

/**
 * \name Cy_Fx2g3_InitPeripheralClocks
 * \brief Enables clocks to different peripherals on the FX2G3 device.
 */
void Cy_Fx2g3_InitPeripheralClocks(bool adcClkEnable, bool usbfsClkEnable)
{
    if (adcClkEnable) {
        /* Divide PERI clock at 75 MHz by 75 to get 1 MHz clock using 16-bit divider #1. */
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1, 74);
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1);
        Cy_SysLib_DelayUs(10U);
        Cy_SysClk_PeriphAssignDivider(PCLK_LVDS2USB32SS_CLOCK_SAR, CY_SYSCLK_DIV_16_BIT, 1);
    }

    if (usbfsClkEnable) {
        /* Divide PERI clock at 75 MHz by 750 to get 100 KHz clock using 16-bit divider #2. */
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2, 749);
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2);
        Cy_SysLib_DelayUs(10U);
        Cy_SysClk_PeriphAssignDivider(PCLK_USB_CLOCK_DEV_BRS, CY_SYSCLK_DIV_16_BIT, 2);
    }
}

/**
 * \name Cy_Fx2g3_OnResetInit
 * \brief Enables high bandwidth RAM at reset.
 */
void Cy_Fx2g3_OnResetInit(void)
{
    /* Enable clk_hf4 with IMO as input. */
    SRSS->CLK_ROOT_SELECT[4] = SRSS_CLK_ROOT_SELECT_ENABLE_Msk;

    /* Enable LVDS2USB32SS IP and select clk_hf[4] as clock input. */
    MAIN_REG->CTRL = (
            MAIN_REG_CTRL_IP_ENABLED_Msk |
            (1UL << MAIN_REG_CTRL_NUM_FAST_AHB_STALL_CYCLES_Pos) |
            (1UL << MAIN_REG_CTRL_NUM_SLOW_AHB_STALL_CYCLES_Pos) |
            (3UL << MAIN_REG_CTRL_DMA_SRC_SEL_Pos));
}

/**
 * \name Cy_OnResetUser
 * \brief Startup hook before scatter loading is performed.
 */
void Cy_OnResetUser(void)
{
    Cy_Fx2g3_OnResetInit();
}

/**
 * \name HbDma_Callback
 * \brief Empty callback for HBDMA.
 */
void HbDma_Callback(cy_stc_hbdma_channel_t *handle, cy_en_hbdma_cb_type_t type, cy_stc_hbdma_buff_status_t *pbufStat, void *userCtx)
{
    (void)handle;
    (void)type;
    (void)pbufStat;
    (void)userCtx;
}

/**
 * \name SetupEp1Dma
 * \brief Configures Endpoint 1 IN (Bulk IN 0x81) and its HBDMA channel.
 */
void SetupEp1Dma(void)
{
    cy_stc_usb_endp_config_t endpConfig;
    extern void Ep1InDma_ISR(void);

    DBG_APP_INFO("[SetupEp1Dma] Starting EP1 HBDMA setup...\r\n");

    if (ep1InDmaChannel.state != CY_HBDMA_CHN_NOT_CONFIGURED) {
        DBG_APP_INFO("[SetupEp1Dma] Existing channel found. Disabling & destroying...\r\n");

        cy_en_hbdma_mgr_status_t dis_status = Cy_HBDma_Channel_Disable(&ep1InDmaChannel);
        DBG_APP_INFO("[SetupEp1Dma] Disabling channel, status: 0x%x\r\n", (unsigned int)dis_status);
        Cy_SysLib_Delay(1);

        cy_en_hbdma_mgr_status_t dest_status = Cy_HBDma_Channel_Destroy(&ep1InDmaChannel);
        DBG_APP_INFO("[SetupEp1Dma] Destroying channel, status: 0x%x\r\n", (unsigned int)dest_status);
        Cy_SysLib_Delay(1);
    }
    
    /* 1. Configure the Endpoint in USBD */
    endpConfig.endpType = CY_USB_ENDP_TYPE_BULK;
    endpConfig.endpDirection = CY_USB_ENDP_DIR_IN;
    endpConfig.valid = true;
    endpConfig.endpNumber = 1;
    /* Packetsize is 512 for High Speed, 64 for Full Speed */
    uint16_t maxPktSize = (Cy_USBD_GetDeviceSpeed(&usbdCtxt) == CY_USBD_USB_DEV_HS) ? 512 : 64;
    
    DBG_APP_INFO("[SetupEp1Dma] USB Device Speed: %d, maxPktSize: %u\r\n",
                 (int)Cy_USBD_GetDeviceSpeed(&usbdCtxt), (unsigned int)maxPktSize);

    endpConfig.maxPktSize = maxPktSize;
    endpConfig.isoPkts = 0;
    endpConfig.burstSize = 0;
    endpConfig.streamID = 0;
    endpConfig.interval = 0;
    endpConfig.allowNakTillDmaRdy = true;

    Cy_USB_USBD_EndpConfig(&usbdCtxt, endpConfig);
    Cy_USBD_ResetEndp(&usbdCtxt, 1, CY_USB_ENDP_DIR_IN, false);
    Cy_SysLib_Delay(1);

    /* 2. Configure the HBDMA channel for EP1 IN */
    cy_stc_hbdma_chn_config_t dmaConfig;
    memset(&dmaConfig, 0, sizeof(dmaConfig));
    dmaConfig.size         = maxPktSize;
    dmaConfig.prodBufSize  = maxPktSize;
    dmaConfig.count        = 4; /* Use 4 buffers for ping-pong */
    dmaConfig.prodHdrSize  = 0;
    dmaConfig.eventEnable  = 0;
    dmaConfig.intrEnable   = LVDSSS_LVDS_ADAPTER_DMA_SCK_INTR_CONSUME_EVENT_Msk;
    dmaConfig.bufferMode   = false;
    dmaConfig.chType       = CY_HBDMA_TYPE_MEM_TO_IP;
    dmaConfig.prodSckCount = 1;
    dmaConfig.prodSck[0]   = CY_HBDMA_VIRT_SOCKET_WR;
    dmaConfig.consSckCount = 1;
    dmaConfig.consSck[0]   = (cy_hbdma_socket_id_t)(CY_HBDMA_USBHS_IN_EP_00 + 1); /* EP1 IN */
    dmaConfig.usbMaxPktSize = maxPktSize;
    dmaConfig.cb           = HbDma_Callback;
    dmaConfig.userCtx      = NULL;

    cy_en_hbdma_mgr_status_t create_status = Cy_HBDma_Channel_Create(&HBW_MgrCtxt, &ep1InDmaChannel, &dmaConfig);
    DBG_APP_INFO("[SetupEp1Dma] Channel_Create: 0x%x state: %d\r\n",
                 (unsigned int)create_status, (int)ep1InDmaChannel.state);
    
    /* 3. Initialize CPU DMA Interrupt for DW1 channel 1 (IN endpoint 1) */
    cy_stc_sysint_t intrCfg;
    intrCfg.intrPriority = 5;
    intrCfg.intrSrc = (IRQn_Type)(cpuss_interrupts_dw1_0_IRQn + 1);
    
    Cy_SysInt_Init(&intrCfg, Ep1InDma_ISR);
    NVIC_EnableIRQ(intrCfg.intrSrc);
    
    /* Enable HBDMA Channel */
    cy_en_hbdma_mgr_status_t en_status = Cy_HBDma_Channel_Enable(&ep1InDmaChannel, 0);
    DBG_APP_INFO("[SetupEp1Dma] Channel_Enable: 0x%x\r\n", (unsigned int)en_status);
}

/**
 * \name InEpDma_ISR
 * \brief Interrupt handler for EP1 IN DMA completions (overrides library weak symbol).
 */
void InEpDma_ISR(uint8_t endpNum)
{
    (void)endpNum;
    Cy_HBDma_Mgr_HandleDW1Interrupt(&HBW_MgrCtxt);
}

/**
 * \name SetupCallback
 * \brief Handles control endpoint 0 requests, including custom WinUSB requests.
 */
void SetupCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
{
    uint32_t setupData0 = pMsg->data[0];
    uint32_t setupData1 = pMsg->data[1];

    uint8_t bmRequest = (uint8_t)((setupData0 & CY_USB_BMREQUEST_SETUP0_MASK) >> CY_USB_BMREQUEST_SETUP0_POS);
    uint8_t bRequest = (uint8_t)((setupData0 & CY_USB_BREQUEST_SETUP0_MASK) >> CY_USB_BREQUEST_SETUP0_POS);
    uint16_t wValue = (uint16_t)((setupData0 & CY_USB_WVALUE_SETUP0_MASK) >> CY_USB_WVALUE_SETUP0_POS);
    uint16_t wIndex = (uint16_t)((setupData1 & CY_USB_WINDEX_SETUP1_MASK) >> CY_USB_WINDEX_SETUP1_POS);
    uint16_t wLength = (uint16_t)((setupData1 & CY_USB_WLENGTH_SETUP1_MASK) >> CY_USB_WLENGTH_SETUP1_POS);

    uint8_t reqType = ((bmRequest & CY_USB_CTRL_REQ_TYPE_MASK) >> CY_USB_CTRL_REQ_TYPE_POS);
    uint8_t bTarget = (bmRequest & CY_USB_CTRL_REQ_RECIPENT_MASK);

    bool isReqHandled = false;

    if (reqType == CY_USB_CTRL_REQ_STD) {
        /* Microsoft OS String Descriptor request at index 0xEE */
        if ((bTarget == CY_USB_CTRL_REQ_RECIPENT_DEVICE) &&
            (bRequest == CY_USB_SC_GET_DESCRIPTOR) &&
            (wValue == ((CY_USB_STRING_DSCR << 8) | 0xEE))) {
            
            if (wLength > glOsString[0]) {
                wLength = glOsString[0];
            }
            Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsString, wLength);
            isReqHandled = true;
        }
    }
    else if (reqType == CY_USB_CTRL_REQ_VENDOR) {
        /* Microsoft OS Compatibility and Feature descriptor requests */
        if (bRequest == MS_VENDOR_CODE) {
            if (wIndex == 0x04) {
                if (wLength > *((uint16_t *)glOsCompatibilityId)) {
                    wLength = *((uint16_t *)glOsCompatibilityId);
                }
                Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsCompatibilityId, wLength);
                isReqHandled = true;
            } else if (wIndex == 0x05) {
                if (wLength > *((uint16_t *)glOsFeature)) {
                    wLength = *((uint16_t *)glOsFeature);
                }
                Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsFeature, wLength);
                isReqHandled = true;
            }
        }
        /* Custom Control Transfers: Start (0xA0) / Stop (0xA1) streaming commands */
        else if (bRequest == 0xA0) { /* REQ_START */
            streamingEnabled = true;
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            isReqHandled = true;
        }
        else if (bRequest == 0xA1) { /* REQ_STOP */
            streamingEnabled = false;
            Cy_USBD_SendAckSetupDataStatusStage(pUsbdCtxt);
            isReqHandled = true;
        }
    }

    if (!isReqHandled) {
        /* Stall EP0 for unhandled requests */
        Cy_USB_USBD_EndpSetClearStall(pUsbdCtxt, 0, CY_USB_ENDP_DIR_IN, true);
    }
}

/**
 * \name SetConfigCallback
 * \brief Invoked when device configuration has been selected.
 */
void SetConfigCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
{
    cy_stc_usb_setup_req_t *pSetupReq = (cy_stc_usb_setup_req_t *)(&(pMsg->data[0]));
    
    if (pSetupReq->wValue == 0) {
        /* Set Config 0: disconnect/unconfigure */
        usbConfigured = false;
        streamingEnabled = false;
        return;
    }

    /* Enable DW0 and DW1 blocks */
    Cy_DMA_Enable((DW_Type *)DW0_BASE);
    Cy_DMA_Enable((DW_Type *)DW1_BASE);

    /* Setup EP1 DMA and Interrupts */
    SetupEp1Dma();

    usbConfigured = true;
}

/**
 * \name BusResetCallback
 * \brief Invoked when USB bus reset is detected.
 */
void BusResetCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt, cy_stc_usb_cal_msg_t *pMsg)
{
    usbConfigured = false;
    streamingEnabled = false;
}

/**
 * \name USB_Init
 * \brief Performs the full initialization of the high-speed USB device stack.
 */
void USB_Init(void)
{
    cy_stc_sysint_t intrCfg;

    /* Do peripheral clock configuration */
    Cy_Fx2g3_InitPeripheralClocks(false, true);

    /* Register the ISR for USBHS active and enable the interrupt. */
    intrCfg.intrSrc      = usbhsdev_interrupt_u2d_active_o_IRQn;
    intrCfg.intrPriority = 4;
    Cy_SysInt_Init(&intrCfg, Cy_USB_HS_ISR);
    NVIC_EnableIRQ(intrCfg.intrSrc);

    /* Register ISR for USBHS deepsleep and enable the interrupt. */
    intrCfg.intrSrc      = usbhsdev_interrupt_u2d_dpslp_o_IRQn;
    intrCfg.intrPriority = 4;
    Cy_SysInt_Init(&intrCfg, Cy_USB_HS_ISR);
    NVIC_EnableIRQ(intrCfg.intrSrc);

    /* Setup SysTick for 1ms ticks */
    Cy_SysTick_SetClockSource(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU);
    Cy_SysTick_SetReload(Cy_SysClk_ClkFastGetFrequency() / 1000U);
    Cy_SysTick_Clear();
    Cy_SysTick_Enable();

    memset((void *)&usbdCtxt, 0, sizeof(cy_stc_usb_usbd_ctxt_t));
    memset((void *)&hsCalCtxt, 0, sizeof(cy_stc_usb_cal_ctxt_t));

    /* Store IP base address in CAL context. */
    hsCalCtxt.pCalBase = MXS40USBHSDEV_USBHSDEV;
    hsCalCtxt.pPhyBase = MXS40USBHSDEV_USBHSPHY;

    /* Initialize the HBW DMA IP and DMA Manager */
    Cy_HBDma_Init(LVDSSS_LVDS, USB32DEV, &HBW_DrvCtxt, 0, 0);
    Cy_HBDma_DscrList_Create(&HBW_DscrList, 32U);
    Cy_HBDma_BufMgr_Create(&HBW_BufMgr, (uint32_t *)0x1C030000UL, 0x10000UL); /* 64KB */
    Cy_HBDma_Mgr_Init(&HBW_MgrCtxt, &HBW_DrvCtxt, &HBW_DscrList, &HBW_BufMgr);
    Cy_HBDma_Mgr_RegisterUsbContext(&HBW_MgrCtxt, &usbdCtxt);

    /* Initialize the USBD layer */
    Cy_USB_USBD_Init(NULL, &usbdCtxt, ((DMAC_Type *)DMAC_BASE), &hsCalCtxt, NULL, &HBW_MgrCtxt);

    /* Enable stall cycles between back-to-back AHB accesses to high bandwidth RAM. */
    MAIN_REG->CTRL = (MAIN_REG->CTRL & 0xF00FFFFFUL) | 0x09900000UL;

    /* Register USB descriptors with the stack. */
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_DEVICE_DSCR, 0, (uint8_t *)CyFxUSB20DeviceDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_BOS_DSCR, 0, (uint8_t *)CyFxUSBBOSDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_DEVICE_QUAL_DSCR, 0, (uint8_t *)CyFxUSBDeviceQualDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_CONFIG_DSCR, 0, (uint8_t *)CyFxUSBHSConfigDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_FS_CONFIG_DSCR, 0, (uint8_t *)CyFxUSBFSConfigDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 0, (uint8_t *)CyFxUSBStringLangIDDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 1, (uint8_t *)CyFxUSBManufactureDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 2, (uint8_t *)CyFxUSBProductDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 3, (uint8_t *)CyFxUSBConfigDscrStr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 4, (uint8_t *)CyFxUSBIntfDscrStr);

    /* Register Callbacks */
    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_SETUP, SetupCallback);
    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_SET_CONFIG, SetConfigCallback);
    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_RESET, BusResetCallback);

    /* Enable USB 2.x connection (High Speed preferred) */
    Cy_USBD_ConnectDevice(&usbdCtxt, CY_USBD_USB_DEV_HS);
}

/**
 * \name USB_Stream_Write
 * \brief Places data into a free high bandwidth DMA buffer and commits it to the hardware FIFO.
 */
bool USB_Stream_Write(const uint8_t* data, uint32_t length)
{
    if (!usbConfigured) return false;

    /* One-shot log on the first transfer attempt after USB is configured. */
    static bool startLogged = false;
    if (!startLogged) {
        startLogged = true;
        DBG_APP_INFO("[USB] Streaming started. EP1 IN channel: type=%d state=%d\r\n",
                     (int)ep1InDmaChannel.type, (int)ep1InDmaChannel.state);
    }

    cy_stc_hbdma_buff_status_t buffStat;
    cy_en_hbdma_mgr_status_t stat = Cy_HBDma_Channel_GetBuffer(&ep1InDmaChannel, &buffStat);
    if (stat != CY_HBDMA_MGR_SUCCESS) {
        DBG_APP_INFO("[USB] GetBuffer FAIL 0x%x pCtx=%s type=%d state=%d\r\n",
                     (unsigned int)stat,
                     (ep1InDmaChannel.pContext != NULL) ? "OK" : "NULL",
                     (int)ep1InDmaChannel.type,
                     (int)ep1InDmaChannel.state);
        return false;
    }
    
    /* Copy data to DMA buffer, zero-pad to full size to send a full USB packet.
     * The host parser uses 0xAA 0xAA sync bytes to find frames, so padding is safe.
     * Sending full 512-byte packets avoids ambiguity in how the USBHS EPM tracks
     * the byte count for short packets. */
    uint32_t bytesToCopy = (length < buffStat.size) ? length : buffStat.size;
    memcpy((uint8_t*)buffStat.pBuffer, data, bytesToCopy);
    if (bytesToCopy < buffStat.size) {
        memset((uint8_t*)buffStat.pBuffer + bytesToCopy, 0, buffStat.size - bytesToCopy);
    }
    buffStat.count = buffStat.size;

    /* Reset the DataWire trigger flag before each commit. DW_QueueWrite only asserts
     * the SW trigger on the first call (egressDWTrigDone flag). On subsequent calls it
     * expects the USB hardware to re-trigger DW1 via USBHSDEV_TR_OUT16, but that trigger
     * fires while DW1 is disabled and is permanently lost. Clearing the flag forces the
     * SW trigger to be asserted on every commit, preventing the DW1 deadlock. */
    ep1InDmaChannel.egressDWTrigDone[0] = false;

    stat = Cy_HBDma_Channel_CommitBuffer(&ep1InDmaChannel, &buffStat);
    if (stat != CY_HBDMA_MGR_SUCCESS) {
        DBG_APP_INFO("[USB] CommitBuffer FAIL 0x%x pCtx=%s type=%d evEn=%d cnt=%u\r\n",
                     (unsigned int)stat,
                     (ep1InDmaChannel.pContext != NULL) ? "OK" : "NULL",
                     (int)ep1InDmaChannel.type,
                     (int)ep1InDmaChannel.eventEnable,
                     (unsigned)buffStat.count);
        return false;
    }

    return true;
}

/* [] END OF FILE */
