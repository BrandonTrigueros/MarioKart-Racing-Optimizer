#pragma once

#include<limits>
#include "Driver.hpp"

class MotorcycleDriver final : public Driver {
    public:
        MotorcycleDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* vehicleD);
        
        double get_time_land (int distancia) override;
        
        double get_time_air (int distancia) override;
        
        inline Vehicle* getMotorcycle() const {return this->VehicleD;}

        double getTime(int landDis, int waterDis, int airDis) override;
};