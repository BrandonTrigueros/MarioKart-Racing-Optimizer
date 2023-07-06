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


    this->print();
    
}

void Garage::print(){
    std::cout << this->ATVsT->getRoot()->getKey() << std::endl;
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

void Garage::readKarts (int qKarts)
{
    this->kartsT = new RBTree<Vehicle*>();
    for (int iPieces = 0; iPieces < qKarts; ++iPieces)
    {   
        
        std::string name;
        int aceleration, baseSpeed;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> aceleration >> baseSpeed;
        Vehicle* kart = new Vehicle(name, aceleration, baseSpeed);
        this->kartsT->insertNode(kart, name);
    }
}

void Garage::readTires(int qTires)
{
    this->tiresT = new RBTree<partS*>();  
    for (int iPieces = 0; iPieces < qTires; ++iPieces)
    {   
        std::string name;
        int landVelocity, propellerVelocity, airDrag;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> landVelocity >> propellerVelocity >> airDrag;
        partS* tires = new partS(name, landVelocity, propellerVelocity, airDrag);
        this->tiresT->insertNode(tires, name);
    }
}

void Garage::readBikes(int qBikes)
{    
    this->bikesT = new RBTree<Vehicle*>();
    for (int iPieces = 0; iPieces < qBikes; ++iPieces)
    {
        std::string name;
        int aceleration, baseSpeed;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> aceleration >> baseSpeed;
        Vehicle* bike = new Vehicle(name, aceleration, baseSpeed);
        this->bikesT->insertNode(bike, name);
    }

}

void Garage::readATVs(int qATVs)
{
    this->ATVsT = new RBTree<Vehicle*>();
    for (int iPieces = 0; iPieces < qATVs; ++iPieces)
    {
        std::string name;
        int aceleration, baseSpeed;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> aceleration >> baseSpeed;
        Vehicle* ATV = new Vehicle(name, aceleration, baseSpeed);
        this->ATVsT->insertNode(ATV, name);
    }
}

void Garage::readGliders(int qGliders)
{
    this->glidersT = new RBTree<partS*>();
    for (int iPieces = 0; iPieces < qGliders; ++iPieces)
    {   
        std::string name;
        int landDrag, waterDrag, airVelocity;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> landDrag >> waterDrag >> airVelocity;
        partS* glider = new partS(name, landDrag, waterDrag, airVelocity);
        this->glidersT->insertNode(glider, name);
    }
}