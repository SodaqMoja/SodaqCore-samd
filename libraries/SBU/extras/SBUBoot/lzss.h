#ifndef SBU_LZSS_H_
#define SBU_LZSS_H_

/**************************************************************************************
   INCLUDE
 **************************************************************************************/

#include <stdint.h>

/**************************************************************************************
   FUNCTION DEFINITION
 **************************************************************************************/

void lzss_init(uint32_t const sketch_start);
void lzss_decode();
void lzss_flush();

#endif /* SBU_LZSS_H_ */