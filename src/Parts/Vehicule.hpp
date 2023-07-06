#include <string>

class vehicule {
    private:
        std::string name;
        double aceleration;
        int baseSpeed; 
    public: 
        inline std::string getName() const {return this->name;} 
        inline double getAceleration() const {return this->aceleration;} 
        inline int getBaseSpeed() const {return this->baseSpeed;} 
};