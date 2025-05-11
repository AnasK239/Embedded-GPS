#include "GPS.h"


Landmark landmar[NUM_LANDMARKS] = {

    {"HALLS A and B"  ,30.06417,31.28},
    {"HALLS C and D" , 30.06361, 31.28028},
    {"Architecture" ,  30.06389,  31.28056},

    {"Old Building" , 30.064554, 31.2788},  
 
    {"Library" , 30.06472,31.28028},  
    {"Library" , 30.06556,  31.28}, 

    {"Playground" , 30.0638833, 31.2792306},  

    {"Luban Workshop" , 30.06333,  31.27972},
    {"Luban Workshop" , 30.06361, 31.27889},

    {"Credit" , 30.063462,  31.278356},
    {"Kharasana" , 30.06417,  31.2775},
    {"Mosque" , 30.06472,  31.28028},
   
};
// returns -1 if the coordinates passed by gps are invalid
int8_t Get_GPS_Coordinates(double *currLat, double *currLon) {
    uint8_t   index = 0; 
    char message[NMEA_BUF_SIZE];
    char *token;        
    // buffers to hold latitude and longitude in string format
    char lat_str[COORDINATE_STR_SIZE] = {0}, lon_str[COORDINATE_STR_SIZE] = {0};
    // check if the string starts with $GPRMC
		
    do {
        UART2_ReadString(message, sizeof(message));
    } while (strncmp(message, "$GPRMC", 6) != 0);
       



    token = strtok(message, ",");   // split string by commas

    while (token != NULL) {
        
        
        switch (index) {
            // We only care about the following indices because the latitude and longitude are always here
            case VALID_INDEX:  if(token[0] != 'A')  return -2; // check if the string is valid
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

void Display_Location(double currLat, double currLon) {

    // find nearest landmark to my current location
    double bestDist = 100000;
    int8_t choice = -1;
	uint8_t i ;
    for ( i = 0; i < NUM_LANDMARKS; i++) {
        double d = haversine(currLat, currLon,landmar[i].lat, landmar[i].lon);

        if (d < bestDist) {
            bestDist = d;
            choice  = i;
        }
    }

    // display if in close proximity
    if (choice >= 0 && bestDist <= Proximity) {
				Lcd_string(landmar[choice].name);
    }
}

double deg2rad(double d) { 
    return d * M_PI / 180.0;
}

// haversine formula to get the distance between two points on the earth
double haversine(double lat1, double lon1, double lat2, double lon2) {   // lat 1 , long 1 are the current location passed by the GPS

    double theta1 = deg2rad(lat1), phi1 = deg2rad(lon1);
    double theta2 = deg2rad(lat2), phi2 = deg2rad(lon2);

    double delta_theta = theta2 - theta1;
    double delta_phi = phi2 - phi1;

    double a = sin(delta_theta/2)*sin(delta_theta/2)
                + cos(theta1)*cos(theta2)*sin(delta_phi/2)*sin(delta_phi/2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS_M * c;
}


