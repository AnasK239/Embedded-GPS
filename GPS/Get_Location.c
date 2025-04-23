#include "GPS.h"
#include "Landmarks.h"
void Display_Location(void) {
    
    double currLat, currLon;   // Given as global variables from GPS.c
    

    // find nearest landmark to my current location
    double bestDist = 1e9;
    uint8_t choice = -1;

    for (uint8_t i = 0; i < NUM_LANDMARKS; i++) {
        double d = haversine(currLat, currLon,landmarks[i].lat, landmarks[i].lon);

        if (d < bestDist) {
            bestDist = d;
            choice  = i;
        }
    }

    // display if in close proximity
    // TODO : Change this to output on the LCD
    if (choice >= 0 && bestDist <= Proximity) {
        printf(landmarks[choice].name);
    } else {
        printf("------------------");  
    }
}