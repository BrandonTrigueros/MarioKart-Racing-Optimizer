#include "MotorcycleDriver.hpp"


MotorcycleDriver::MotorcycleDriver(std::string tag, std::string personaje,  partS* tiresD, partS* gliderD, Vehicle* VehicleD)
        : Driver(tag, personaje, tiresD, gliderD, VehicleD){}

        

double MotorcycleDriver::get_time_land (int distancia) {
    if (distancia == 0 ) return 0;
    
    return ((0.4 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        - (1.2 * this->tiresD->getAir())
        - (0.4 * this->gliderD->getAir()));
}

double MotorcycleDriver::get_time_air (int distancia) {
    if (distancia == 0 ) return 0;
    return ((0.5 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        - (0.7 * this->tiresD->getAir())
        + (0.9 * this->gliderD->getAir()));
}

double MotorcycleDriver::getTime(int landDis, int waterDis, int airDis){
    if (!this->valid){
        std::cout << this->tag <<" invalido" <<std::endl;
        return std::numeric_limits<double>::max();
    }
    std::cout << this->tag;
    std::cout << "   Tiempo Tierra|"<< get_time_land(landDis) <<"|Tiempo Agua|"<< get_time_water(waterDis) << "|Tiempo Aire|" << get_time_air(airDis) << std::endl;

    return this->get_time_land(landDis) + this->get_time_water(waterDis) + this->get_time_air(airDis);
}
