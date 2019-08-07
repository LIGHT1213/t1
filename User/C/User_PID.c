#include "User_PID.h"
#include "math.h"
static uint16_t x = 0; //74
static uint16_t y = 300; //64
float sx = 0, sy = 0;;
float PID_valueX=0;
float previous_errorX, previous_errorY;
int value =0;
int i=0;
int GetErrorX(void)
{
    return  Get_CoordinateXResult()-x;
}
void PIDOut(void)
{
    float KpX = 7.5, KiX = 0, KdX = 30;
    float errorX = 0, errorY = 0, PX = 0, IX = 0., DX = 0;
    errorX = GetErrorX();
    PX = errorX;
    IX = IX + errorX;
    DX = errorX - previous_errorX;
    PID_valueX = (KpX * PX) + (KiX * IX) + (KdX * DX);

    previous_errorX = errorX;
		if(PID_valueX>800)
			PID_valueX=800;
				if(PID_valueX<=-800)
			PID_valueX=-800;
    printf("X=%f\n",errorX);

//	printf("x=%d,y=%d\n",Get_CoordinateXResult(),Get_CoordinateYResult());
        ChannelOne_SetPositon(PID_valueX);

//    ChannelOne_SetPositon(0);
//    ChannelTwo_SetPositon(0);


}
void turn(void)
{
	int turn_value;
	value=Get_CoordinateXResult();
	printf("%d\n",value);
	while(value < 290||value>310)
	{
		for(i = 0;i < 1600;i++)
	{
		ChannelOne_SetPositon(i);
	HAL_Delay(1);
	}
	}
}

