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
#include "app_version.h"
#include "cybsp.h"

/* UART and SPI SCB instances */
#define UART_SCB            (SCB1)
#define SPI_SCB             (SCB4)

/* Test pattern definitions */
#define UART_TEST_PATTERN   "TEST_UART_DATA\r\n"
#define SPI_TEST_BYTE       0xAA

/* Test timing */
#define TEST_INTERVAL_MS    500

/**
* \brief Initialize UART peripheral (SCB1)
* Baud rate: 115200, 8-bit data, no parity, 1 stop bit
*/
void UART_Init(void)
{
   cy_stc_scb_uart_config_t uartConfig = {
       .uartMode = CY_SCB_UART_STANDARD,
       .oversample = 12,
       .dataWidth = 8,
       .stopBits = CY_SCB_UART_STOP_BITS_1,
       .parity = CY_SCB_UART_PARITY_NONE,
       .enableMsbFirst = false,
       .ackAddress = false,
       .ackAddressMask = 0,
       .dropOnFrameError = false,
       .dropOnParityError = false,
       .enableRxTimeout = false,
       .rxTimeout = 0
   };
    
   Cy_SCB_UART_Init(UART_SCB, &uartConfig, NULL);
   Cy_SCB_UART_Enable(UART_SCB);
}

/**
* \brief Initialize SPI peripheral (SCB4) as Master
* Clock: 1 MHz, Mode 0 (CPHA=0, CPOL=0)
*/
void SPI_Init(void)
{
   cy_stc_scb_spi_config_t spiConfig = {
       .spiMode = CY_SCB_SPI_MASTER,
       .subMode = CY_SCB_SPI_MOTOROLA,
       .sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
       .oversample = 15,
       .rxDataWidth = 8,
       .txDataWidth = 8,
       .enableMsbFirst = true,
       .enableFreeRunSclk = false,
       .enableInputFilter = false,
       .enableDuplex = true,
       .enableWakeup = false,
       .parity = CY_SCB_SPI_PARITY_NONE,
       .dropOnParityError = false,
       .waitOnSpiBusIdle = 0,
       .ssPolarity = 0x0F,
       .enableTransferSeperation = false,
       .enableTransferSkipping = false,
       .enableByteMode = false
   };
    
   Cy_SCB_SPI_Init(SPI_SCB, &spiConfig, NULL);
   Cy_SCB_SPI_Enable(SPI_SCB);
}

/**
* \brief Transmit data via UART
*/
void UART_SendData(const uint8_t *data, uint32_t length)
{
   for (uint32_t i = 0; i < length; i++) {
       Cy_SCB_UART_PutArrayBlocking(UART_SCB, (uint8_t*)&data[i], 1);
   }
}

/**
* \brief Transmit data via SPI
*/
void SPI_SendData(uint8_t data)
{
   while (Cy_SCB_SPI_GetTxFifoStatus(SPI_SCB) & CY_SCB_TX_FIFO_STATUS_NOT_FULL) {
       Cy_SCB_SPI_Write(SPI_SCB, data);
       break;
   }
    
   while (!(Cy_SCB_SPI_GetTxFifoStatus(SPI_SCB) & CY_SCB_TX_FIFO_STATUS_EMPTY)) {
       /* Wait for TX FIFO to empty */
   }
}

/**
* \brief Entry to the application
*/
int main(void)
{
   uint32_t loopCount = 0;
    
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
    
   /* Initialize UART and SPI peripherals */
   UART_Init();
   SPI_Init();
    
   /* Initial delay to allow peripherals to stabilize */
   Cy_SysLib_Delay(100);
    
   /* Send startup message via UART */
   const uint8_t startup_msg[] = "=== FX2G3 UART/SPI Test Started ===\r\n";
   UART_SendData(startup_msg, sizeof(startup_msg) - 1);
    
   Cy_SysLib_Delay(100);
    
   /* Main test loop */
   while (1) {
       /* Send UART test pattern */
       uint8_t uart_msg[] = "LOOP_";
       UART_SendData(uart_msg, sizeof(uart_msg) - 1);
        
       /* Send loop count via UART (convert to ASCII) */
       uint8_t count_str[10];
       int len = sprintf((char*)count_str, "%ld\r\n", loopCount);
       UART_SendData(count_str, len);
        
       /* Send SPI test pattern */
       SPI_SendData(SPI_TEST_BYTE);
       SPI_SendData((uint8_t)loopCount & 0xFF);
        
       /* Toggle LED to indicate test is running */
       Cy_GPIO_Inv(P4_3_PORT, P4_3_PIN);
        
       loopCount++;
       Cy_SysLib_Delay(TEST_INTERVAL_MS);
   }
    
   return 0;
}

/* [] END OF FILE */
