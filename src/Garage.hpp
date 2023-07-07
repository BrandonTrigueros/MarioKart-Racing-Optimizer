#include "Driver/Driver.hpp"
#include "RBTree.hpp"
#include <fstream>


class Garage {
    private:
        RBTree<partS*> *tiresT;
        RBTree<partS*> *glidersT;
        RBTree<Vehicle*> *kartsT;
        RBTree<Vehicle*> *bikesT;
        RBTree<Vehicle*> *ATVsT;
        RBTree<Driver*> *driversT;
        std::ifstream playerInput;
        std::ifstream partsInput;
        
    public:
        Garage ();
        ~Garage ();


        void run (bool useConsole, std::string filePlayersName, std::string filePartsName);

        void readParts ();

        RBTree<Vehicle*>* readVehicleTree(int qKarts);
        
        RBTree<partS*>* readPartTree(int qTires);

        // void readBikes(int qBikes);

        // void readATVs(int qATVs);

        // void readGliders(int qGliders);

        void print();

        // void readDrivers (int& d_tierra, int& d_agua, int& d_aire);
        
        // void printStats (Driver* Drivers[], int d_tierra, int d_agua, int d_aire);
        
};