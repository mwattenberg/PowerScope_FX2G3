/***************************************************************************//**
* \file main.c
* \version 1.0
*
* \brief FX2G3 serial-to-USB relay — top-level wiring.
*
* Peripheral init (UART/SPI) lives here so pin and clock assignments from the
* device configurator are visible in one place. Relay logic is in
* serial_relay.c; USB transport is in usb_stream.c.
*
*******************************************************************************
* \copyright
* (c) (2026), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#include "cy_pdl.h"
#include "app_version.h"
#include "cybsp.h"
#include "cy_debug.h"
#include "cycfg_peripherals.h"
#include "serial_relay.h"
#include "usb_stream.h"

/* Debug logging via USBFS CDC */
#define DEBUG_LEVEL  (3u)
#define LOGBUF_SIZE  (1024u)
static uint8_t logBuff[LOGBUF_SIZE];
static cy_stc_debug_config_t dbgCfg = {
    .pBuffer   = logBuff,
    .traceLvl  = DEBUG_LEVEL,
    .bufSize   = LOGBUF_SIZE,
    .dbgIntfce = CY_DEBUG_INTFCE_USBFS_CDC,
    .printNow  = true
};

/* Reset hook — must run before scatter loading */
void Cy_OnResetUser(void)
{
    /* Enable clk_hf4 with IMO and bring up the LVDS2USB32SS IP. */
    SRSS->CLK_ROOT_SELECT[4] = SRSS_CLK_ROOT_SELECT_ENABLE_Msk;
    MAIN_REG->CTRL = (
        MAIN_REG_CTRL_IP_ENABLED_Msk |
        (1UL << MAIN_REG_CTRL_NUM_FAST_AHB_STALL_CYCLES_Pos) |
        (1UL << MAIN_REG_CTRL_NUM_SLOW_AHB_STALL_CYCLES_Pos) |
        (3UL << MAIN_REG_CTRL_DMA_SRC_SEL_Pos));
}

static void AppInit(void)
{
    Cy_PDL_Init(&cy_deviceIpBlockCfgFX3G2);
    cybsp_init();

    Cy_WDT_Unlock();
    Cy_WDT_Disable();

#if (CY_CPU_CORTEX_M4)
    __set_BASEPRI(0);
#endif
    __enable_irq();
    Cy_SysLib_Delay(100);

    /* UART init — pins and clock configured in device configurator */
    extern const cy_stc_scb_uart_config_t UART_config;
    Cy_SCB_UART_Init(UART_HW, &UART_config, NULL);
    Cy_SCB_UART_Enable(UART_HW);
    Cy_Debug_LogInit(&dbgCfg);

    /* SPI init — configured but not enabled; host selects interface at runtime */
    extern const cy_stc_scb_spi_config_t SPI_config;
    Cy_SCB_SPI_Init(SPI_HW, &SPI_config, NULL);

    /* Register relay vendor callback, then start USB */
    SerialRelay_Init();
    USB_Stream_Init();
}

int main(void)
{
    AppInit();
    DBG_APP_INFO("=== FX2G3 Serial Relay Started v%u.%u.%u ===\r\n",
                 APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH);

    for (;;)
    {
        SerialRelay_Run();
    }
}
