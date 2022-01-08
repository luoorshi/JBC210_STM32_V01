#ifndef __OLED_H
#define	__OLED_H

#include "drv_Init.h"


void OLED_Init_12864(void);
void OLED_Init_12832(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
void OLED_ItoC(unsigned int num, unsigned char *str);
void OLED_uItoC(unsigned int num,unsigned char *str);
void OLED_New_ItoC(unsigned int num,unsigned char *str,unsigned char len);

#endif


