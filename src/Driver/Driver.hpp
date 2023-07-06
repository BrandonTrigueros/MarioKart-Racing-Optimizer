#include "common.hpp"

class Driver {
    protected:
        std::string tag;
        std::string personage;
        tires_s tiresD;
        glider_s gliderD;
        vehicle_s vehicleD;
        bool valid;
    public:
        Driver (std::string tag, std::string personage);
        
        Driver(std::string tag, std::string personage, tires_s tiresD, glider_s gliderD, vehicle_s vehicleD);
        virtual double get_time_land (int distancia) = 0;
        virtual double get_time_air (int distancia) = 0;
        double get_time_water (int distancia);
        
        inline std::string getTag() const {return this->tag;}
        inline std::string getpersonage() const {return this->personage;}
        inline tires_s getWheels() const {return this->tiresD;}
        inline glider_s getGlider() const {return this->gliderD;}
        inline bool getValid() const {return this->valid;}
};
