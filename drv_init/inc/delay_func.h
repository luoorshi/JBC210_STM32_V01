#ifndef __DELAY_FUNC_H
#define	__DELAY_FUNC_H

#include "stm32f10x.h"


static u16  fac_us=0;
static u16 fac_ms=0;

void DelayMs(unsigned int delayms);
void DelayS(unsigned int delays);




#endif


