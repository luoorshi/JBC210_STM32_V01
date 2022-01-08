
#include "drv_Init.h"
#include "User_func.h"


extern unsigned int Time_flag;
extern unsigned int Key_flag;

void Hal_Init(void)
{
	Time_Init();
	I2C_Configuration();
	PWM_Out_Init();
	ADC_PB0_Init();
	ADC_PB1_Init();
	OLED_Init_12832();

}

int main(void)
{
	Hal_Init();
	TIM_Cmd(TIM3,ENABLE);//STM32  TIM START
	while(1)
	{
		//Time_flag 10ms
		if(Time_flag&0x01 )
		{
			Time_flag = Time_flag & 0xfe;
			/*******************************
			
			*******************************/
		}
		//Time_flag 20ms
		if(Time_flag&0x02 )
		{
			Time_flag = Time_flag & 0xfd;
			/*******************************
			
			*******************************/
			
		}
		//Time_flag 50ms
		if(Time_flag&0x04 )
		{
			Time_flag = Time_flag & 0xfb;
			/*******************************
			
			*******************************/
			
		}
		//Time_flag 100ms
		if(Time_flag&0x08 )
		{
			Time_flag = Time_flag & 0xf7;
			/*******************************
			
			*******************************/
			
		}
		
	}
	
	return 0;
}

