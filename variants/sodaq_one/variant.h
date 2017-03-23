/*
  Copyright (c) 2016 SODAQ.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_SODAQ_ONE_
#define _VARIANT_SODAQ_ONE_

// The definitions here needs a SAMD core >=1.6.3
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10603

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC       (32768ul)

/** Master clock frequency */
#define VARIANT_MCK           (48000000ul)

/** Copied from bootloader. It will cause a "stay in bootloader" when doing 1200bps-touch */
#define BOOT_DOUBLE_TAP_ADDRESS         (0x20007FFCul)
#define BOOT_DOUBLE_TAP_DATA            (*((volatile uint32_t *) BOOT_DOUBLE_TAP_ADDRESS))
#define DOUBLE_TAP_MAGIC                0x07738135

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (50u)
#define NUM_DIGITAL_PINS     (12u)	// Without the "other" Digital Pins
#define NUM_ANALOG_INPUTS    (12u)	// Without the "other" Analog Pins
#define NUM_ANALOG_OUTPUTS   (1u)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( g_APinDescription[P].ulExtInt )

// LEDs
#define PIN_LED_RED          (14u)
#define PIN_LED_GREEN        (15u)
#define PIN_LED_BLUE         (16u)

//LORA
#define LORA_RESET           (49u)

/*
 * Analog pins
 */
#define PIN_A0               (22u)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A6               (PIN_A0 + 4)
#define PIN_A7               (PIN_A0 + 5)
#define PIN_A8               (PIN_A0 + 6)
#define PIN_A9               (PIN_A0 + 7)
#define PIN_A10              (PIN_A0 + 8)
#define PIN_A11              (PIN_A0 + 9)
#define PIN_A12              (PIN_A0 + 10)
#define PIN_A13              (PIN_A0 + 11)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;
static const uint8_t A8  = PIN_A8 ;
static const uint8_t A9  = PIN_A9 ;
static const uint8_t A10 = PIN_A10;
static const uint8_t A11 = PIN_A11;
static const uint8_t A12 = PIN_A12;
static const uint8_t A13 = PIN_A13;
#define ADC_RESOLUTION      12

/*
 * Serial interfaces
 */
// Serial
#define PIN_SERIAL_RX       (39u)
#define PIN_SERIAL_TX       (40u)
#define PAD_SERIAL_TX       (UART_TX_PAD_0)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_1)

// Serial1
#define PIN_SERIAL1_RX      (41u)
#define PIN_SERIAL1_TX      (42u)
#define PAD_SERIAL1_TX      (UART_TX_PAD_0)
#define PAD_SERIAL1_RX      (SERCOM_RX_PAD_1)

// Other Digital Pins
static const uint8_t LED_RED       = PIN_LED_RED;
static const uint8_t LED_GREEN     = PIN_LED_GREEN;
static const uint8_t LED_BLUE      = PIN_LED_BLUE;
static const uint8_t GPS_TIMEPULSE = (17u);
static const uint8_t GPS_ENABLE    = (18u);
static const uint8_t BUTTON        = (19u);
static const uint8_t ACCEL_INT1    = (4u);
static const uint8_t ACCEL_INT2    = (5u);
static const uint8_t ENABLE_PIN_IO = (20u);
static const uint8_t SWITCH_SENSE  = (21u);

// Other Analog Pins
static const uint8_t DAC0          = PIN_A0; // or (24u) implications for cores/arduino/wiring_analog.c analogWrite()
static const uint8_t AREF          = (35u);
static const uint8_t BAT_VOLT      = (36u);

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (43u)
#define PIN_SPI_SS           (44u)
#define PIN_SPI_MOSI         (45u)
#define PIN_SPI_SCK          (46u)
#define PERIPH_SPI           sercom0
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SS   = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (47u)
#define PIN_WIRE_SCL         (48u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

/*
 * USB
 */
#define PIN_USB_DM          (38ul)
#define PIN_USB_DP          (39ul)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*  =========================
 *  ===== SERCOM DEFINITION
 *  =========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;

#endif

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
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB

// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1

#endif /* _VARIANT_SODAQ_ONE_ */
