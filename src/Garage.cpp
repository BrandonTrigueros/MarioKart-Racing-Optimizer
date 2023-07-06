
#include "Garage.hpp"
#include <fstream>
Garage::Garage ()
    {}

Garage::~Garage ()
{
    delete this->tiresT;
    delete this->glidersT;
    delete this->vehicleT;
    delete this->driversT;
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


}

void Garage::readParts (std::ifstream partsInput)
{
    std::string partType;
    int qPieces = 0;
    for (int category = 0; category < 6; ++category)
    {
        std::par
    }

}
        


