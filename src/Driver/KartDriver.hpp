#include "Driver.hpp"

class KartDriver final : public Driver {

    public:
        KartDriver(std::string tag, std::string personaje, partS* tiresD, partS* gliderD, Vehicle* VehicleD);
        
        virtual double get_time_land (int distancia);
        
        virtual double get_time_air (int distancia);

        inline Vehicle* getKart() const {return this->VehicleD;}
};