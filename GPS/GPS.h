#ifndef GPS
#define GPS

#define LAT_INDEX 3
#define LAT_DIR_INDEX 4
#define LON_INDEX 5
#define LON_DIR_INDEX 6
#define COORDINATE_STR_SIZE 16
#define NMEA_BUF_SIZE 85
#define M_PI 3.14159265358979323846
#define Proximity 10                                                    // how close am i to the landmark before displaying its name  (Meters)
#define EARTH_RADIUS_M         6371000.0
#define VALID_INDEX 2

#include "stdio.h"
#include "stdint.h"

uint8_t Get_GPS_Coordinates(void);                                         // returns decimal coordinates in the global variable currLat/currLon
float NMEA_to_decimal (const char *coordinate_str, char direction);

void Display_Location(void);                                            // displays the name of the nearest landmark to the current location on the LCD
double deg2rad(double d);
double haversine(double lat1, double lon1, double lat2, double lon2);   // returns the distance between two points on the earth in meters


#endif