/************************************************************************************
* Author : ls
* Version: 0.1
* Date   : 2021.11.09
* Email  : luoorshi@gmail.com
* Modification: none
* 
* Description:STM32F103C8T6 I2C int function
*
* Others: none;
*
* Function List:
*	1. void ADC_PB0_Init(void) -- 配置CPU的硬件ADC  PB0
* 2. void ADC_PB1_Init(void) -- 配置CPU的硬件ADC  PB1
* 3. void ADC_PA5_Init(void) -- 配置CPU的硬件ADC  PA5
*
* History: none;
*
*************************************************************************************/

#include "adc_init.h"

void ADC_PB0_Init(void)
{
	/*******GPIO PB0 Init********/
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_ADC1,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	/*******ADC1_CH8 PB0 Init********/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	ADC_InitStructure.ADC_NbrOfChannel = 1;	
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_239Cycles5);
  ADC_Cmd(ADC1, ENABLE);                                                /* Enable ADC1 */                      
  ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

void ADC_PB1_Init(void)
{
	/*******GPIO PB1 Init********/
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_ADC2,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	/*******ADC2_CH9 PB1 Init********/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	ADC_InitStructure.ADC_NbrOfChannel = 2;	
	ADC_Init(ADC2, &ADC_InitStructure);
	ADC_RegularChannelConfig(ADC2, ADC_Channel_9, 1, ADC_SampleTime_239Cycles5);
  ADC_Cmd(ADC2, ENABLE);                                                /* Enable ADC1 */                      
  ADC_SoftwareStartConvCmd(ADC2,ENABLE);
}

void ADC_PA5_Init(void)
{
	/*******GPIO PB1 Init********/
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_ADC2,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	/*******ADC2_CH5 PA5 Init********/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	ADC_InitStructure.ADC_NbrOfChannel = 2;	
	ADC_Init(ADC2, &ADC_InitStructure);
	ADC_RegularChannelConfig(ADC2, ADC_Channel_5, 2, ADC_SampleTime_239Cycles5);
  ADC_Cmd(ADC2, ENABLE);                                                /* Enable ADC1 */                      
  ADC_SoftwareStartConvCmd(ADC2,ENABLE);
}

