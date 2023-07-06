#include "MotorcycleDriver.hpp"


MotorcycleDriver::MotorcycleDriver(std::string tag, std::string personaje, piece_s wheels, piece_s glider, piece_s vehicle)
        : Driver(tag, personaje, wheels, glider, vehicle){}

double MotorcycleDriver::get_time_land (int distancia) {
    return ((2*vehicle.velocity) 
    + (wheels.velocity) 
    - (glider.velocity));
}

double MotorcycleDriver::get_time_air (int distancia) {
    return (1.8 * 0.5 * glider.velocity);
}
