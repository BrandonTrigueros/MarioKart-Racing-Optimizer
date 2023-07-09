#include "Garage.hpp"

Garage::Garage()
{
}

Garage::~Garage()
{
    delete this->tiresT;
    delete this->glidersT;
    delete this->vehiclesT;
    delete this->driversT;
    delete this->traksT;
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

// Codigo tomado de: https://www.techiedelight.com/trim-string-cpp-removeleading-trailingspaces/#:~:text=We%20can%20use%20a%20combination,functions%20to%20trim%20the%20string.
std::string Garage::ltrim(const std::string &s)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string Garage::rtrim(const std::string &s)
{
    const std::string WHITESPACE = " \n\r\t\f\v";
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string Garage::trim(const std::string &s)
{
    return rtrim(ltrim(s));
}
// Fin de codigo tomado

void Garage::readPartsFile()
{
    int qPieces = 0;
    std::string partType;
    this->vehiclesT = new RBTree<Vehicle>();
    for (int category = 0; category < 5; ++category)
    {
        std::getline(this->partsInput, partType, ',');
        this->partsInput >> qPieces;
        this->partsInput.ignore(15, '\n');

        if (!this->partsInput.good())
        {
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
        this->partsInput.ignore(10, '\n');
        // std::cout <<std::endl;
    }
}

void Garage::readVehicleTree(int qVehicles)
{
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

        Vehicle* vehicle = new Vehicle(name, aceleration, baseSpeed);
        this->vehiclesT->insertNode(vehicle, name);
    }
}

RBTree<partS>* Garage::readPartTree(int qParts, bool partType)
{
    RBTree<partS>* partT = new RBTree<partS>();
    for (int iPieces = 0; iPieces < qParts; ++iPieces)
    {
        partS* part;
        std::string name;
        int land, water, air;

        std::getline(this->partsInput, name, ',');
        this->partsInput >> land;
        this->partsInput.ignore(1, ',');
        this->partsInput >> water;

        if (partType == 0)
        {
            this->partsInput.ignore(1, ',');
            this->partsInput >> air;
            part = new partS(name, land, water, air);
        }
        else
        {
            part = new partS(name, land, water);
        }

        this->partsInput.ignore(15, '\n');
        partT->insertNode(part, name);
    }
    return partT;
}

void Garage::readDriversFile()
{
    std::string line;
    std::getline(this->playerInput, line, '\n');
    this->traksT = new RBTree<traks>();
    while (line.length() > 1)
    {
        this->addTrack(line);
        std::getline(this->playerInput, line, '\n');
    }

    this->playerInput.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(this->playerInput, line, '\n');
    this->driversT = new RBTree<Driver>();
    int i = 0;
    while (line.length())
    {
        this->addDriver(line);
        std::getline(this->playerInput, line, '\n');
        i++;
    }
}

void Garage::addTrack(std::string line)
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
    this->traksT->insertNode(trak, name);
}

void Garage::addDriver(std::string line)
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
    this->driversT->insertNode(driver, tag);
}

Driver* Garage::createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string &glider)
{
    Vehicle* vehicleD = this->vehiclesT->search(this->vehiclesT->getRoot(), vehicle);
    partS* tiresD = this->tiresT->search(this->tiresT->getRoot(), tires);
    partS* gliderD = this->glidersT->search(this->glidersT->getRoot(), glider);
    
    if (vehicleD && tiresD && gliderD)
    {
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
    return new KartDriver(tag, character);
}

void Garage::findBestCombinatioForAll()
{
    double minimunTime = std::numeric_limits<double>::max();
    double currentTime = 0;
    Driver* bestDriver = nullptr;
    for (typename RBTree<Driver>::Iterator it = this->driversT->begin(); it != this->driversT->end(); ++it)
    {
        Driver* driverA = it.getValue();
        if (!driverA->getValid())
            continue;
        for (typename RBTree<traks>::Iterator it2 = this->traksT->begin(); it2 != this->traksT->end(); ++it2)
        {
            currentTime += driverA->getTime(it2.getValue()->getLandDistance(), it2.getValue()->getWaterDistance(), it2.getValue()->getAirDistance());
            // std::cout << currentTime <<std::endl;
        }
        if (currentTime < minimunTime)
        {
            minimunTime = currentTime;
            bestDriver = driverA;
        }
        currentTime = 0;
    }
    if (bestDriver != nullptr)
    {
        std::cout << "La mejor combinación para todas las pistas es la del jugador " << bestDriver->getTag()
                  << " con un tiempo de " << minimunTime / 60.0 << " minutos" << std::endl
                  << "Automovil: " << bestDriver->getVehicle()->getName() << "\n"
                  << "Ruedas: " << bestDriver->getTires()->getName() << "\n"
                  << "Planeador: " << bestDriver->getGlider()->getName() << std::endl;
    }
}

void Garage::showStatsTrack(traks *track)
{
    double minimunTime = std::numeric_limits<double>::max();
    double currentTime = 0;
    Driver* bestDriver = nullptr;
    Driver* currentDriver = nullptr;
    // std::cout << "DistanciaTierra|"<<track->getLandDistance() <<"|Agua|"<< track->getWaterDistance() << "|Distancia Aire" << track->getAirDistance()<< std::endl;
    for (typename RBTree<Driver>::Iterator it = this->driversT->begin(); it != this->driversT->end(); ++it)
    {
        currentDriver = it.getValue();
        if (!currentDriver->getValid())
            continue;
        currentTime = currentDriver->getTime(track->getLandDistance(), track->getWaterDistance(), track->getAirDistance());
        if (currentTime < minimunTime)
        {
            minimunTime = currentTime;
            bestDriver = currentDriver;
        }
        currentTime = 0;
    }

    if (bestDriver != nullptr)
    {
        std::cout << "La mejor combinación para la pista " << track->getName() << " es la del jugador " << bestDriver->getTag()
                  << " con un tiempo de " << minimunTime << " segundos" << std::endl
                  << "Automovil: " << bestDriver->getVehicle()->getName() << "\n"
                  << "Ruedas: " << bestDriver->getTires()->getName() << "\n"
                  << "Planeador: " << bestDriver->getGlider()->getName() << std::endl;
    }
}

void Garage::findAveragePos(Driver *driverSelected)
{
    double pos = 0;
    double cTraks = 0;
    for (typename RBTree<traks>::Iterator itTrak = this->traksT->begin(); itTrak != this->traksT->end(); ++itTrak)
    {
        int landM = itTrak.getValue()->getLandDistance();
        int waterM = itTrak.getValue()->getWaterDistance();
        int airM = itTrak.getValue()->getAirDistance();
        double driverTime = driverSelected->getTime(landM, waterM, airM);
        ++pos;
        ++cTraks;
        // std::cout<< "driverTime" << driverTime << std::endl;
        for (typename RBTree<Driver>::Iterator itDriver = this->driversT->begin(); itDriver != this->driversT->end(); ++itDriver)
        {
            Driver* driverA = itDriver.getValue();
            if (!driverA->getValid())
            {
                break;
            }
            double currentTime = driverA->getTime(landM, waterM, airM);
            // std::cout << "current: " << currentTime <<std::endl;
            if (currentTime < driverTime)
            {
                ++pos;
            }
        }
    }
    // std::cout << pos << " | " << cTraks << std::endl;
    pos /= cTraks;
    std::cout << "La posicion promedio del jugador: " << driverSelected->getTag() << " es: " << pos << std::endl;
}

void Garage::findBestCombinatioForCup(traks **cup)
{
    double minimunTime = std::numeric_limits<double>::max();
    double currentTime = 0;
    Driver *bestDriver = nullptr;
    for (typename RBTree<Driver>::Iterator it = this->driversT->begin(); it != this->driversT->end(); ++it)
    {
        Driver* driverA = it.getValue();
        if (!driverA->getValid())
        {
            continue;
        }
        for (int i = 0; i < 4; ++i)
        {
            currentTime += driverA->getTime(cup[i]->getLandDistance(), cup[i]->getWaterDistance(), cup[i]->getAirDistance());
        }
        if (currentTime < minimunTime)
        {
            minimunTime = currentTime;
            bestDriver = driverA;
        }
        currentTime = 0;
    }
    std::cout << "La mejor combinación para la copa es la del jugador: " << bestDriver->getTag()
              << " con un tiempo de: " << minimunTime / 60 << " minutos"
              << "\nVehiculo: " << bestDriver->getVehicle()->getName() << "\n"
              << "Ruedas: " << bestDriver->getTires()->getName() << "\n"
              << "Planeador: " << bestDriver->getGlider()->getName() << std::endl;
}