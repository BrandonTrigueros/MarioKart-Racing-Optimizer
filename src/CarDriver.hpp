#include "common.hpp"
#include "Driver.hpp"

class CarDriver final : public Driver {

    public:
        CarDriver(std::string tag, std::string personaje, part_s wheels, part_s glider, part_s vehicle);
        
        virtual double get_time_land (int distancia);
        
        virtual double get_time_air (int distancia);

        inline part_s getCar() const {return this->vehicle;}
};