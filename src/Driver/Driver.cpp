#include "Driver.hpp"

Driver::Driver (std::string tag, std::string personage)
    : tag(tag), personage(personage), valid(false)
    {}

Driver::Driver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* VehicleD)
    : tag(tag), personage(personage)
    , tiresD(tiresD), gliderD(gliderD)
    , VehicleD(VehicleD), valid(true)
    {}


double Driver::get_time_water (int distancia) {
    return ((0.7 * distancia) * this->VehicleD->getBaseSpeed());
}