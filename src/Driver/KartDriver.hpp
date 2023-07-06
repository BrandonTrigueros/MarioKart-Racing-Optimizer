#include "Driver.hpp"

class KartDriver final : public Driver {

    public:
        KartDriver(std::string tag, std::string personaje, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD);
        
        virtual double get_time_land (int distancia);
        
        virtual double get_time_air (int distancia);

        inline vehicle_s getKart() const {return this->vehicleD;}
};