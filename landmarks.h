#ifndef LANDMARKS_H_
#define LANDMARKS_H_
#define NUM_LANDMARKS 18

typedef struct {
    char *name;
    double lat, lon;
} Landmark;

// List of landmarks with their coordinates ( NAME , Lat , Long )
Landmark landmarks[NUM_LANDMARKS] = {

    {"HALL A and HALL B"  ,30.06417,31.28},
    {"HALL C and HALL D" , 30.06361, 31.28028},
    {" Architecture Building" ,  30.06389,  31.28056},

    {"Old Building" , 30.06417, 31.27972},  
    {"Old Building" , 30.06361,  31.27889},           
    {"Old Building" ,  30.06333, 31.27917},
    {"Old Building" ,  30.06361, 31.28},

    {"Library" , 30.06472, 31.28028},  
    {"Library" , 30.06556,  31.28}, 

    {"Playground " , 30.06417, 31.27972},  
    {"Playground " ,  30.06361,  31.27889},  
    {"Playground " ,  30.06333, 31.27917},  
    {"Playground " , 30.06361,  31.28},  

    {"Luban Workshop Corners" , 30.06333,  31.27972},
    {"Luban Workshop Corners" , 30.06361, 31.27889},

    {"Credit Building" , 30.06333,  31.27806},
    {"Kharasana Building" , 30.06417,  31.2775},
    {"Mosque" , 30.06472,  31.28028},
   
};

#endif