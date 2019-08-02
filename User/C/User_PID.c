#include "User_PID.h"
uint16_t x=104;   //74
uint16_t y=92;   //64
float previous_errorX,previous_errorY;
int GetErrorX(void)
{
	return x-Get_CoordinateXResult();
}
int GetErrorY(void)
{
	return y-Get_CoordinateYResult();
}
void PIDOut(void)
{
	float KpX = 80, KiX = 0.2, KdX = 1000;
	float KpY = 80, KiY = 0.2, KdY = 1000;
	float errorX = 0, errorY=0 ,PX = 0, IX = 0., DX = 0, PID_valueX = 0,PY = 0, IY = 0., DY = 0, PID_valueY = 0;
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
	printf("X=%f,Y=%f\n",PID_valueX,PID_valueY);
	printf("x=%d,y=%d\n",Get_CoordinateXResult(),Get_CoordinateYResult());
	if(Get_CoordinateXResult()>74)
	ChannelTwo_SetPositon(-PID_valueX);
	else
	ChannelTwo_SetPositon(-PID_valueX);
	if(Get_CoordinateYResult()>64)
	ChannelOne_SetPositon(PID_valueY);
	else
	ChannelOne_SetPositon(PID_valueY);
}