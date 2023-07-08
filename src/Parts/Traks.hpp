#pragma once

#include <string>

class traks{
    private:
        std::string name;
        int landDistance;
        int waterDistance;
        int airDistance;
    public:
        traks (std::string name, int landDistance, int waterDistance, int airDistance)
            : name (name)
            , landDistance (landDistance)
            , waterDistance (waterDistance)
            , airDistance (airDistance)
        {

        }
        
        inline std::string getName() const {return this->name;}
        inline int getLandDistance() const {return this->landDistance;}
        inline int getWaterDistance() const {return this->waterDistance;}
        inline int getAirDistance() const {return this->airDistance;}
};