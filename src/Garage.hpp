#include "common.hpp"
#include "./Driver/Driver.hpp"
#include "RBTree.hpp"


class Garage {
    private:
        RBTree<tires_s> *tiresT;
        RBTree<glider_s> *glidersT;
        RBTree<vehicle_s> *vehicleT;
   
        RBTree<Driver*> *driversT;
        
        
    public:
        Garage ();
        ~Garage ();


        void run (bool useConsole, std::string filePlayersName, std::string filePartsName);

        void readParts (std::ifstream partsInput);
        
        // void readConductores (int& d_tierra, int& d_agua, int& d_aire);
        
        // void printStats (Driver* conductores[], int d_tierra, int d_agua, int d_aire);
        
};