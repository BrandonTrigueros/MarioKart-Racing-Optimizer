#include "common.hpp"

class Driver {
    protected:
        std::string tag;
        std::string personage;
        part_s wheels;
        part_s glider;
        part_s vehicle;
        bool valid;
    public:
        Driver (std::string tag, std::string personage);
        
        Driver(std::string tag, std::string personage, part_s wheels, part_s glider, part_s vehicle);
        
        virtual double get_time_land (int distancia) = 0;
        virtual double get_time_air (int distancia) = 0;
        double get_time_water (int distancia);
        
        inline std::string getTag() const {return this->tag;}
        inline std::string getpersonage() const {return this->personage;}
        inline part_s getWheels() const {return this->wheels;}
        inline part_s getGlider() const {return this->glider;}
        inline bool getValid() const {return this->valid;}
};
