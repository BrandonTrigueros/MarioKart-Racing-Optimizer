#include "KartDriver.hpp"

KartDriver::KartDriver(std::string tag, std::string personaje, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}


double KartDriver::get_time_land (int distancia) {
    return 2;
}

double KartDriver::get_time_air (int distancia) {
    return 2;
}