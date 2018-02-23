/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  Autonomo pin    |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions for SODAQ NarrowBand
 *
 *  0..15 digital
 * 16..31 analog, A0..A15
 */
const PinDescription g_APinDescription[]=
{ 
  /*
  | PORT | PIN | PIN_TYPE    | PIN_ATTRIBUTES                                    | ADC_CHANNEL   | PWM_CHANNEL | TIMER_CHANNEL | EXT. INTERRUPT |
  */

  // 0..1 - SERCOM/UART (Serial)
  { PORTB, 31, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15  }, // RX, SERCOM5/PAD[1], D0
  { PORTB, 30, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14  }, // TX, SERCOM5/PAD[0], D1

  // 2..15 Digital
  { PORTA, 2,  PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, // D2
  { PORTA, 19, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3   }, // D3
  { PORTB, 4,  PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4   }, // D4
  { PORTB, 6,  PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6   }, // D5
  { PORTB, 7,  PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7   }, // D6
  { PORTB, 8,  PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8   }, // D7
  { PORTB, 10, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_10  }, // TC5[0], D8
  { PORTB, 11, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11  }, // D9
  { PORTA, 23, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_7   }, // TC4[1], D10
  { PORTA, 20, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM7_CH0,   TC7_CH0,      EXTERNAL_INT_4   }, // TC7[0], D11
  { PORTA, 22, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_6   }, // TC4[0], D12
  { PORTA, 21, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM7_CH1,   TC7_CH1,      EXTERNAL_INT_5   }, // TC7[1], D13 LED_BUILTIN
  { PORTA, 10, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM1_CH0,   TCC1_CH0,     EXTERNAL_INT_10  }, // GROVE1, D14, TCC1[0]
  { PORTA, 11, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM1_CH1,   TCC1_CH1,     EXTERNAL_INT_11  }, // GROVE2, D15, TCC1[1]

  // 16..18 RGB LED
  { PORTA, 12, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM2_CH0,   TCC2_CH0,     EXTERNAL_INT_NONE}, // LED_RED, D16, TCC2[0]
  { PORTB, 15, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_NONE}, // LED_GREEN, D17, TC5[1]
  { PORTA, 13, PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER),     No_ADC_Channel, PWM2_CH1,   TCC2_CH1,     EXTERNAL_INT_NONE}, // LED_BLUE, D18, TCC2[1]

  // 19..25 On-board Peripheral Inputs
  { PORTA, 14, PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14  }, // ACC_INT1, D19
  { PORTA, 15, PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15  }, // ACC_INT2, D20
  { PORTA, 18, PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, // MAG_INT, D21
  { PORTB, 16, PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0   }, // USB_DETECT, D22
  { PORTB, 22, PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6   }, // SARA_STATUS, D23
  { PORTA, 4,  PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4   }, // CHG_STAT, D24
  { PORTA, 7,  PIO_INPUT,       PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7   }, // GPS_TIMEPULSE, D25

  // 26..30 On-board Peripheral Outputs
  { PORTA, 28, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // GPS_ENABLE, D26
  { PORTA, 27, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // SARA_ENABLE, D27
  { PORTB, 14, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // SARA_RESET, D28
  { PORTB, 13, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // SARA_TX_ENABLE, D29
  { PORTB, 12, PIO_OUTPUT,      PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // D30

  // 31..36 A0..A5
  { PORTB,  0, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel8,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0   }, // ADC/AIN[8], A0
  { PORTB,  1, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel9,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1   }, // ADC/AIN[9], A1
  { PORTB,  2, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel10,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, // ADC/AIN[0], A2
  { PORTB,  3, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel11,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3   }, // ADC/AIN[1], A3
  { PORTA,  8, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel16,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI }, // ADC/AIN[2], A4
  { PORTA,  9, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel17,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9   }, // ADC/AIN[3], A5
  
  // 37..40 Other Analog Inputs
  { PORTA, 10, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel18,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10  }, // ADC/AIN[18], A6 Grove1
  { PORTA, 11, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel19,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11  }, // ADC/AIN[19], A7 Grove2
  { PORTB,  5, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel13,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5   }, // BAT_VOLT, A8
  { PORTB,  9, PIO_ANALOG,     PIN_ATTR_ANALOG,                                        ADC_Channel3,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9   }, // A9

  // 41..42 - SERCOM/UART (Serial1)
  { PORTA, 6, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL,                                       No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5   }, // TX: SERCOM0/PAD[2]
  { PORTA, 5, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL,                                       No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6   }, // RX: SERCOM0/PAD[1]

  // 43..44 - I2C pins (SDA/SCL)
  { PORTA, 16, PIO_SERCOM,     PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_0   }, // SDA: SERCOM1/PAD[0]
  { PORTA, 17, PIO_SERCOM,     PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1   }, // SCL: SERCOM1/PAD[1]

  // 45..48 - SPI pins (ICSP: MISO, SS, MOSI, SCK)
  // Notice that SCK is sharing the same PA21 with LED_BUILTIN
  { PORTA, 22, PIO_SERCOM,     PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6   }, // MISO: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM,     PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7   }, // SS: SERCOM3/PAD[1]
  { PORTA, 20, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4   }, // MOSI: SERCOM3/PAD[2]
  { PORTA, 21, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5   }, // SCK: SERCOM3/PAD[3]

  // 49..50 - USB
  { PORTA, 24, PIO_COM,        PIN_ATTR_NONE,                                         No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DM
  { PORTA, 25, PIO_COM,        PIN_ATTR_NONE,                                         No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, // USB/DP

  // 51..52 - DAC, SARA_R4XX_TOGGLE 
  { PORTA,  2, PIO_ANALOG,     PIN_ATTR_ANALOG,                                       DAC_Channel0,    NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, // DAC
  { PORTB, 17, PIO_OUTPUT,     PIN_ATTR_DIGITAL,                                      No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},  // SARA_R4XX_TOGGLE
  
  // 53..54 - I2C1 pins (SDA/SCL)
  { PORTA, 8,  PIO_SERCOM_ALT, PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI }, // SDA: SERCOM2/PAD[0]
  { PORTA, 9,  PIO_SERCOM_ALT, PIN_ATTR_DIGITAL,                                      No_ADC_Channel,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9   }, // SCL: SERCOM2/PAD[1]
};

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5, TC6, TC7 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ; // Serial1
SERCOM sercom1( SERCOM1 ) ; // I2C
SERCOM sercom2( SERCOM2 ) ; // I2C1
SERCOM sercom3( SERCOM3 ) ; // SPI
SERCOM sercom4( SERCOM4 ) ; // -
SERCOM sercom5( SERCOM5 ) ; // Serial


Uart Serial( &sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
void SERCOM5_Handler()
{
  Serial.IrqHandler();
}

Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX );
void SERCOM0_Handler()
{
  Serial1.IrqHandler();
}
