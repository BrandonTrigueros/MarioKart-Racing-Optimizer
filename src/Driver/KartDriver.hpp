#pragma once

#include "Driver.hpp"

class KartDriver final : public Driver {

    public:
        KartDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* VehicleD);

        KartDriver(std::string tag, std::string personaje);

        double get_time_land (int distancia) override;
        
        double get_time_air (int distancia) override;

        inline Vehicle* getKart() const {return this->VehicleD;}
};