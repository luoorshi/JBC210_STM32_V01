/************************************************************************************
* Author : ls
* Version: 0.1
* Date   : 2021.11.09
* Email  : luoorshi@gmail.com
* Modification: none
* 
* Description:STM32F103C8T6 PWM int function
*
* Others: none;
*
* Function List:
*	1. void PWM_Out_Init(void) -- 配置CPU的硬件WPM
*
* History: none;
*
*************************************************************************************/

#include "delay_func.h"

void DelayMs(unsigned int delayms)
{

	u32 temp;

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SystemCoreClock/8000000;
	fac_ms=(u16)fac_us*1000;
    	 
	SysTick->LOAD=delayms*fac_ms;   		 
	SysTick->VAL=0x00;        
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; 
	SysTick->VAL =0X00;

	
}
void DelayS(unsigned int delays)
{
	for(;delays < 1;delays--)
	{
		DelayMs(1000);	
	}
}
