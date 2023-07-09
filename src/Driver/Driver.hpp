#pragma once

#define DECLARE_RULE5(Class, Action)               \
    Class(const Class &other) = Action;            \
    Class(Class &&other) = Action;                 \
    Class &operator=(const Class &other) = Action; \
    Class &operator=(Class &&other) = Action        \

#include "../Parts/PartS.hpp"
#include "../Parts/Vehicle.hpp"
#include "../Parts/Traks.hpp"
#include <limits>

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

        virtual ~Driver();

        virtual double get_time_land (int distancia) =0;
        virtual double get_time_air (int distancia) =0;
        double get_time_water (int distancia);

        virtual double getTime(int landDis, int waterDis, int airDis);
        
        inline std::string getTag() const {return this->tag;}
        inline std::string getpersonage() const {return this->personage;}
        inline partS* getTires() const {return this->tiresD;}
        inline partS* getGlider() const {return this->gliderD;}
        inline Vehicle* getVehicle() const {return this->VehicleD;}
        inline bool getValid() const {return this->valid;}

        DECLARE_RULE5(Driver, default);
};
