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

#include "time_init.h"
void Time_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		TIM_TimeBaseStructure.TIM_Period = 1000;
		TIM_TimeBaseStructure.TIM_Prescaler = 35999;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	//TIM_Cmd(TIM3,ENABLE);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

