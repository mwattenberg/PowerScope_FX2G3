/***************************************************************************//**
* \file main.c
* \version 1.0
*
* \brief Main source file of the FX2G3 device - UART and SPI test application.
*
* Tests basic UART and SPI functionality by outputting test signals
* that can be verified with a logic analyzer.
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
#include <stdio.h>
#include "app_version.h"
#include "cybsp.h"

/* Test timing */
#define TEST_INTERVAL_MS    500

/**
* \brief Initialize UART (SCB1)
* Uses device configurator-generated config
*/
void UART_Init(void)
{
   extern const cy_stc_scb_uart_config_t UART_config;
    
   /* Using low-level API, pass NULL for context */
   Cy_SCB_UART_Init(UART_HW, &UART_config, NULL);
   Cy_SCB_UART_Enable(UART_HW);
}

/**
* \brief Initialize SPI (SCB4) as Master
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
    
   /* Initialize UART and SPI */
   UART_Init();
   SPI_Init();
}

/**
* \brief Entry to the application
*/
int main(void)
{
   uint32_t loopCount = 0;
    
   /* Initialize application */
   AppInit();
    
   /* Send startup message via UART */
   const uint8_t startup_msg[] = "=== FX2G3 UART/SPI Test Started ===\r\n";
   Cy_SCB_UART_PutArrayBlocking(UART_HW, (uint8_t*)startup_msg, sizeof(startup_msg) - 1);
    
   Cy_SysLib_Delay(100);
    
   /* Main test loop */
   while (1) {
       /* Send UART test pattern */
       uint8_t uart_msg[] = "LOOP_";
       Cy_SCB_UART_PutArrayBlocking(UART_HW, (uint8_t*)uart_msg, sizeof(uart_msg) - 1);
        
       /* Send loop count via UART (convert to ASCII) */
       uint8_t count_str[10];
       int len = sprintf((char*)count_str, "%ld\r\n", loopCount);
       Cy_SCB_UART_PutArrayBlocking(UART_HW, count_str, len);
        
       /* Send SPI test pattern - write bytes directly */
       Cy_SCB_SPI_Write(SPI_HW, 0xAA);
       Cy_SCB_SPI_Write(SPI_HW, (uint8_t)loopCount & 0xFF);
        
       /* Wait for SPI transmission to complete */
       while (Cy_SCB_SPI_IsBusBusy(SPI_HW)) {
           /* Wait for SPI to finish */
       }
        
       /* Toggle LED to indicate test is running */
       //Cy_GPIO_Inv(P4_3_PORT, P4_3_PIN);
        
       loopCount++;
       Cy_SysLib_Delay(TEST_INTERVAL_MS);
   }
    
   return 0;
}

/* [] END OF FILE */
