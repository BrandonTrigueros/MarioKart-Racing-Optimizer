#include "KartDriver.hpp"

KartDriver::KartDriver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}


KartDriver::KartDriver(std::string tag, std::string personage)
    : Driver(tag, personage)
    {}

double KartDriver::get_time_land (int distancia) {
    if (distancia == 0) return 0;
    return ((0.5 * distancia) * this->VehicleD->getAceleration()
    + this->VehicleD->getBaseSpeed()
    + (1.1 * this->tiresD->getLand())
    - (1.5 * this->gliderD->getLand()));
}

double KartDriver::get_time_air (int distancia) {
    if (distancia == 0) return 0;
    return ((0.5 * distancia) * this->VehicleD->getAceleration()
    + this->VehicleD->getBaseSpeed()
    - (0.9 * this->tiresD->getAir())
    + (0.7 * this->gliderD->getAir()));
}