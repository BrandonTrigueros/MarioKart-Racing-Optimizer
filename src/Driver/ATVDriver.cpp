#include "ATVDriver.hpp"

ATVDriver::ATVDriver(std::string tag, std::string personaje, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD)
    : Driver(tag, personage, tiresD, gliderD, vehicleD)
    {}


double ATVDriver::get_time_land (int distancia) {
    // 0.6𝑑 ∗ 𝐴 + 𝑉 + 1.0𝑉𝑅 − 0.6𝐷𝑃 
    return (0.6 * distancia) 
        * this->vehicleD.aceleration 
        + this->vehicleD.baseSpeed 
        + this->tiresD.landVelocity 
        - (0.6 * this->gliderD.landDrag);
}

double ATVDriver::get_time_air (int distancia) {
    // 0.4𝑑 ∗ 𝐴 + 𝑉 − 0.68𝑉𝑅 − 0.8𝑉𝑃
    return (0.4 * distancia)
    * this->vehicleD.aceleration
    + this->vehicleD.baseSpeed
    - (0.68 * this->tiresD.airDrag)
    - (0.8 * this->gliderD.airVelocity);
}