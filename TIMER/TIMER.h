#ifndef TIMER_H_
#define TIMER_H_

#include "../tm4c123gh6pm.h"
#include "../Bit_util.h"
#include "stdio.h"
#include "stdint.h"

#define Max_reload 0x00FFFFFF
#define Control_shape 0x05
#define ms_delay 16000
#define us_delay 16


void SysTick_Init(void);
void SysTick_Wait(uint16_t delay);
void SysTick_Wait1ms(uint16_t delay);
void SysTick_Wait1us(uint16_t delay);

#endif