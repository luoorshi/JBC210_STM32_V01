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

#include "pwm_init.h"

void PWM_Out_Init(void)
{
	/*******GPIO PA8 Init********/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/*******TIM 1 CH1 PA8 Init********/
	  TIM_TimeBaseStructure.TIM_Period = 9999;//计数10000 0.1k
    TIM_TimeBaseStructure.TIM_Prescaler = 72 - 1;//1us
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;//时钟分割
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;
		TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;//选择输出方式
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Enable;//输出使能
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//输出极性
		
		TIM_OC1Init(TIM1,&TIM_OCInitStructure);
		TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
		TIM_CtrlPWMOutputs(TIM1,ENABLE);
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	TIM_Cmd(TIM1,ENABLE);
}
