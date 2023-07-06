#include "MotorcycleDriver.hpp"


MotorcycleDriver::MotorcycleDriver(std::string tag, std::string personaje,  tires_s tiresD, glider_s gliderD, vehicle_s vehicleD)
        : Driver(tag, personaje, tiresD, gliderD, vehicleD){}

double MotorcycleDriver::get_time_land (int distancia) {
    return ((2*vehicleD.baseSpeed) 
    + (tiresD.airDrag) 
    - (gliderD.airVelocity));
}

double MotorcycleDriver::get_time_air (int distancia) {
    return (1.8 * 0.5 * gliderD.airVelocity);
}
