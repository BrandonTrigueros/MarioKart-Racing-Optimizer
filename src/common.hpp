#include <iostream>
#include <string>
#include <limits>
#include <fstream>

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
