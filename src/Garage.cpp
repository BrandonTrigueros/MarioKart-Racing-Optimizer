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
        this->playerInput.open(filePlayersName);
        this->partsInput.open(filePartsName);
        
        this->readPartsFile();
        this->readDriversFile();

    }

    partsInput.close();
    // this->print();
    
}

void Garage::print(){
    std::cout <<"/*/"<< this->kartsT->getRoot()->getKey() << std::endl;
}

void Garage::readPartsFile ()
{
    int qPieces = 0;
    std::string partType = "vacio";
    for (int category = 0; category < 5; ++category)
    {
        std::getline(this->partsInput, partType, ',');
        this->partsInput>> qPieces;
        if (!this->partsInput.good()){
            std::cerr << "Error de lectura";
            break;
        }
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

void Garage::readDriversFile(){
    std::string line;
    this->traksT = new RBTree<traks>();
    std::getline(this->playerInput, line, '\n');
    // std::cout <<"*"<< line<< "*";
    while(line.length() > 1){
        this->addTrack(line);
        std::getline(this->playerInput, line, '\n');
        // break;
    }
    this->playerInput.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(this->playerInput, line, '\n');
    std::cout << "---------------------------------";
    this->driversT = new RBTree<Driver>();
    while(line.length() > 1){
        // std::cout <<"*"<< line<< "/"<< std::endl;
        this->addDriver(line);
        std::getline(this->playerInput, line, '\n');
        // break;
    }

}

void Garage::addTrack (std::string line)
{
    std::stringstream input(line);
    std::string name;
    int landDistance, waterDistance, airDistance;
    std::getline(input, name, ',');
    input >> landDistance; 
    input.ignore(1, ',');
    input >> waterDistance;
    input.ignore(1, ',');
    input >> airDistance; 
    input.ignore(15, '\n');
    traks* trak = new traks(name, landDistance, waterDistance, airDistance);
    this->traksT->insertNode(*trak, name);
    std::cout<< name<< std::endl;
}

void Garage::addDriver (std::string line)
{
    std::stringstream input(line);
    std::string tag, character, vehicle, vehicleType, tires, glider;
    std::getline(input, tag, ',');
    std::getline(input, character, ',');
    std::getline(input, vehicle, ',');
    std::getline(input, vehicleType, ',');
    std::getline(input, tires, ',');
    std::getline(input, glider, '\n');
    Driver* driver = createDriver(tag, character, vehicle, vehicleType, tires, glider);
    this->driversT->insertNode(*driver, tag);
    std::cout<< glider<< std::endl;
}

Driver* Garage::createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string glider)
{
    if (vehicleType == std::string("Kart")){
        //return new KartDriver(tag, character, find en el arbol estas partes);
    }


    return nullptr;
}
