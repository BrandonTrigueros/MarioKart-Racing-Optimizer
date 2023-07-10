#include "Driver.hpp"
#include <limits>

Driver::Driver(std::string tag, std::string personage)
    : tag(tag), personage(personage), valid(false)
{
}

Driver::Driver(std::string tag, std::string personage, partS *tiresD, partS *gliderD, Vehicle *VehicleD)
    : tag(tag), personage(personage), tiresD(tiresD), gliderD(gliderD), VehicleD(VehicleD), valid(true)
{
}

Driver::~Driver()
{
    this->tiresD = nullptr;
    this->gliderD = nullptr;
    this->VehicleD = nullptr;
}

double Driver::get_time_water(int distancia)
{
    if (distancia == 0)
        return 0;
    return (((0.7 * distancia) * (this->VehicleD->getBaseSpeed()) + this->VehicleD->getBaseSpeed()) + (1.2 * this->tiresD->getWater()) - (0.7 * this->gliderD->getWater()));
}

double Driver::getTime(int landDis, int waterDis, int airDis)
{
    if (!this->valid)
    {
        // std::cout << this->tag <<" invalido" <<std::endl;
        return std::numeric_limits<double>::max();
    }
    // std::cout << this->tag;
    // std::cout << "   Tiempo Tierra|"<< get_time_land(landDis) <<"|Tiempo Agua|"<< get_time_water(waterDis) << "|Tiempo Aire|" << get_time_air(airDis) << std::endl;

    return this->get_time_land(landDis) + this->get_time_water(waterDis) + this->get_time_air(airDis);
}