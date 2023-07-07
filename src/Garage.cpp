#include "Garage.hpp"
// #include "../input/pieces.csv"
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
        this->partsInput.open(filePartsName);
        
        this->readParts();
    }

    partsInput.close();
    this->print();
    
}

void Garage::print(){
    std::cout <<"/*/"<< this->kartsT->getRoot()->getKey() << std::endl;
}

void Garage::readParts ()
{
    int qPieces = 0;
    std::string partType = "vacio";
    for (int category = 0; category < 5; ++category)
    {

        // this->partsInput.ignore(11, ',');
        std::getline(this->partsInput, partType, ',');
        this->partsInput>> qPieces;
        if (this->partsInput.good()){}
            // std::cout << "*"<<partType << " , "<< qPieces << std::endl;
        if (partType == std::string("Karts"))
        {
            std::cout << "si kart***";
            this->kartsT = this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("Tires"))
        {
            std::cout << "si llantas***";
            this->tiresT = this->readPartTree(qPieces, 0);
        }
        else if (partType == std::string("Bikes"))
        {
            std::cout << "si motos***";
            this->bikesT = this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("ATVs"))
        {
            std::cout << "si atvs***";
            this->ATVsT = this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("Gliders"))
        {
            std::cout << "si Gliders***";

            this->glidersT = this->readPartTree(qPieces, 1);
        }
        this->partsInput.ignore (10, '\n');
        std::cout <<std::endl;
    }
}

RBTree<Vehicle>* Garage::readVehicleTree (int qVehicles)
{
    RBTree<Vehicle>* VehicleT = new RBTree<Vehicle>();
    for (int iPieces = 0; iPieces < qVehicles; ++iPieces)
    {
        std::string name;
        double aceleration = 0;
        int baseSpeed = 0;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> aceleration; 
        this->partsInput.ignore(1, ',');
        this->partsInput >> baseSpeed;
        this->partsInput.ignore(15, '\n');
        std::cout << name;
        Vehicle* vehicle = new Vehicle(name, aceleration, baseSpeed);
        VehicleT->insertNode(*vehicle, name);
    }
    return VehicleT;
}

RBTree<partS>* Garage::readPartTree(int qParts, bool partType)
{
    RBTree<partS>* partT = new RBTree<partS>();
    for (int iPieces = 0; iPieces < qParts; ++iPieces)
    {
        std::string name;
        int land, water, air;
        std::getline(this->partsInput, name, ',');
        this->partsInput >> land; 
        this->partsInput.ignore(1, ',');
        this->partsInput >> water;
        this->partsInput.ignore(1, ',');
        this->partsInput >> air; 
        this->partsInput.ignore(15, '\n');
        std::cout<< name;
        partS* part;
        if (partType == 0) {
            part = new partS(name, land, water, air);
        }
        else {
            part = new partS(name, land, air);
        }
        partT->insertNode(*part, name);
    }
    return partT;
}

// void Garage::readBikes(int qBikes)
// {    
//     this->bikesT = new RBTree<Vehicle*>();
//     for (int iPieces = 0; iPieces < qBikes; ++iPieces)
//     {
//         std::string name;
//         int aceleration, baseSpeed;
//         std::getline(this->partsInput, name, ',');
//         this->partsInput >> aceleration; 
//         this->partsInput.ignore(1, ',');
//         this->partsInput >> baseSpeed;
//         this->partsInput.ignore(15, '\n');
//                 std::cout << name << aceleration <<" ~ "<< baseSpeed << std::endl;

//         Vehicle* bike = new Vehicle(name, aceleration, baseSpeed);
//         this->bikesT->insertNode(bike, name);
//     }

// }

// void Garage::readATVs(int qATVs)
// {
//     this->ATVsT = new RBTree<Vehicle*>();
//     for (int iPieces = 0; iPieces < qATVs; ++iPieces)
//     {
//         std::string name;
//         int aceleration, baseSpeed;
//         std::getline(this->partsInput, name, ',');
//         this->partsInput >> aceleration >> baseSpeed;
//         Vehicle* ATV = new Vehicle(name, aceleration, baseSpeed);
//         this->ATVsT->insertNode(ATV, name);
//     }
// }

// void Garage::readGliders(int qGliders)
// {
//     this->glidersT = new RBTree<partS*>();
//     for (int iPieces = 0; iPieces < qGliders; ++iPieces)
//     {   
//         std::string name;
//         int landDrag, waterDrag, airVelocity;
//         std::getline(this->partsInput, name, ',');
//         this->partsInput >> landDrag >> waterDrag >> airVelocity;
//         partS* glider = new partS(name, landDrag, waterDrag, airVelocity);
//         this->glidersT->insertNode(glider, name);
//     }
// }