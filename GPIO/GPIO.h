#ifndef GPIO_H
#define GPIO_H

#include "../tm4c123gh6pm.h"
#include "stdio.h"
#include "stdint.h"

#define Functions_D6_D7 0xc0     // Enable alternate function, digital function and Disable analog function for PD6 and PD7
#define Clear_PCTL_D6_D7 0xFF000000
#define Set_PCTL_D6_D7 0x11000000

void Lcd_ports_init(void);
void UART_GPIO_INIT(void);

#endif
