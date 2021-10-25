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
#define LED_BUILTIN             LED_RED

// On-board user button
#define B1_BTN                  PA0  
#define B2_BTN                  PB13  // (BOOT)
#define USER_BTN                B1_BTN
#define BOOT_BTN                B2_BTN

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM16
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM17
#endif

// UART Definitions
#define SERIAL_UART_INSTANCE    1
#define ENABLE_HWSERIAL1
#define ENABLE_HWSERIAL2
// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#define PIN_SERIAL1_TX          PB6
#define PIN_SERIAL1_RX          PB7

#define PIN_SERIAL2_TX          PA2
#define PIN_SERIAL2_RX          PA3

// I2C definitions
#define PIN_WIRE_SDA            PA15
#define PIN_WIRE_SCL            PB15

// SPI definitions
#define PIN_SPI_SS              PB9
#define PIN_SPI_MOSI            PA10
#define PIN_SPI_MISO            PB14
#define PIN_SPI_SCK             PB13

// LPUART1
#ifndef UART_WAKEUP_EXTI_LINE
  // For LPUART1
  #define UART_WAKEUP_EXTI_LINE LL_EXTI_LINE_28
#endif
#define ENABLE_HWSERIALLP1
#define PIN_SERIALLP1_TX        PC1
#define PIN_SERIALLP1_RX        PC0

// Extra HAL modules
#define HAL_DAC_MODULE_ENABLED

#define HAL_ADC_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED

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
