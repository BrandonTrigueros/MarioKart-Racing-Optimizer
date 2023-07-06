#include "../Parts/Parts.hpp"
#include "../Parts/Vehicle.hpp"
#include "../Parts/Traks.hpp"

class Driver {
    protected:
        std::string tag;
        std::string personage;
        partS* tiresD;
        partS* gliderD;
        Vehicle* VehicleD;
        bool valid;
    public:
        Driver (std::string tag, std::string personage);
        
        Driver(std::string tag, std::string personage, partS* tiresD, partS* gliderD, Vehicle* VehicleD);
        virtual double get_time_land (int distancia) = 0;
        virtual double get_time_air (int distancia) = 0;
        double get_time_water (int distancia);
        
        inline std::string getTag() const {return this->tag;}
        inline std::string getpersonage() const {return this->personage;}
        inline partS* getTires() const {return this->tiresD;}
        inline partS* getGlider() const {return this->gliderD;}
        inline Vehicle* getVehicle() const {return this->VehicleD;}
        inline bool getValid() const {return this->valid;}
};
