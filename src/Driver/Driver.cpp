#include "Driver.hpp"
#include <limits>

Driver::Driver (std::string tag, std::string personage)
    : tag(tag), personage(personage), valid(false)
    {}

Driver::Driver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* VehicleD)
    : tag(tag), personage(personage)
    , tiresD(tiresD), gliderD(gliderD)
    , VehicleD(VehicleD), valid(true)
    {}

double Driver::get_time_water (int distancia) {
    if (distancia == 0) return 0;
    return ((0.7 * distancia) * this->VehicleD->getBaseSpeed()
    + this->VehicleD->getBaseSpeed()
    + (1.2 * this->tiresD->getWater())
    - (0.7 * this->gliderD->getWater()));
}
