#include "Driver.hpp"

class MotorcycleDriver final : public Driver {
    public:
        MotorcycleDriver(std::string tag, std::string personaje, piece_s wheels, piece_s glider, piece_s vehicle);
        
        double get_time_land (int distancia);
        
        double get_time_air (int distancia);
        
        inline piece_s getMotorcycle() const {return this->vehicle;}
};