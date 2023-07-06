#include "Driver.hpp"

class ATVDriver final : public Driver {

    public:
        ATVDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* vehicleD);
        
        virtual double get_time_land (int distancia);
        
        virtual double get_time_air (int distancia);

        inline Vehicle* getATV() const {return this->VehicleD;}
};