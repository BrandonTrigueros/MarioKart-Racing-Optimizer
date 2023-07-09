#include "KartDriver.hpp"

KartDriver::KartDriver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}

double KartDriver::get_time_land (int distancia) {
    if (distancia == 0) return 0;
    return ((0.5 * distancia) * this->VehicleD->getAceleration()
    + this->VehicleD->getBaseSpeed()
    + (1.1 * this->tiresD->getLand())
    - (1.5 * this->gliderD->getLand()));
}

double KartDriver::get_time_air (int distancia) {
    if (distancia == 0) return 0;
    return ((0.5 * distancia) * this->VehicleD->getAceleration()
    + this->VehicleD->getBaseSpeed()
    - (0.9 * this->tiresD->getAir())
    + (0.7 * this->gliderD->getAir()));
}

double KartDriver::getTime(int landDis, int waterDis, int airDis){
    if (!this->valid){
        std::cout << this->tag <<" invalido" <<std::endl;
        return std::numeric_limits<double>::max();
    }
    std::cout << this->tag;
    std::cout << "   Tiempo Tierra|"<< get_time_land(landDis) <<"|Tiempo Agua|"<< get_time_water(waterDis) << "|Tiempo Aire|" << get_time_air(airDis) << std::endl;
    return this->get_time_land(landDis) + this->get_time_water(waterDis) + this->get_time_air(airDis);
}
