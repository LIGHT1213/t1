#include "User_main.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

void User_main(void)
{
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	
	while(1)
	{
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,1500);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,1500);
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		HAL_Delay(2000);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,2500);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,2500);
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		HAL_Delay(2000);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,500);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,500);
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		HAL_Delay(2000);				
	}
}
