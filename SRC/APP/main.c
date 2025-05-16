#include "../../HEADERS/HAL/GPS.h"
#include "../../HEADERS/HAL/LCD.h" 
#include "../../HEADERS/MCAL/TIMER.h"
#include "../../HEADERS/MCAL/GPIO.h"


void SystemInit(){};

int main(){
    int8_t y;
    double currLat = 0.0, currLon = 0.0;
    SysTick_Init();
    Lcd_init();
    UART_Init();

    while(1){

        do{
        y= Get_GPS_Coordinates(&currLat , &currLon);
        } while(y == -2);

        Display_Location(currLat,currLon);
        SysTick_Wait1ms(1000);
        Lcd_clear();
    }

    return 0;
}
