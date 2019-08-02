#ifndef PID_H
#define PID_H
#include "User_PWM.h"
#include "User_Uart.h"
int GetErrorX(void);
int GetErrorY(void);
void PIDOut(void);
#endif