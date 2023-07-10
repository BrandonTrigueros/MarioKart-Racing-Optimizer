#pragma once

#include <string>
#include <iostream>

class Vehicle {
    private:
        std::string name;
        double aceleration;
        int baseSpeed; 
    public: 

        Vehicle () = default;
        Vehicle (std::string name, double aceleration, int baseSpeed)
            : name (name)
            , aceleration (aceleration)
            , baseSpeed (baseSpeed)
        {}

        Vehicle (const Vehicle& other)
            : name (other.name)
            , aceleration (other.aceleration)
            , baseSpeed (other.baseSpeed)
        {}

        ~Vehicle() = default;
        inline std::string getName() const {return this->name;} 
        inline double getAceleration() const {return this->aceleration;} 
        inline int getBaseSpeed() const {return this->baseSpeed;}
};