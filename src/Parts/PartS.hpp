#pragma once

#include <string>

class partS {
    private:
        std::string name;
        int land;
        int water;
        int air;
    public:

        partS () = default;
        partS(std::string name, int landVelocity, int waterVelocity, int airDrag)
            : name (name)
            , land (landVelocity)
            , water (waterVelocity)
            , air (airDrag)
        {}

        partS(std::string name, int landWaterDrag, int airVelocity) 
            : name (name)
            , land (landWaterDrag)
            , water (landWaterDrag)
            , air (airVelocity)
        {}

        partS(const partS& other)
            : name (other.name)
            , land (other.land)
            , water (other.water)
            , air (other.air)
        {}

        inline bool operator==(const partS& other) const {
            return (this->name == other.name && this->land == other.land && this->water == other.water && this->air == other.air);
        }

        ~partS() = default;
        
        inline std::string getName() const {return this->name;}
        inline int getLand() const {return this->land;}
        inline int getWater() const {return this->water;}
        inline int getAir() const {return this->air;}
};