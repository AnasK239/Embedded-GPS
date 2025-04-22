#include <stdio.h>
#include <string.h>

#define NMEA_BUF_SIZE 128

float currLat, currLon; // global variables to hold the current coordinates

void Get_GPS_Coordinates(void) {

    char message[NMEA_BUF_SIZE]; // buffer to hold the NMEA message

    // wait for my gps to actually give me the NMEA string i don't know how to send from UART to here yet
    /*  do {
        UART1_ReadLine(sentence, sizeof(sentence));
    } while (strncmp(sentence, "$GPRMC", 6) != 0);
    */

    // recived NMEA from the gps thing
    char message[] = "$GPRMC,120818.94,A,3007.58084,N,03120.94863,E,,,120523,,,A*7F";


    char *token;          // pointer to hold the tokenized string
    int   index = 0;      // index of word in string

    // buffers to hold latitude and longitude in string format
    char lat_str[16] = {0}, lon_str[16] = {0};
    char lat_dir = 0,   lon_dir = 0;

    token = strtok(message, ",");   // split string by commas

    while (token) {
        switch (index) {
            // We only care about the following indices because the latitude and longitude with their directions are always

            case 3:  strncpy(lat_str, token, sizeof(lat_str)-1); break;

            case 4:  lat_dir = token[0];                         break;

            case 5:  strncpy(lon_str, token, sizeof(lon_str)-1); break;

            case 6:  lon_dir = token[0];                         break;
        }

        token = strtok(NULL, ","); // if not one of the indices i want set it to NULL and go to next (the next word starts at token[0])
        index++;
    }

    // convert the string values to decimal and save to my global variables
    currLat = nmea_to_decimal(lat_str, lat_dir);
    currLon = nmea_to_decimal(lon_str, lon_dir);
}


float nmea_to_decimal (const char *coordinate_str , char direction){
    
    float intial_coord = atof(coordinate_str);       // convert the recived string to a float

    // convert the float value to degrees and minutes then to decimal
    int degrees = (int)( intial_coord / 100.0);         // integer degrees  
    float minutes = intial_coord - (degrees * 100.0);   // remaining minutes  
    float dec = degrees + minutes / 60.0;               // final decimal value of the coordinate

    // south and west are negative
    if (direction == 'S' || direction == 'W')
        dec = -dec;
        
    return dec;
}