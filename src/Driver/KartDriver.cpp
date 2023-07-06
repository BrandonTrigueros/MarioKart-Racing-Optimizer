#include "KartDriver.hpp"

KartDriver::KartDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}


double KartDriver::get_time_land (int distancia) {
    return 2;
}

double KartDriver::get_time_air (int distancia) {
    return 2;
}