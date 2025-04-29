#include"TIMER.h"

void SysTick_Init(void){
    NVIC_ST_CTRL_R = 0;
    SET(NVIC_ST_RELOAD_R, Max_reload);
    NVIC_ST_CURRENT_R = 0;
    SET(NVIC_ST_CTRL_R, Control_shape);
}

void SysTick_Wait(uint16_t delay){
    NVIC_ST_RELOAD_R = delay - 1;
    NVIC_ST_CURRENT_R = 0;
    while((NVIC_ST_CTRL_R & 0x00010000) == 0); // Wait for count flag
}

void SysTick_Wait1ms(uint16_t delay){
    for (uint16_t i = 0; i < delay; i++)
    {
        SysTick_Wait(ms_delay);
    }
}

void SysTick_Wait1us(uint16_t delay){
    for (uint16_t i = 0; i < delay; i++)
    {
        SysTick_Wait(us_delay);
    }
}