#include <string>

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
        {

        }
        inline std::string getName() const {return this->name;} 
        inline double getAceleration() const {return this->aceleration;} 
        inline int getBaseSpeed() const {return this->baseSpeed;} 
};