#include "Driver.hpp"

Driver::Driver (std::string tag, std::string personage)
    : tag(tag), personage(personage), valid(false) 
    {}

Driver::Driver(std::string tag, std::string personage, part_s wheels, part_s glider, part_s vehicle)
    : tag(tag), personage(personage),
    wheels(wheels), glider(glider), 
    valid(true), vehicle(vehicle) 
    {}


double Driver::get_time_water (int distancia) {
    return ((0.7 * distancia) * vehicle.velocity);
}