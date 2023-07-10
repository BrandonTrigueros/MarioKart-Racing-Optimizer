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
     * @brief Reads part data from the input file and stores them in an RBTree.
     *
     * This method reads the specified number of parts from the parts input file.
     * Each part is represented by a line in the file, with the part's name, land, water,
     * and (optionally) air attributes separated by commas.
     *
     * It checks the part type: if partType is 0, it reads an additional air attribute from the line
     * and creates a new partS object with the name, land, water, and air attributes.
     * If partType is not 0, it creates a new partS object with the name, land, and water attributes only.
     *
     * Each newly created partS object is then inserted into the RBTree, with its name as the key.
     *
     * @param qParts The number of parts to read from the input file.
     * @param partType The type of parts to read (0 for parts with air attribute, other values for parts without air attribute).
     * @return Pointer to the RBTree of partS objects created from the input file data.
     */
    RBTree<partS> *readPartTree(int qTires, bool partType);

    /**
     * @brief Adds a track from a string line to the track RBTree.
     *
     * This method parses a string line, extracting the name, land distance,
     * water distance, and air distance for a track.
     * It then creates a new track with these attributes and adds it to the track RBTree.
     *
     * @param line A string line containing the track's information,
     * with the name and distances separated by commas.
     */
    void addTrack(std::string line);

    /**
     * @brief Adds a driver from a string line to the driver RBTree.
     *
     * This method parses a string line, extracting the tag, character,
     * vehicle, vehicle type, tires, and glider for a driver.
     * It then calls the createDriver method to create a new Driver object with these attributes,
     * and adds the new Driver to the driver RBTree.
     *
     * @param line A string line containing the driver's information,
     * with the tag, character, vehicle, vehicle type, tires, and glider separated by commas.
     */
    void addDriver(std::string line);

    /**
     * @brief Creates a new Driver object based on the provided information.
     *
     * This method creates a new Driver object based on the tag, character,
     * vehicle, vehicle type, tires, and glider information provided. It searches
     * the respective RBTrees (vehiclesT, tiresT, glidersT) to find the matching
     * objects for the driver's vehicle, tires, and glider. If all the necessary
     * objects are found, it creates a new driver object based on the vehicle type
     * and returns it. If any of the objects are not found, it creates a default
     * KartDriver object with the provided tag and character.
     *
     * @param tag The driver's tag.
     * @param character The driver's character.
     * @param vehicle The name of the driver's vehicle.
     * @param vehicleType The type of the driver's vehicle (e.g., "Kart", "Bike", "ATV").
     * @param tires The name of the driver's tires.
     * @param glider The name of the driver's glider (passed by reference).
     * @return A pointer to the newly created Driver object.
     */
    Driver *createDriver(std::string tag, std::string character, std::string vehicle, std::string vehicleType, std::string tires, std::string &glider);

    /**
     * @brief Finds the best combination of drivers for all tracks.
     *
     * This method iterates over all drivers and tracks to find the best combination
     * of drivers for all tracks. It calculates the total time for each driver on each track
     * and selects the driver with the minimum total time. The best driver, along with the
     * corresponding vehicle, tires, and glider, is printed as the result.
     */
    void findBestCombinatioForAll();

    /**
     * @brief Shows the stats for a specific track.
     *
     * This method calculates the best driver for a specific track by iterating over all
     * drivers and comparing their times on the given track. It prints the best driver,
     * along with the corresponding vehicle, tires, and glider, as the result.
     *
     * @param track The track for which to show the stats.
     */
    void showStatsTrack(traks *trackSelected);

    /**
     * @brief Finds the average position of a selected driver across all tracks.
     *
     * This method calculates the average position of a selected driver across all tracks.
     * It iterates over all tracks and compares the selected driver's time with the times
     * of other drivers on each track. The average position is calculated and printed as the result.
     *
     * @param driverSelected The selected driver.
     */
    void findAveragePos(Driver *driverSelected);

    /**
     * @brief Finds the best combination of drivers for a cup.
     *
     * This method finds the best combination of drivers for a cup by iterating over all
     * drivers and calculating the total time for each driver on each track of the cup.
     * It selects the driver with the minimum total time and prints the best driver,
     * along with the corresponding vehicle, tires, and glider, as the result.
     *
     * @param cup An array of tracks representing the cup.
     */
    void findBestCombinatioForCup(traks **cup);

    /**
     * @brief Remove leading and trailing whitespaces from a string.
     *
     * This function removes any leading and trailing whitespaces (spaces, tabs, newlines, etc.) from the given string.
     *
     * @param s The input string.
     * @return The trimmed string with leading and trailing whitespaces removed.
     */
    std::string trim(const std::string &str);

    /**
     * @brief Remove leading whitespaces from a string.
     *
     * This function removes any leading whitespaces (spaces, tabs, newlines, etc.) from the given string.
     *
     * @param s The input string.
     * @return The trimmed string with leading whitespaces removed.
     */
    std::string ltrim(const std::string &str);

    /**
     * @brief Remove trailing whitespaces from a string.
     *
     * This function removes any trailing whitespaces (spaces, tabs, newlines, etc.) from the given string.
     *
     * @param s The input string.
     * @return The trimmed string with trailing whitespaces removed.
     */
    std::string rtrim(const std::string &str);

public:
    /**
     * @brief Returns the RBTree of tires.
     *
     * This method returns a pointer to the RBTree object that contains the tires.
     *
     * @return Pointer to the RBTree of tires.
     */
    inline RBTree<partS> *getTiresT() { return this->tiresT; }

    /**
     * @brief Returns the RBTree of gliders.
     *
     * This method returns a pointer to the RBTree object that contains the gliders.
     *
     * @return Pointer to the RBTree of gliders.
     */
    inline RBTree<partS> *getGlidersT() { return this->glidersT; }

    /**
     * @brief Returns the RBTree of vehicles.
     *
     * This method returns a pointer to the RBTree object that contains the vehicles.
     *
     * @return Pointer to the RBTree of vehicles.
     */
    inline RBTree<Vehicle> *getVehiclesT() { return this->vehiclesT; }

    /**
     * @brief Returns the RBTree of tracks.
     *
     * This method returns a pointer to the RBTree object that contains the tracks.
     *
     * @return Pointer to the RBTree of tracks.
     */
    inline RBTree<traks> *getTraksT() { return this->traksT; }

    /**
     * @brief Returns the RBTree of drivers.
     *
     * This method returns a pointer to the RBTree object that contains the drivers.
     *
     * @return Pointer to the RBTree of drivers.
     */
    inline RBTree<Driver> *getDriversT() { return this->driversT; }
};