#include <iostream>
#include <string>
#include <limits>


typedef struct vehicle {
    std::string name;
    double aceleration;
    int baseSpeed; 
} vehicle_s;

typedef struct tires {
    std::string name;
    int landVelocity;
    int propellerVelocity;
    int airDrag;
} tires_s;

typedef struct glider {
    std::string name;
    int landDrag;
    int waterDrag;
    int airVelocity;
} glider_s;


typedef struct traks{
    std::string name;
    int landDistance;
    int waterDistance;
    int airDistance;
} track_s;
