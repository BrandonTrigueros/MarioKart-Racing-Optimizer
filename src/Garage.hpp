#pragma once

#include "Driver/KartDriver.hpp"
#include "Driver/MotorcycleDriver.hpp"
#include "Driver/ATVDriver.hpp"
#include "RBTree.hpp"
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

class Garage
{
private:
    RBTree<partS> *tiresT;
    RBTree<partS> *glidersT;
    RBTree<Vehicle> *vehiclesT; // Tree of pointers to vehicles because vehicle is an abstract class
    RBTree<traks> *traksT;
    RBTree<Driver> *driversT;

    std::ifstream playerInput;
    std::ifstream partsInput;

public:
    /**
     * @brief Constructor for the Garage class.
     *
     * Initializes all pointer attributes to nullptr and opens the provided
     * input files to load players and parts information.
     *
     * @param filePlayersName Name of the file containing player information.
     * @param filePartsName Name of the file containing parts information.
     */
    Garage(std::string filePlayersName, std::string filePartsName);

    /**
     * @brief Destructor for the Garage class.
     *
     * Frees up the memory allocated for the tire, glider, vehicle, driver,
     * and track pointers by deleting them. This ensures that no memory leaks occur.
     */
    ~Garage();

    /**
     * @brief Loads files into the Garage class.
     *
     * This method reads in the necessary data from the input files into the Garage.
     * If the useConsole parameter is set to true, console input is used.
     * Otherwise, it reads from the specified parts and drivers files.
     *
     * @param useConsole Boolean that determines whether to use console input (true) or file input (false).
     */
    void loadFiles(bool useConsole);

public:
    /**
     * @brief Performs tests on various functionality of the RBTree class.
     *
     * This method performs tests on the copy constructor, move constructor,
     * assignment operator, and move assignment operator of the RBTree class.
     * These tests involve copying and moving of Driver and partS instances
     * stored within RBTree objects. The results of each operation are
     * demonstrated by printing the states of the relevant trees before
     * and after each operation.
     */
    void testR5();

    /**
     * @brief Reads parts data from a file and stores them into the Garage.
     *
     * This method processes a CSV file that contains different types of vehicle parts.
     * The CSV file is structured with the type of the part and the quantity of parts
     * of that type, followed by the specific details for each part.
     * The different types of parts are Karts, Tires, Bikes, ATVs, and Gliders.
     * Depending on the type of part, they are read and stored into the appropriate
     * data structures within the Garage.
     *
     * This function reads the data directly from the `partsInput` ifstream object.
     */
    void readPartsFile();

    /**
     * @brief Reads drivers and tracks information from the input file and stores them in RBTrees.
     *
     * This method reads information about drivers and tracks from the drivers input file.
     * It first reads track information, creating new track objects and inserting them
     * into the tracks RBTree. This process continues until it encounters a line with a length of 1
     * or less. Then it ignores the rest of the current line and reads the driver information.
     *
     * Each line of driver information is used to create a new driver object which is
     * then inserted into the drivers RBTree. This process continues until it encounters
     * a line with zero length.
     */
    void readDriversFile();

    /**
     * @brief Reads vehicle information from the input file and stores it in a RBTree.
     *
     * This method reads information about vehicles from the parts input file.
     * The information is used to create new Vehicle objects which are then
     * inserted into a RBTree. The process repeats as many times as specified
     * by the 'qVehicles' parameter, each time reading the next line from the file.
     *
     * @param qVehicles The quantity of vehicles to read from the file.
     */
    void readVehicleTree(int qKarts);

    /**
     * @brief Reads part information from the input file and stores it in a RBTree.
     *
     * This method reads information about parts from the parts input file.
     * The information is used to create new partS objects which are then
     * inserted into a new RBTree. The process repeats as many times as specified
     * by the 'qParts' parameter, each time reading the next line from the file.
     * The function can handle two types of parts (indicated by 'partType'):
     * ones with three attributes and ones with four attributes.
     *
     * @param qParts The quantity of parts to read from the file.
     * @param partType Type of the part (0 or 1). 0 stands for parts with three attributes (name, land, water)
     * and 1 for parts with four attributes (name, land, water, air).
     * @return A pointer to the RBTree containing the read parts.
     */
    RBTree<partS> *readPartTree(int qTires, bool partType);

    void addTrack(std::string line);

    void addDriver(std::string line);

    Driver *createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string &glider);

    void findBestCombinatioForAll();

    void showStatsTrack(traks *trackSelected);

    void findAveragePos(Driver *driverSelected);

    void findBestCombinatioForCup(traks **cup);

    std::string trim(const std::string &str);

    std::string ltrim(const std::string &str);

    std::string rtrim(const std::string &str);

public:
    inline RBTree<partS> *getTiresT() { return this->tiresT; }
    inline RBTree<partS> *getGlidersT() { return this->glidersT; }
    inline RBTree<Vehicle> *getVehiclesT() { return this->vehiclesT; }
    inline RBTree<traks> *getTraksT() { return this->traksT; }
    inline RBTree<Driver> *getDriversT() { return this->driversT; }
};