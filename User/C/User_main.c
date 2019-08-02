#include "User_main.h"

#include "stm32f1xx_hal.h"

#include "User_Uart.h"

void User_main(void)
{
	/* 舵机控制初始化开始 初始化TIM1的 CH1 CH2 PWM模式 作为舵机控制的输出端口 分别对应PA8 PA9 */
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	/* 舵机控制初始化结束 */
	
	/* 图像误差获取串口初始化开始 选择UART1 PB7 PB8作为接收图像误差信息的串口 其连接了HC12 */
	User_GetErrorUart_Init();
	/* 图像误差获取串口初始化结束 */
	
	/* 调试串口初始化开始 使用无线调试器上的串口作为调试信息输出串口 */
	User_DebugUart_Init();
	//(需要修改printf重定向部分)
	
	/* 调试串口初始化结束 */
	
	while(1)
	{
		
		/* 南桥必读 */
		/* 当前版本 8.2 0:32 具备的功能 */
		
		/* 通过 Is_CommandUpdate() 查询命令是否更新  */
		/* 通过 Clear_CommandUpdateStatus() 清除命令标志位 */
		/* 通过 Get_CoordinateXResult()获取返回的第一个三位数坐标 */
		/* 通过 Get_CoordinateYResult()获取返回的第二个三位数坐标 */
		/* 究竟哪个函数是X 哪个是Y 得看明天的安装情况 */
		printf("FUCK\r\n");
		HAL_Delay(500);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,1500);
		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,1500);
	}
	
}
