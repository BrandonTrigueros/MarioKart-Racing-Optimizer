#include "ATVDriver.hpp"

ATVDriver::ATVDriver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}


double ATVDriver::get_time_land (int distancia) {
    // 0.6𝑑 ∗ 𝐴 + 𝑉 + 1.0𝑉𝑅 − 0.6𝐷𝑃 
    if (distancia == 0) return 0;
    return ((0.6 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        + (1.0 * this->tiresD->getLand())
        - (0.6 * this->gliderD->getLand()));
}

double ATVDriver::get_time_air (int distancia) {
    // 0.4𝑑 ∗ 𝐴 + 𝑉 − 0.68𝑉𝑅 − 0.8𝑉𝑃
    
    if (distancia == 0) return 0;
    return ((0.4 * distancia) * this->VehicleD->getAceleration() 
        + this->VehicleD->getBaseSpeed()
        - (0.68 * this->tiresD->getAir())
        - (0.8 * this->gliderD->getAir()));
}

double ATVDriver::getTime(int landDis, int waterDis, int airDis){
    if (!this->valid){
        std::cout << this->tag <<" invalido" <<std::endl;
        return std::numeric_limits<double>::max();
    }
    std::cout << this->tag;
    std::cout << "   Tiempo Tierra|"<< get_time_land(landDis) <<"|Tiempo Agua|"<< get_time_water(waterDis) << "|Tiempo Aire|" << get_time_air(airDis) << std::endl;

    return this-> get_time_land(landDis) + this->get_time_water(waterDis) + this->get_time_air(airDis);
}