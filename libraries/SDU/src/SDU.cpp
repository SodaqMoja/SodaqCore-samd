/*
  Copyright (c) 2017 Arduino LLC.  All right reserved.

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

#include <Arduino.h>

#include "SDU.h"

__attribute__ ((section(".sketch_boot")))
unsigned char sduBoot[0x4000] = {
#if defined(ARDUINO_SAMD_ZERO)
  #include "boot/zero.h"
#elif defined(ARDUINO_SAMD_MKR1000)
  #include "boot/mkr1000.h"
#elif defined(ARDUINO_SAMD_MKRZERO)
  #include "boot/mkrzero.h"
#elif defined(ARDUINO_SAMD_MKRFox1200)
  #include "boot/mkrfox1200.h"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
  #include "boot/mkrgsm1400.h"
#elif defined(ARDUINO_SAMD_MKRWAN1300)
  #include "boot/mkrwan1300.h"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
  #include "boot/mkrwifi1010.h"
#elif defined(ARDUINO_SAMD_MKRNB1500)
  #include "boot/mkrnb1500.h"
#elif defined(ARDUINO_SAM_ZERO)
  #include "boot/mzero.h"
#elif defined(ARDUINO_SODAQ_AUTONOMO)
  #include "boot/sodaq_autonomo.h"
#elif defined(ARDUINO_SODAQ_EXPLORER)
  #include "boot/sodaq_explorer.h"
#elif defined(ARDUINO_SODAQ_ONE_BETA)
  #include "boot/sodaq_one_beta.h"
#elif defined(ARDUINO_SODAQ_ONE)
  #include "boot/sodaq_one.h"
#elif defined(ARDUINO_SODAQ_SARA)
  #include "boot/sodaq_sara.h"
#elif defined(ARDUINO_SODAQ_SFF)
  #include "boot/sodaq_sff.h"
#else
  #error "Unsupported board!"
#endif
};
