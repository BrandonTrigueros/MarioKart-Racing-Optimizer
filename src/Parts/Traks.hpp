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

        traks(const traks& other)
            : name (other.name)
            , landDistance (other.landDistance)
            , waterDistance (other.waterDistance)
            , airDistance (other.airDistance)
        {

        }

        ~traks() = default;
        
        inline std::string getName() const {return this->name;}
        inline int getLandDistance() const {return this->landDistance;}
        inline int getWaterDistance() const {return this->waterDistance;}
        inline int getAirDistance() const {return this->airDistance;}
};