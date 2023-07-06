#include "Driver.hpp"

class MotorcycleDriver final : public Driver {
    public:
        MotorcycleDriver(std::string tag, std::string personaje, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD);
        
        double get_time_land (int distancia);
        
        double get_time_air (int distancia);
        
        inline vehicle_s getMotorcycle() const {return this->vehicleD;}
};