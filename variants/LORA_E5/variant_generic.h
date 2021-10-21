/*
 *******************************************************************************
 * Copyright (c) 2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/
// LoRa-E5 Dev Board
// First is begin at the top right of the board
// J7
#define PC0                     0  // LPUART1_RX
#define PC1                     1  // LPUART1_TX
#define PB7                     2  // USART1_RX
#define PB6                     3  // USART1_TX
#define PB4                     PIN_A0  // ENRS485
// J4
#define PB3                     PIN_A1
#define PB15                    6  // I2C2_SCL
#define PA15                    7  // I2C2_SDA
#define PA14                    8  // SWCLK
#define PA13                    9  // SWDIO
// J1
#define PA10                    10 // SPI2_MOSI
#define PB14                    11 // SPI2_MISO
#define PB9                     12 // SPI2_NSS
#define PB13                    13 // SPI2_SCK/BOOT
#define PA0                     14 // USER_BTN
#define PB5                     15 // LED_RED
// J2
#define PA9                     16 // EN3V3
#define PB10                    17 // EN5V
#define PA2                     18 // USART2_TX
#define PA3                     19 // USART2_RX


#define NUM_DIGITAL_PINS        20
#define NUM_ANALOG_INPUTS       2

//Enable RS485
#define ENRS485                 PB4

// On-board LED pin number
#define LED1                    PB5
#define LED_RED                 LED1
#ifndef LED_BUILTIN
  #define LED_BUILTIN           LED_RED
#endif

// On-board user button
#define B1_BTN                  PA0  
#define B2_BTN                  PB13 // PB13 (BOOT)
#ifndef USER_BTN
  #define USER_BTN              B1_BTN
#endif
#ifndef BOOT_BTN
  #define BOOT_BTN              B2_BTN
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#define ENABLE_HWSERIAL2
#define PIN_SERIAL2_TX          PA2
#define PIN_SERIAL2_RX          PA3

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM16
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM17
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  101
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PB7
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PB6
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PA15
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB15
#endif

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PB9
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PA10
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PB14
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PB13
#endif

#ifndef UART_WAKEUP_EXTI_LINE
  // For LPUART1
  #define UART_WAKEUP_EXTI_LINE LL_EXTI_LINE_28
#endif

// Extra HAL modules
#if !defined(HAL_DAC_MODULE_DISABLED)
  #define HAL_DAC_MODULE_ENABLED
#endif

#define HAL_ADC_MODULE_ENABLED

//
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
