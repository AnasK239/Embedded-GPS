#include "GPS.h"
#include "../UART/UART.h"

// returns -1 if the coordinates passed by gps are invalid
int8_t Get_GPS_Coordinates(double *currLat, double *currLon) {

    char message[NMEA_BUF_SIZE];

    // check if the string starts with $GPRMC
      do {
        UART2_ReadString(message, sizeof(message));
    } while (strncmp(message, "$GPRMC", 6) != 0);
       

    char *token;          
    // buffers to hold latitude and longitude in string format
    char lat_str[COORDINATE_STR_SIZE] = {0}, lon_str[COORDINATE_STR_SIZE] = {0};

    token = strtok(message, ",");   // split string by commas
    uint8_t   index = 0; 
    while (token) {
        switch (index) {
            // We only care about the following indices because the latitude and longitude are always here
            case VALID_INDEX:  if(token[0] != 'A') return VALIDITY_ERROR; // check if the string is valid
                                                    break;

            case LAT_INDEX :  strncpy(lat_str, token, sizeof(lat_str)-1); break;

            case LON_INDEX:  strncpy(lon_str, token, sizeof(lon_str)-1); break;
        }

        token = strtok(NULL, ","); // if not one of the indices i want set it to NULL and go to next (the next word starts at token[0])
        index++;
    }

    // convert the string values to decimal and save to the passed variables
    if(currLat != NULL) *currLat = NMEA_to_decimal(lat_str);
    if(currLon != NULL) *currLon = NMEA_to_decimal(lon_str);
    
    return 0; 
}


double NMEA_to_decimal (const char *coordinate_str){
    
    double intial_coord = atof(coordinate_str);       // convert the recived string to a float

    // convert the float value to degrees and minutes then to decimal
    int degrees = (int)( intial_coord / 100.0);         // integer degrees  
    double minutes = intial_coord - (degrees * 100.0);   // remaining minutes  
    double dec = degrees + minutes / 60.0;               // final decimal value of the coordinate

    return dec;
}