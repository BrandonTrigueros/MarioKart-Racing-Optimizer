#include "Garage.hpp"
// #include "../input/pieces.csv"
Garage::Garage ()
    {}

Garage::~Garage ()
{
    delete this->tiresT;
    delete this->glidersT;
    delete this->vehiclesT;
    delete this->driversT;
}

void Garage::loadFiles(bool useConsole, std::string filePlayersName, std::string filePartsName)
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
    playerInput.close();
    
}

void Garage::runMenu(IOHandler* ioHandler) {
    int option = 0;
    int option2 = 0;
    while (option != 6) {
        option = ioHandler->menu();
        switch (option) {
            case 1:
                option2 = ioHandler->pieceSubMenu();
                switch (option2) {
                    case 1:
                        std::cout<<"Todos los vehiculos son:\n" << std::endl;
                        this->vehiclesT->printTreeOrder();
                        break;
                    case 2:
                        std::cout<<"Todas las llantas son:\n" << std::endl;
                        this->tiresT->printTreeOrder();
                        break;
                    case 3:
                        std::cout<<"Todos los planeador son:\n" << std::endl;
                        this->glidersT->printTreeOrder();
                        break;
                    default:
                        
                        break;
                }
                break;
            case 2:
                this->findBestCombinatioForAll();
                break;
            case 3:
                option2 = ioHandler->tracksSubMenu(this->traksT);
                traks* trackSelected = this->traksT->findPerNumber(option2);
                std::cout<<"Imprimir estadisticas en Pista: # "<<option2<<"\n\t"<<trackSelected->getName()<<std::endl;
                this->showStatsTrack(trackSelected);
                break;
            // case 4:
            //     option2 = ioHandler->playerSubMenu(this->driversT);
            //     std::cout<< option2;
            //     break;
            // case 5:
            //     option2 = ioHandler->cupSubMenu(this->traksT);
            //     std::cout<< option2;
            //     break;
            // default:
            //     break;
        }
    }
}

//Codigo tomado de: https://www.techiedelight.com/trim-string-cpp-removeleading-trailingspaces/#:~:text=We%20can%20use%20a%20combination,functions%20to%20trim%20the%20string.
const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string& s)
{
 size_t start = s.find_first_not_of(WHITESPACE);
 return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s)
{
    return rtrim(ltrim(s));
}
// Fin de codigo tomado

void Garage::readPartsFile ()
{
    int qPieces = 0;
    std::string partType;
    this->vehiclesT = new RBTree<Vehicle>();
    for (int category = 0; category < 5; ++category)
    {
        std::getline(this->partsInput, partType, ',');
        this->partsInput>> qPieces;
        this->partsInput.ignore(15, '\n');
        if (!this->partsInput.good()){
            std::cerr << "Error de lectura";
            break;
        }
        if (partType == std::string("Karts"))
        {
            // std::cout << "si kart***";
            this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("Tires"))
        {
            // std::cout << "si llantas***";
            this->tiresT = this->readPartTree(qPieces, 0);
        }
        else if (partType == std::string("Bikes"))
        {
            // std::cout << "si motos***";
            this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("ATVs"))
        {
            // std::cout << "si atvs***";
            this->readVehicleTree(qPieces);
        }
        else if (partType == std::string("Gliders"))
        {
            // std::cout << "si gliders***";

            this->glidersT = this->readPartTree(qPieces, 1);
        }
        this->partsInput.ignore (10, '\n');
        // std::cout <<std::endl;
    }
}

void Garage::readVehicleTree (int qVehicles)
{
    // RBTree<Vehicle>* VehicleT = new RBTree<Vehicle>();
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
        // std::cout << name << std::endl;
        Vehicle* vehicle = new Vehicle(name, aceleration, baseSpeed);
        this->vehiclesT->insertNode(*vehicle, name);
    }
    
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
        // std::cout<< name <<std::endl;
        partS* part;
        if (partType == 0) {
            this->partsInput.ignore(1, ',');
            this->partsInput >> air; 
            part = new partS(name, land, water, air);
        }
        else {
            part = new partS(name, land, water);
        }
        this->partsInput.ignore(15, '\n');
        // std::cout << name << std::endl;
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
    //std::cout << "---------------------------------";
    this->driversT = new RBTree<Driver>();
    int i=0;
    while(line.length()){
        //std::cout <<"Linea de Driver leida --"<< line<< " --"<< std::endl;
        this->addDriver(line);
        std::getline(this->playerInput, line, '\n');

        i++;
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
    // std::cout<< name<< std::endl;
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
    glider = trim(glider);
    Driver* driver = this->createDriver(tag, character, vehicle, vehicleType, tires, glider);
    this->driversT->insertNode(*driver, tag);
}

Driver* Garage::createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string& glider)
{
    //std::cout<< "Buscando--------------" << vehicle<<"--------------"<< std::endl;
    Vehicle* vehicleD = this->vehiclesT->search(this->vehiclesT->getRoot(), vehicle);
    //std::cout<< "Buscando--------------" << tires <<"--------------"<< std::endl;
    partS *tiresD = this->tiresT->search(this->tiresT->getRoot(), tires);
    // std::cout<< "busco tires"<< std::endl;
    partS* gliderD = this->glidersT->search(this->glidersT->getRoot(), glider);
    // std::cout<< "busco gliders"<< std::endl;

    if (vehicleD && tiresD && gliderD) 
    {
        // std::cout<< "not null" << std::endl;
        if (vehicleType == std::string("Kart"))
        {
            return new KartDriver(tag, character, tiresD, gliderD, vehicleD);
        }
        else if (vehicleType == std::string("Bike"))
        {
            return new MotorcycleDriver(tag, character, tiresD, gliderD, vehicleD);
        }
        else if (vehicleType == std::string("ATV"))
        {
            return new ATVDriver(tag, character, tiresD, gliderD, vehicleD);
        }
    }
    // std::cout<< "yes null" << std::endl;

    return new Driver(tag, character);
}


void Garage::findBestCombinatioForAll(){
    // crear un arreglo de tiempos
    // recorer cada pista con cada Driver "2 for que recorran el arbol"
    // comparar cual tiene menor tiempo
    // imprimir ese Driver

}

void Garage::showStatsTrack (traks* track){
    // esto debe ser con un for para todos los jugadores
    Driver* driver = this->driversT->getRoot()->getValue();
    std::cout <<"Pista:\nlandD: "<<track->getLandDistance()<<" waterD: "<< track->getWaterDistance()<<" Aird: "<< track->getAirDistance()<< "|*|"<<std::endl;
    std::cout<< "GamerTag:"<<driver->getTag() <<"\n\tTiempo: "<< driver->getTime(track->getLandDistance(), track->getWaterDistance(), track->getAirDistance())<< ""<<std::endl;
}

