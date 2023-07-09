#pragma once

#include "Driver.hpp"

class ATVDriver final : public Driver {

    public:
        ATVDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* vehicleD);
        
        double get_time_land (int distancia) override;
        
        double get_time_air (int distancia) override;

        inline Vehicle* getATV() const {return this->VehicleD;}
};