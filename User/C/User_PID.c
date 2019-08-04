#include "User_PID.h"
#include "math.h"
static uint16_t x = 104; //74
static uint16_t y = 94; //64
float sx = 0, sy = 0;;

float previous_errorX, previous_errorY;
void SetPoint(uint16_t SetX, uint16_t SetY)
{
    x = SetX+3;
    y = SetY+8;
}
int GetErrorX(void)
{
    return x - Get_CoordinateXResult();
}
int GetErrorY(void)
{
    return y - Get_CoordinateYResult();
}
void PIDOut(void)
{
    float KpX = 57, KiX = 5, KdX = 1120;
    float KpY = 57, KiY = 5, KdY = 1120;
    float errorX = 0, errorY = 0, PX = 0, IX = 0., DX = 0, PID_valueX = 0, PY = 0, IY = 0., DY = 0, PID_valueY = 0;
    errorX = GetErrorX();
    PX = errorX;
    IX = IX + errorX;
    DX = errorX - previous_errorX;
    PID_valueX = (KpX * PX) + (KiX * IX) + (KdX * DX);

    previous_errorX = errorX;


    errorY = GetErrorY();
    PY = errorY;
    IY = IY + errorY;
    DY = errorY - previous_errorY;
    PID_valueY = (KpY * PY) + (KiY * IY) + (KdY * DY);
    previous_errorY = errorY;

    if(fabs(errorX) <= 5 && fabs(errorY) <= 5)
    {
        ChannelTwo_SetPositon(-sx);
        ChannelOne_SetPositon(sy);
    }
    else
    {
        sx = PID_valueX;
        sy = PID_valueY;
    }
    //printf("X=%f,Y=%f\n",errorX,errorY);

//	printf("x=%d,y=%d\n",Get_CoordinateXResult(),Get_CoordinateYResult());
    if(Get_CoordinateXResult() > 74)
        ChannelTwo_SetPositon(-PID_valueX);
    else
        ChannelTwo_SetPositon(-PID_valueX);
    if(Get_CoordinateYResult() > 64)
        ChannelOne_SetPositon(PID_valueY);
    else
        ChannelOne_SetPositon(PID_valueY);
//    ChannelOne_SetPositon(0);
//    ChannelTwo_SetPositon(0);


}

void GetCommand(uint8_t i)
{
    switch(i)
    {
    case 1:
        SetPoint(50, 34);
        break;
    case 2:
        SetPoint(77, 33);
        break;
    case 3:
        SetPoint(102, 34);
        break;
    case 4:
        SetPoint(46, 60);
        break;
    case 5:
        SetPoint(74, 60);
        break;
    case 6:
        SetPoint(105, 61);
        break;
    case 7:
        SetPoint(48, 85);
        break;
    case 8:
        SetPoint(74, 87);
        break;
    case 9:
        SetPoint(102, 88);
        break;
    default:
        SetPoint(74, 60);
        break;
    }
}
void DealQuestion(int i)
{
	if(i==1)
	{
		GetCommand(2);
	}
	else if(i==2)
	{
		GetCommand(1);
		HAL_Delay(4000);
		GetCommand(5);
		HAL_Delay(5000);
	}
	else if(i==3)
	{
		GetCommand(1);
		HAL_Delay(4000);
		GetCommand(4);
		HAL_Delay(2500);
		GetCommand(5);
		HAL_Delay(2500);
	}
	else if(i==4)
	{
		GetCommand(1);
		HAL_Delay(5000);
		GetCommand(5);
		HAL_Delay(1000);
		GetCommand(9);
		HAL_Delay(5000);
	}
	else if(i==5)
	{
		GetCommand(1);
		HAL_Delay(4000);
		GetCommand(2);
		HAL_Delay(4000);
		GetCommand(6);
		HAL_Delay(4000);
		GetCommand(9);
		HAL_Delay(3500);
	}
//	else if(i==6)
//	{
//		
//	}
//	else 
}