#ifndef __FLASH_STM_H
#define	__FLASH_STM_H

#include "stm32f10x_flash.h"

u8 flash_read(u32 addr,u8 len,u32 * buff);

u8 flash_wite(u32 addr,u8 len,u32 * buff);



#endif


