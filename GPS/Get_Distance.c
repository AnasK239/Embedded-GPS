#include "GPS.h"


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