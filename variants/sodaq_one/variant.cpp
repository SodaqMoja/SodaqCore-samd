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

#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // 0..13 Main IO Pins Digital Properties
  { PORTA, 2,  PIO_DIGITAL,    (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTA, 3,  PIO_DIGITAL,    (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },
  { PORTB, 8,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_8    }, // TC4/WO[0]
  { PORTB, 9,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_9    }, // TC4/WO[1]
  { PORTA, 4,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH0,   TCC0_CH0,     EXTERNAL_INT_4    }, // TCC0/WO[0]
  { PORTA, 5,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH1,   TCC0_CH1,     EXTERNAL_INT_5    }, // TCC0/WO[1]
  { PORTA, 6,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH0,   TCC1_CH0,     EXTERNAL_INT_6    }, // TCC1/WO[0]
  { PORTA, 7,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM1_CH1,   TCC1_CH1,     EXTERNAL_INT_7    }, // TCC1/WO[1]
  { PORTA, 8,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH0,   TCC0_CH0,     EXTERNAL_INT_NMI  },
  { PORTA, 9,  PIO_TIMER,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH1,   TCC0_CH1,     EXTERNAL_INT_9    }, 
  { PORTA, 10, PIO_TIMER_ALT,  (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH2,   TCC0_CH2,     EXTERNAL_INT_10   }, // TCC0/WO[2]
  { PORTA, 11, PIO_TIMER_ALT,  (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM0_CH3,   TCC0_CH3,     EXTERNAL_INT_11   }, // TCC0/WO[3]
  { PORTB, 2,  PIO_DIGITAL,    (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTB, 3,  PIO_DIGITAL,    (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },

  // 14..23 Other Digital Pins
  { PORTA, 15, PIO_INPUT,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM3_CH1,   TC3_CH1,      EXTERNAL_INT_NONE }, // LED_RED
  { PORTB, 10, PIO_INPUT,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_NONE }, // LED_GREEN
  { PORTB, 11, PIO_INPUT,      (PIN_ATTR_DIGITAL | PIN_ATTR_PWM | PIN_ATTR_TIMER), No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_NONE }, // LED_BLUE
  { PORTA, 14, PIO_INPUT,      (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_14   }, // GPS_TIMEPULSE
  { PORTA, 18, PIO_OUTPUT,     (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // GPS_ENABLE
  { PORTA, 19, PIO_INPUT,      (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    }, // BUTTON
  { PORTA, 21, PIO_INPUT,      (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4    }, // ACCEL_INT1
  { PORTA, 20, PIO_INPUT,      (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5    }, // ACCEL_INT2
  { PORTB, 22, PIO_OUTPUT,     (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // ENABLE_PIN_IO
  { PORTA, 28, PIO_INPUT,      (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8    }, // SWITCH_SENSE

  // 24..37 Main IO Pins Analog Properties
  { PORTA, 2,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTA, 3,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel1,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },
  { PORTB, 8,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel2,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8    },
  { PORTB, 9,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel3,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9    },
  { PORTA, 4,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel4,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4    },
  { PORTA, 5,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel5,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5    },
  { PORTA, 6,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel6,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6    },
  { PORTA, 7,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel7,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7    },
  { PORTA, 8,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel16,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI  },
  { PORTA, 9,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel17,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9    },
  { PORTA, 10, PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel18,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10   },
  { PORTA, 11, PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel19,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11   },
  { PORTB, 2,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel10,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTB, 3,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel11,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },

  // 38..39 Other Analog Pins
  { PORTA, 2,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  DAC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    }, // DAC/VOUT
  { PORTA, 3,  PIO_ANALOG,     (PIN_ATTR_ANALOG),                                  ADC_Channel1,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // AREF

  // 40..41 USB Pins
  { PORTA, 24, PIO_COM,        (PIN_ATTR_NONE),                                    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB_N
  { PORTA, 25, PIO_COM,        (PIN_ATTR_NONE),                                    No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB_P

  // 42..43 Serial
  { PORTB, 3,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    }, // SERIAL_RX
  { PORTB, 2,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    }, // SERIAL_TX

  // 44..45 Serial1
  { PORTA, 13, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_13   }, // SERIAL1_RX
  { PORTA, 12, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_12   }, // SERIAL1_TX

  // 46..49 SPI 
  { PORTA, 4,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_4    }, // SPI_MISO
  { PORTA, 5,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5    }, // SPI_SS
  { PORTA, 6,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6    }, // SPI_MOSI
  { PORTA, 7,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7    }, // SPI_SCK

  // 50..51 I2C for GPS & Accelerometer
  { PORTA, 22, PIO_SERCOM,     (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6    }, // I2C_SDA
  { PORTA, 23, PIO_SERCOM,     (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7    }, // I2C_SCL

   // 52..53 I2C1 for exernal devices
  { PORTA, 8,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI  }, // I2C1_SDA
  { PORTA, 9,  PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL),                                 No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_9    }  // I2C1_SCL
} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;	// SPI
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;	// Serial1
SERCOM sercom3( SERCOM3 ) ;	// I2C
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;	// Serial

Uart Serial(&sercom5, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
Uart Serial1(&sercom4, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);

void SERCOM4_Handler()
{
  Serial1.IrqHandler();
}

void SERCOM5_Handler()
{
  Serial.IrqHandler();
}

