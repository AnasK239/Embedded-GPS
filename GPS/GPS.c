#include <stdio.h>
#include <string.h>
#include "GPS.h"


float currLat, currLon; // global variables to hold the current coordinates

// returns -1 if the coordinates passed by gps are invalid
uint8_t Get_GPS_Coordinates(void) {

    char message[NMEA_BUF_SIZE]; // buffer to hold the NMEA message

    // wait for my gps to actually give me the NMEA string i don't know how to send from UART to here yet
    // check if the string starts with $GPRMC
      do {
        UART2_ReadString(message, sizeof(message));
    } while (strncmp(message, "$GPRMC", 6) != 0);
       
    /*
    TODO: Validate the string
    */
    // check if the string is valid



    char *token;          // pointer to hold the tokenized string

    // buffers to hold latitude and longitude in string format
    char lat_str[COORDINATE_STR_SIZE] = {0}, lon_str[COORDINATE_STR_SIZE] = {0};
    char lat_dir = 0,   lon_dir = 0;

    token = strtok(message, ",");   // split string by commas

    uint8_t   index = 0; 
    while (token) {
        switch (index) {
            // We only care about the following indices because the latitude and longitude with their directions are always here
            case VALID_INDEX:  if(token[0] != 'A') return -1; // check if the string is valid
                                break;

            case LAT_INDEX :  strncpy(lat_str, token, sizeof(lat_str)-1); break;

            case LAT_DIR_INDEX:  lat_dir = token[0];                         break;

            case LON_INDEX:  strncpy(lon_str, token, sizeof(lon_str)-1); break;

            case LON_DIR_INDEX:  lon_dir = token[0];                         break;
        }

        token = strtok(NULL, ","); // if not one of the indices i want set it to NULL and go to next (the next word starts at token[0])
        index++;
    }

    // convert the string values to decimal and save to my global variables
    currLat = NMEA_to_decimal(lat_str, lat_dir);
    currLon = NMEA_to_decimal(lon_str, lon_dir);
    
    return 0; 
}


float NMEA_to_decimal (const char *coordinate_str){
    
    float intial_coord = atof(coordinate_str);       // convert the recived string to a float

    // convert the float value to degrees and minutes then to decimal
    int degrees = (int)( intial_coord / 100.0);         // integer degrees  
    float minutes = intial_coord - (degrees * 100.0);   // remaining minutes  
    float dec = degrees + minutes / 60.0;               // final decimal value of the coordinate

    return dec;
}