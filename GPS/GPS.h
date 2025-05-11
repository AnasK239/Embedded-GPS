#ifndef GPS_H
#define GPS_H

#define LAT_INDEX 3
#define LAT_DIR_INDEX 4
#define LON_INDEX 5
#define LON_DIR_INDEX 6
#define COORDINATE_STR_SIZE 16
#define NMEA_BUF_SIZE 85
#define M_PI 3.14159265358979323846
#define Proximity 10000                                                    // how close am i to the landmark before displaying its name  (Meters)
#define EARTH_RADIUS_M         6371000.0
#define VALID_INDEX 2
#define VALIDITY_ERROR -1

#include "../UART/UART.h"
#include "../LCD/LCD.h"
#include "stdio.h"
#include "stdint.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define NUM_LANDMARKS 18



typedef struct {
    char *name;
    double lat, lon;
} Landmark;

int8_t Get_GPS_Coordinates(double *currLat,double *currLon);                                         // returns decimal coordinates in the global variable currLat/currLon
double NMEA_to_decimal (const char *coordinate_str);

void Display_Location(double currLat, double currLon);                                            // displays the name of the nearest landmark to the current location on the LCD
double deg2rad(double d);
double haversine(double lat1, double lon1, double lat2, double lon2);   // returns the distance between two points on the earth in meters


#endif
