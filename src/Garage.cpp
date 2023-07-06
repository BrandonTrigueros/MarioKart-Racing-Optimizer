
#include "Garage.hpp"
Garage::Garage ()
    {}

Garage::~Garage ()
{
    // delete this->tiresT;
    // delete this->glidersT;
    // delete this->vehicleT;
    // delete this->driversT;
}

void Garage::run(bool useConsole, std::string filePlayersName, std::string filePartsName)
{
    std::ifstream playerInput;
    std::ifstream partsInput;
    if (useConsole)
    {
    }
    else
    {
        playerInput.open(filePlayersName);
        partsInput.open(filePartsName);
    }
    this->readParts();
    
}

void Garage::readParts ()
{
    std::string partType;
    int qPieces = 0;
    for (int category = 0; category < 6; ++category)
    {
        this->partsInput >> partType >> qPieces;
        if (partType == std::string("Karts"))
        {
            this->readKarts(qPieces);
        }
        else if (partType == std::string("Tires"))
        {
            this->readTires(qPieces);
        }
        else if (partType == std::string("Bikes"))
        {
            this->readBikes(qPieces);
        }
        else if (partType == std::string("ATVs"))
        {
            this->readATVs(qPieces);
        }
        else if (partType == std::string("Gliders"))
        {
            this->readGliders(qPieces);
        }
    }
}

void Garage::readKarts (int qKarts){
    for (int iPieces = 0; iPieces < qKarts; ++iPieces)
    {   
        vehicle_s kart;
        std::getline(this->partsInput, kart.name, ',');
        this->partsInput >> kart.aceleration >> kart.baseSpeed;
        // esto funciona asi?------------------------------------------------------------------------------
        this->kartsT->insertNode(kart);
    }
}

void Garage::readTires(int qTires)
{
    for (int iPieces = 0; iPieces < qTires; ++iPieces)
    {   
        tires_s tires;
        std::getline(this->partsInput, tires.name, ',');
        this->partsInput >> tires.landVelocity >> tires.propellerVelocity >> tires.airDrag;
        // esto funciona asi?------------------------faltan los ignore ------------------------
        this->tiresT->insertNode(tires);
    }
}

void Garage::readBikes(int qBikes)
{    
    for (int iPieces = 0; iPieces < qBikes; ++iPieces)
    {   
        vehicle_s bike;
        std::getline(this->partsInput, bike.name, ',');
        this->partsInput >> bike.aceleration >> bike.baseSpeed;
        // esto funciona asi?------------------------------------------------------------------------------
        this->bikesT->insertNode(bike);
    }

}

void Garage::readATVs(int qATVs)
{
    for (int iPieces = 0; iPieces < qATVs; ++iPieces)
    {   
        vehicle_s ATV;
        std::getline(this->partsInput, ATV.name, ',');
        this->partsInput >> ATV.aceleration >> ATV.baseSpeed;
        // esto funciona asi?------------------------------------------------------------------------------
        this->ATVsT->insertNode(ATV);
    }
}

void Garage::readGliders(int qGliders)
{
    for (int iPieces = 0; iPieces < qGliders; ++iPieces)
    {   
        glider_s glider;
        std::getline(this->partsInput, glider.name, ',');
        this->partsInput >> glider.landDrag >> glider.waterDrag >> glider.airVelocity;
        // esto funciona asi?------------------------------------------------------------------------------
        this->glidersT->insertNode(glider);
    }
}
        


