#include "CarDriver.hpp"

CarDriver::CarDriver(std::string tag, std::string personaje, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD);
: Driver(tag, personaje, wheels, glider, vehicle){}

double CarDriver::get_time_land (int distancia) {
    return ((2*vehicle.velocity) 
        + (wheels.velocity) 
        - (glider.velocity));
}

double CarDriver::get_time_air (int distancia) {
    return (1.8 * 0.5 * glider.velocity);
}