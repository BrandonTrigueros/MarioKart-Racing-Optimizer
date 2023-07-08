#pragma once

#include "Driver/KartDriver.hpp"
#include "Driver/MotorcycleDriver.hpp"
#include "Driver/ATVDriver.hpp"
#include "RBTree.hpp"
#include <fstream>
#include <limits>
#include <sstream>

class Garage {
    private:
        RBTree<partS>* tiresT;
        RBTree<partS>* glidersT;
        RBTree<Vehicle>* vehiclesT;

        RBTree<traks>* traksT;
        RBTree<Driver>* driversT;
        std::ifstream playerInput;
        std::ifstream partsInput;
        
    public:
        Garage ();
        ~Garage ();


        void run (bool useConsole, std::string filePlayersName, std::string filePartsName);

        void readPartsFile ();

        void readVehicleTree(int qKarts);
        
        RBTree<partS>* readPartTree(int qTires, bool partType);

        void print();

        void readDriversFile ();

        void addTrack (std::string line);

        void addDriver (std::string line);

        Driver* createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string glider);
        // void printStats (Driver* Drivers[], int d_tierra, int d_agua, int d_aire)
        
};