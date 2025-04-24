#ifndef TIMER_H_
#define TIMER_H_

#include "../tm4c123gh6pm.h"
#include "../Bit_util.h"
#include "stdio.h"
#include "stdint.h"

#define Max_reload 0x00FFFFFF
#define Control_shape 0x05
#define ms_delay 80000


void SysTick_Init(void);
void SysTick_Wait(uint32_t delay);
void SysTick_Wait1ms(uint32_t delay);

#endif