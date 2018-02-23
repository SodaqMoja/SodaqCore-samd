/*
  Copyright (c) 2017 SODAQ.  All right reserved.

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

#ifndef _VARIANT_SODAQ_SARA_
#define _VARIANT_SODAQ_SARA_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

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
#define PINS_COUNT           (51u)
#define NUM_DIGITAL_PINS     (30u)
#define NUM_ANALOG_INPUTS    (10u)
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

// Digital Pins
#define PIN_ACCEL_INT1       (19u)
#define PIN_ACCEL_INT2       (20u)
#define PIN_MAG_INT          (21u)
#define PIN_USB_DETECT       (22u)
#define PIN_SARA_STATUS      (23u)
#define PIN_CHARGER_STATUS   (24u)
#define PIN_GPS_TIMEPULSE    (25u)

#define PIN_GPS_ENABLE       (26u)
#define PIN_SARA_ENABLE      (27u)
#define PIN_SARA_RESET       (28u)
#define PIN_SARA_TX_ENABLE   (29u)
#define PIN_SARA_R4XX_TOGGLE (52u)

static const uint8_t ACCEL_INT1 = PIN_ACCEL_INT1;
static const uint8_t ACCEL_INT2 = PIN_ACCEL_INT2;
static const uint8_t MAG_INT = PIN_MAG_INT;
static const uint8_t USB_DETECT = PIN_USB_DETECT;
static const uint8_t SARA_STATUS = PIN_SARA_STATUS;
static const uint8_t CHARGER_STATUS = PIN_CHARGER_STATUS;
static const uint8_t GPS_TIMEPULSE = PIN_GPS_TIMEPULSE;

static const uint8_t GPS_ENABLE = PIN_GPS_ENABLE;
static const uint8_t SARA_ENABLE = PIN_SARA_ENABLE;
static const uint8_t SARA_RESET = PIN_SARA_RESET;
static const uint8_t SARA_TX_ENABLE = PIN_SARA_TX_ENABLE;
static const uint8_t SARA_R4XX_TOGGLE = PIN_SARA_R4XX_TOGGLE;


// LEDs
#define PIN_LED_13          (13u)
#define PIN_LED             PIN_LED_13
#define LED_BUILTIN         PIN_LED_13

#define LED_RED             (16u)
#define LED_GREEN           (17u)
#define LED_BLUE            (18u)

/*
 * Analog pins
 */
#define PIN_A0               (31u)
#define PIN_A1               (PIN_A0 + 1)
#define PIN_A2               (PIN_A0 + 2)
#define PIN_A3               (PIN_A0 + 3)
#define PIN_A4               (PIN_A0 + 4)
#define PIN_A5               (PIN_A0 + 5)
#define PIN_A6               (PIN_A0 + 6)
#define PIN_A7               (PIN_A0 + 7)
#define PIN_A8               (PIN_A0 + 8)
#define PIN_A9               (PIN_A0 + 9)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;
static const uint8_t A8  = PIN_A8 ;
static const uint8_t A9  = PIN_A9 ;

static const uint8_t BAT_VOLT = PIN_A8;

#define ADC_RESOLUTION      12

static const uint8_t DAC0 = (51u) ; // implications for cores/arduino/wiring_analog.c analogWrite()


/*
 * Serial interfaces
 */
// Serial
#define PIN_SERIAL_RX       (0ul)
#define PIN_SERIAL_TX       (1ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_0)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_1)

// Serial1
#define PIN_SERIAL1_RX       (42ul)
#define PIN_SERIAL1_TX       (41ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_1)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

// SPI
#define PIN_SPI_MISO         (45u)
#define PIN_SPI_SS           (46u)
#define PIN_SPI_MOSI         (47u)
#define PIN_SPI_SCK          (48u)
#define PERIPH_SPI           sercom3
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SS   = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (43u)
#define PIN_WIRE_SCL         (44u)

#define PIN_WIRE1_SDA         (53u)
#define PIN_WIRE1_SCL         (54u)


/*
 * USB
 */
#define PIN_USB_DM          (49ul)
#define PIN_USB_DP          (50ul)

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

#define PERIPH_WIRE          sercom1
#define WIRE_IT_HANDLER      SERCOM1_Handler

#define PERIPH_WIRE1          sercom2
#define WIRE1_IT_HANDLER      SERCOM2_Handler

#endif /* _VARIANT_SODAQ_SARA_ */
