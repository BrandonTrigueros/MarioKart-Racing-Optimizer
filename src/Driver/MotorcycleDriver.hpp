#include "Driver.hpp"

class MotorcycleDriver final : public Driver {
    public:
        MotorcycleDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* vehicleD);
        
        double get_time_land (int distancia);
        
        double get_time_air (int distancia);
        
        inline Vehicle* getMotorcycle() const {return this->VehicleD;}
};