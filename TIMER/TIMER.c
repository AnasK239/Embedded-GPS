#include"TIMER.h"

void SysTick_Init(void){
    NVIC_ST_CTRL_R = 0; // Disable SysTick during setup
    SET(NVIC_ST_RELOAD_R, Max_reload); // Set reload value to maximum
    NVIC_ST_CURRENT_R = 0; // Clear current value
    SET(NVIC_ST_CTRL_R, Control_shape); // Enable SysTick with processor clock
}

void SysTick_Wait(uint32_t delay){
    NVIC_ST_RELOAD_R = delay - 1; // Set reload value
    NVIC_ST_CURRENT_R = 0;
    while((NVIC_ST_CTRL_R & 0x00010000) == 0); // Wait for count flag
}

void SysTick_Wait1ms(uint32_t delay){
    for (uint32_t i = 0; i < delay; i++)
    {
        SysTick_Wait(ms_delay);
    }
    
}