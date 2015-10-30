/*
  dtostrf - Emulation for dtostrf function from avr-libc
  Copyright (c) 2015 Arduino LLC.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {
  int iPart = (uint32_t)val;
  sprintf(sout, "%d", iPart);
    
  if (prec > 0) {
    size_t pos = strlen(sout);
    sout[pos++] = '.';
    int32_t dPart = (uint32_t)((val - floor(val)) * pow(10, prec));
    dPart = dPart > 0 ? dPart : 0;

    for (uint8_t i = (prec - 1); i > 0; i--) {
      size_t pow10 = pow(10, i);
      if (dPart < pow10) {
        sout[pos++] = '0';
      }
      else {
        sout[pos++] = '0' + dPart / pow10;

        dPart = dPart % pow10;
      }
    }

    sout[pos++] = '0' + dPart;
    sout[pos] = '\0';
  }
  
  return sout;
}

