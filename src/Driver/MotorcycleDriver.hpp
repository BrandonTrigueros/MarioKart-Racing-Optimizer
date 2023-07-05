#include "common.hpp"
#include "Driver.hpp"

class MotorcycleDriver final : public Driver {
    public:
        MotorcycleDriver(std::string tag, std::string personaje, part_s wheels, part_s glider, part_s vehicle);
        
        double get_time_land (int distancia);
        
        double get_time_air (int distancia);
        
        inline part_s getMotorcycle() const {return this->vehicle;}
};