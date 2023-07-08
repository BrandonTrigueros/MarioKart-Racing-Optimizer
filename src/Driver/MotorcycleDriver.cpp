#include "MotorcycleDriver.hpp"


MotorcycleDriver::MotorcycleDriver(std::string tag, std::string personaje,  partS* tiresD, partS* gliderD, Vehicle* VehicleD)
        : Driver(tag, personaje, tiresD, gliderD, VehicleD){}

double MotorcycleDriver::get_time_land (int distancia) {
    return ((0.4 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        - (1.2 * this->tiresD->getAir())
        - (0.4 * this->gliderD->getAir()));
}

double MotorcycleDriver::get_time_air (int distancia) {
    return ((0.5 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        - (0.7 * this->tiresD->getAir())
        + (0.9 * this->gliderD->getAir()));
}
