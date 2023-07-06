#include "common.hpp"
#include "./Driver/Driver.hpp"
#include "RBTree.hpp"
#include <fstream>


class Garage {
    private:
        RBTree<tires_s> *tiresT;
        RBTree<glider_s> *glidersT;
        RBTree<vehicle_s> *kartsT;
        RBTree<vehicle_s> *bikesT;
        RBTree<vehicle_s> *ATVsT;
        RBTree<Driver*> *driversT;
        std::ifstream playerInput;
        std::ifstream partsInput;
        
    public:
        Garage ();
        ~Garage ();


        void run (bool useConsole, std::string filePlayersName, std::string filePartsName);

        void readParts ();

        void readKarts(int qKarts);
        
        void readTires(int qTires);

        void readBikes(int qBikes);

        void readATVs(int qATVs);

        void readGliders(int qGliders);

        
        // void readConductores (int& d_tierra, int& d_agua, int& d_aire);
        
        // void printStats (Driver* conductores[], int d_tierra, int d_agua, int d_aire);
        
};