#include <string>

class partS {
    private:
        std::string name;
        int landV;
        int waterV;
        int airV;
    public:
        inline std::string getName() const {return this->name;}
        inline int getLandV() const {return this->landV;}
        inline int getWaterV() const {return this->waterV;}
        inline int getAirV() const {return this->airV;}
};