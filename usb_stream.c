/*******************************************************************************
 * usb_stream.c
 *
 * USB high-speed bulk streaming layer for FX2G3.
 * Extracted from main.c — owns all USB stack and HBDMA logic.
 ******************************************************************************/

#include "usb_stream.h"
#include <string.h>
#include "cy_pdl.h"
#include "cy_debug.h"
#include "cy_usb_common.h"
#include "cy_usb_usbd.h"
#include "cy_usbhs_cal_drv.h"
#include "cy_hbdma.h"
#include "cy_hbdma_mgr.h"
#include "usb_descriptors.h"

/* High Bandwidth DMA contexts */
static cy_stc_hbdma_context_t     HBW_DrvCtxt;
static cy_stc_hbdma_dscr_list_t   HBW_DscrList;
static cy_stc_hbdma_buf_mgr_t     HBW_BufMgr;
static cy_stc_hbdma_mgr_context_t HBW_MgrCtxt;

static cy_stc_usb_usbd_ctxt_t  usbdCtxt;
static cy_stc_usb_cal_ctxt_t   hsCalCtxt;
static cy_stc_hbdma_channel_t  ep1InDmaChannel;

volatile bool usbConfigured = false;

static USB_VendorCmdCallback_t vendorCmdCallback = NULL;

void USB_Stream_RegisterVendorCallback(USB_VendorCmdCallback_t cb)
{
    vendorCmdCallback = cb;
}

/*******************************************************************************
 * Internal helpers
 ******************************************************************************/

static void Cy_Fx2g3_InitPeripheralClocks(bool adcClkEnable, bool usbfsClkEnable)
{
    if (adcClkEnable) {
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1, 74);
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1);
        Cy_SysLib_DelayUs(10U);
        Cy_SysClk_PeriphAssignDivider(PCLK_LVDS2USB32SS_CLOCK_SAR, CY_SYSCLK_DIV_16_BIT, 1);
    }

    if (usbfsClkEnable) {
        /* Target 100 kHz BRS clock: divider = PCLK/100000 - 1 */
        uint32_t brsDivider = (Cy_SysClk_ClkPeriGetFrequency() / 100000U) - 1U;
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2, brsDivider);
        Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2);
        Cy_SysLib_DelayUs(10U);
        Cy_SysClk_PeriphAssignDivider(PCLK_USB_CLOCK_DEV_BRS, CY_SYSCLK_DIV_16_BIT, 2);
    }
}

static void HbDma_Callback(cy_stc_hbdma_channel_t *handle, cy_en_hbdma_cb_type_t type,
                            cy_stc_hbdma_buff_status_t *pbufStat, void *userCtx)
{
    (void)handle; (void)type; (void)pbufStat; (void)userCtx;
}

static void InEpDma_ISR(uint8_t endpNum)
{
    (void)endpNum;
    Cy_HBDma_Mgr_HandleDW1Interrupt(&HBW_MgrCtxt);
}

static void SetupEp1Dma(void)
{
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

    uint16_t maxPktSize = (Cy_USBD_GetDeviceSpeed(&usbdCtxt) == CY_USBD_USB_DEV_HS) ? 512 : 64;
    DBG_APP_INFO("[SetupEp1Dma] USB Device Speed: %d, maxPktSize: %u\r\n",
                 (int)Cy_USBD_GetDeviceSpeed(&usbdCtxt), (unsigned int)maxPktSize);

    cy_stc_usb_endp_config_t endpConfig = {
        .endpType          = CY_USB_ENDP_TYPE_BULK,
        .endpDirection     = CY_USB_ENDP_DIR_IN,
        .valid             = true,
        .endpNumber        = 1,
        .maxPktSize        = maxPktSize,
        .isoPkts           = 0,
        .burstSize         = 0,
        .streamID          = 0,
        .interval          = 0,
        .allowNakTillDmaRdy = true,
    };
    Cy_USB_USBD_EndpConfig(&usbdCtxt, endpConfig);
    Cy_USBD_ResetEndp(&usbdCtxt, 1, CY_USB_ENDP_DIR_IN, false);
    Cy_SysLib_Delay(1);

    cy_stc_hbdma_chn_config_t dmaConfig;
    memset(&dmaConfig, 0, sizeof(dmaConfig));
    dmaConfig.size          = maxPktSize;
    dmaConfig.prodBufSize   = maxPktSize;
    dmaConfig.count         = 4;
    dmaConfig.prodHdrSize   = 0;
    dmaConfig.eventEnable   = 0;
    dmaConfig.intrEnable    = LVDSSS_LVDS_ADAPTER_DMA_SCK_INTR_CONSUME_EVENT_Msk;
    dmaConfig.bufferMode    = false;
    dmaConfig.chType        = CY_HBDMA_TYPE_MEM_TO_IP;
    dmaConfig.prodSckCount  = 1;
    dmaConfig.prodSck[0]    = CY_HBDMA_VIRT_SOCKET_WR;
    dmaConfig.consSckCount  = 1;
    dmaConfig.consSck[0]    = (cy_hbdma_socket_id_t)(CY_HBDMA_USBHS_IN_EP_00 + 1);
    dmaConfig.usbMaxPktSize = maxPktSize;
    dmaConfig.cb            = HbDma_Callback;
    dmaConfig.userCtx       = NULL;

    cy_en_hbdma_mgr_status_t create_status =
        Cy_HBDma_Channel_Create(&HBW_MgrCtxt, &ep1InDmaChannel, &dmaConfig);
    DBG_APP_INFO("[SetupEp1Dma] Channel_Create: 0x%x state: %d\r\n",
                 (unsigned int)create_status, (int)ep1InDmaChannel.state);

    cy_stc_sysint_t intrCfg = {
        .intrPriority = 5,
        .intrSrc      = (IRQn_Type)(cpuss_interrupts_dw1_0_IRQn + 1),
    };
    Cy_SysInt_Init(&intrCfg, Ep1InDma_ISR);
    NVIC_ClearPendingIRQ(intrCfg.intrSrc);
    NVIC_EnableIRQ(intrCfg.intrSrc);

    cy_en_hbdma_mgr_status_t en_status = Cy_HBDma_Channel_Enable(&ep1InDmaChannel, 0);
    DBG_APP_INFO("[SetupEp1Dma] Channel_Enable: 0x%x\r\n", (unsigned int)en_status);
}

/*******************************************************************************
 * USB stack callbacks
 ******************************************************************************/

static void SetupCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                          cy_stc_usb_cal_msg_t *pMsg)
{
    (void)pAppCtxt;

    uint32_t setupData0 = pMsg->data[0];
    uint32_t setupData1 = pMsg->data[1];

    uint8_t  bmRequest = (uint8_t)((setupData0 & CY_USB_BMREQUEST_SETUP0_MASK) >> CY_USB_BMREQUEST_SETUP0_POS);
    uint8_t  bRequest  = (uint8_t)((setupData0 & CY_USB_BREQUEST_SETUP0_MASK)  >> CY_USB_BREQUEST_SETUP0_POS);
    uint16_t wValue    = (uint16_t)((setupData0 & CY_USB_WVALUE_SETUP0_MASK)   >> CY_USB_WVALUE_SETUP0_POS);
    uint16_t wIndex    = (uint16_t)((setupData1 & CY_USB_WINDEX_SETUP1_MASK)   >> CY_USB_WINDEX_SETUP1_POS);
    uint16_t wLength   = (uint16_t)((setupData1 & CY_USB_WLENGTH_SETUP1_MASK)  >> CY_USB_WLENGTH_SETUP1_POS);

    uint8_t reqType = ((bmRequest & CY_USB_CTRL_REQ_TYPE_MASK) >> CY_USB_CTRL_REQ_TYPE_POS);
    uint8_t bTarget = (bmRequest & CY_USB_CTRL_REQ_RECIPENT_MASK);

    bool isReqHandled = false;

    if (reqType == CY_USB_CTRL_REQ_STD) {
        /* Microsoft OS String Descriptor at index 0xEE */
        if ((bTarget == CY_USB_CTRL_REQ_RECIPENT_DEVICE) &&
            (bRequest == CY_USB_SC_GET_DESCRIPTOR) &&
            (wValue == ((CY_USB_STRING_DSCR << 8) | 0xEE))) {
            if (wLength > glOsString[0]) wLength = glOsString[0];
            Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsString, wLength);
            isReqHandled = true;
        }
    } else if (reqType == CY_USB_CTRL_REQ_VENDOR) {
        /* WinUSB compatibility / feature descriptors */
        if (bRequest == MS_VENDOR_CODE) {
            if (wIndex == 0x04) {
                if (wLength > *((uint16_t *)glOsCompatibilityId))
                    wLength = *((uint16_t *)glOsCompatibilityId);
                Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsCompatibilityId, wLength);
                isReqHandled = true;
            } else if (wIndex == 0x05) {
                if (wLength > *((uint16_t *)glOsFeature))
                    wLength = *((uint16_t *)glOsFeature);
                Cy_USB_USBD_SendEndp0Data(pUsbdCtxt, (uint8_t *)glOsFeature, wLength);
                isReqHandled = true;
            }
        }
        /* Dispatch all other vendor requests to the application callback */
        else if (vendorCmdCallback != NULL) {
            vendorCmdCallback(pUsbdCtxt, bRequest, wValue, wIndex, wLength);
            isReqHandled = true;
        }
    }

    if (!isReqHandled) {
        Cy_USB_USBD_EndpSetClearStall(pUsbdCtxt, 0, CY_USB_ENDP_DIR_IN, true);
    }
}

static void SetConfigCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                               cy_stc_usb_cal_msg_t *pMsg)
{
    (void)pAppCtxt; (void)pUsbdCtxt;

    cy_stc_usb_setup_req_t *pSetupReq = (cy_stc_usb_setup_req_t *)(&(pMsg->data[0]));
    if (pSetupReq->wValue == 0) {
        usbConfigured = false;
        return;
    }

    Cy_DMA_Enable((DW_Type *)DW0_BASE);
    Cy_DMA_Enable((DW_Type *)DW1_BASE);
    SetupEp1Dma();
    usbConfigured = true;
}

static void BusResetCallback(void *pAppCtxt, cy_stc_usb_usbd_ctxt_t *pUsbdCtxt,
                              cy_stc_usb_cal_msg_t *pMsg)
{
    (void)pAppCtxt; (void)pUsbdCtxt; (void)pMsg;
    usbConfigured = false;
}

/*******************************************************************************
 * ISRs — must have C linkage so the vector table resolves them correctly
 ******************************************************************************/

void Cy_USB_HS_ISR(void)
{
    Cy_USBHS_Cal_IntrHandler(&hsCalCtxt);
}

void SysTick_Handler(void)
{
    Cy_USBD_TickIncrement(&usbdCtxt);
}

void InEpDma_ISR_top(uint8_t endpNum)
{
    InEpDma_ISR(endpNum);
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

void USB_Stream_Init(void)
{
    Cy_Fx2g3_InitPeripheralClocks(false, true);

    cy_stc_sysint_t intrCfg;
    intrCfg.intrSrc      = usbhsdev_interrupt_u2d_active_o_IRQn;
    intrCfg.intrPriority = 4;
    Cy_SysInt_Init(&intrCfg, Cy_USB_HS_ISR);
    NVIC_EnableIRQ(intrCfg.intrSrc);

    intrCfg.intrSrc      = usbhsdev_interrupt_u2d_dpslp_o_IRQn;
    intrCfg.intrPriority = 4;
    Cy_SysInt_Init(&intrCfg, Cy_USB_HS_ISR);
    NVIC_EnableIRQ(intrCfg.intrSrc);

    Cy_SysTick_SetClockSource(CY_SYSTICK_CLOCK_SOURCE_CLK_CPU);
    Cy_SysTick_SetReload(Cy_SysClk_ClkFastGetFrequency() / 1000U);
    Cy_SysTick_Clear();
    Cy_SysTick_Enable();

    memset((void *)&usbdCtxt, 0, sizeof(usbdCtxt));
    memset((void *)&hsCalCtxt, 0, sizeof(hsCalCtxt));

    hsCalCtxt.pCalBase = MXS40USBHSDEV_USBHSDEV;
    hsCalCtxt.pPhyBase = MXS40USBHSDEV_USBHSPHY;

    Cy_HBDma_Init(LVDSSS_LVDS, USB32DEV, &HBW_DrvCtxt, 0, 0);
    Cy_HBDma_DscrList_Create(&HBW_DscrList, 32U);
    Cy_HBDma_BufMgr_Create(&HBW_BufMgr, (uint32_t *)0x1C030000UL, 0x10000UL);
    Cy_HBDma_Mgr_Init(&HBW_MgrCtxt, &HBW_DrvCtxt, &HBW_DscrList, &HBW_BufMgr);
    Cy_HBDma_Mgr_RegisterUsbContext(&HBW_MgrCtxt, &usbdCtxt);

    Cy_USB_USBD_Init(NULL, &usbdCtxt, ((DMAC_Type *)DMAC_BASE), &hsCalCtxt, NULL, &HBW_MgrCtxt);
    MAIN_REG->CTRL = (MAIN_REG->CTRL & 0xF00FFFFFUL) | 0x09900000UL;

    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_DEVICE_DSCR,   0, (uint8_t *)CyFxUSB20DeviceDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_BOS_DSCR,      0, (uint8_t *)CyFxUSBBOSDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_DEVICE_QUAL_DSCR, 0, (uint8_t *)CyFxUSBDeviceQualDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_HS_CONFIG_DSCR,   0, (uint8_t *)CyFxUSBHSConfigDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_FS_CONFIG_DSCR,   0, (uint8_t *)CyFxUSBFSConfigDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 0, (uint8_t *)CyFxUSBStringLangIDDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 1, (uint8_t *)CyFxUSBManufactureDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 2, (uint8_t *)CyFxUSBProductDscr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 3, (uint8_t *)CyFxUSBConfigDscrStr);
    Cy_USBD_SetDscr(&usbdCtxt, CY_USB_SET_STRING_DSCR, 4, (uint8_t *)CyFxUSBIntfDscrStr);

    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_SETUP,      SetupCallback);
    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_SET_CONFIG,  SetConfigCallback);
    Cy_USBD_RegisterCallback(&usbdCtxt, CY_USB_USBD_CB_RESET,       BusResetCallback);

    Cy_USBD_ConnectDevice(&usbdCtxt, CY_USBD_USB_DEV_HS);
}

bool USB_Stream_Write(const uint8_t *data, uint32_t length)
{
    if (!usbConfigured) return false;

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

    uint32_t bytesToCopy = (length < buffStat.size) ? length : buffStat.size;
    memcpy((uint8_t *)buffStat.pBuffer, data, bytesToCopy);
    buffStat.count = bytesToCopy;

    /* Force SW trigger on every commit to avoid DW1 deadlock after first transfer. */
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
