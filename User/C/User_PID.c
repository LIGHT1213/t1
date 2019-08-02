#include "User_PID.h"
uint16_t x=73;
uint16_t y=66;
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
	float KpX = 0.01, KiX = 0, KdX = 0;
	float KpY = 0.01, KiY = 0, KdY = 0;
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
	ChannelOne_SetPositon(-PID_valueX);
	ChannelTwo_SetPositon(PID_valueY);
}