#include "User_Uart.h"

//公有变量

//私有变量
static uint8_t _GetErrorRXBuffer[7] = {0};
static int16_t Coordinate1_One = 0 , Coordinate1_Two = 0;
static uint8_t CommandUpdateStatus = 0;


/* 查询命令是否更新函数 */
uint8_t Is_CommandUpdate(void)
{
	return CommandUpdateStatus;
}

/* 清除命令更新标志位函数 */
void Clear_CommandUpdateStatus(void)
{
	CommandUpdateStatus = 0;
}

/* 获取X(或者是Y明天决定)轴坐标结果 */
int16_t Get_CoordinateXResult(void)
{
	return Coordinate1_One;
}

/* 获取Y(或者是X明天决定)轴坐标结果 */
int16_t Get_CoordinateYResult(void)
{
	return Coordinate1_Two;
}




/* 误差获取串口 串口1 HC12串口 初始化 */
void User_GetErrorUart_Init(void)
{
	HAL_UART_Receive_IT(&huart1,_GetErrorRXBuffer,7);
}


/* 误差获取串口 UART1 HC12 OPENMV 串口 回调函数(中断处理函数) */
void _GetErrorUartCallBack(void)
{
	uint8_t Coordinate1[3] ={0} ,Coordinate2[3] = {0};
	
	//把/n作为断帧符
	if(_GetErrorRXBuffer[6] != '\n')
	{
		while(1)
		{
			//收不到正确的信息就重启
			printf("Fuck Your Mother 1000 Times.\r\n");
			NVIC_SystemReset();
		}
	}
	else
	{
		//拷贝前三个ASCII字符到坐标一字符串 后三个到坐标二字符串
		memcpy(Coordinate1,_GetErrorRXBuffer,3);
		memcpy(Coordinate2,&_GetErrorRXBuffer[3],3);
		//转换字符串到整数
		Coordinate1_One = atoi((const char*)Coordinate1);
		Coordinate1_Two = atoi((const char*)Coordinate2);
		//重新开启接收中断 等待下一次过程
		HAL_UART_Receive_IT(&huart1,_GetErrorRXBuffer,7);
		//指示收到新的指令
		CommandUpdateStatus = 1;
	}
}

