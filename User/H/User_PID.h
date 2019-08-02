#ifndef PID_H
#define PID_H
#include "User_PWM.h"
#include "User_Uart.h"
int GetErrorX(void);
int GetErrorY(void);
void SetPoint(uint16_t SetX,uint16_t SetY);
void PIDOut(void);
#endif