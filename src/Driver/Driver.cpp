#include "Driver.hpp"

Driver::Driver (std::string tag, std::string personage)
    : tag(tag), personage(personage), valid(false) 
    {}

Driver::Driver(std::string tag, std::string personage, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD)
    : tag(tag), personage(personage),
    tiresD(tiresD), gliderD(gliderD), 
    valid(true), vehicleD(vehicleD) 
    {}


double Driver::get_time_water (int distancia) {
    return ((0.7 * distancia) * vehicleD.baseSpeed);
}