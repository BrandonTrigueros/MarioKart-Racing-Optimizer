#include "MotorcycleDriver.hpp"


MotorcycleDriver::MotorcycleDriver(std::string tag, std::string personaje,  partS* tiresD, partS* gliderD, Vehicle* VehicleD)
        : Driver(tag, personaje, tiresD, gliderD, VehicleD){}

double MotorcycleDriver::get_time_land (int distancia) {
    return distancia;
}

double MotorcycleDriver::get_time_air (int distancia) {
    return (distancia);
}
