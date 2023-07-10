#pragma once
#include <string>
#include <iostream>
#include "RBTree.hpp"
#include "Parts/Traks.hpp"
#include "Parts/PartS.hpp"
#include "Parts/Vehicle.hpp"
#include "Driver/Driver.hpp"

class IOHandler
{
private:
    bool useConsole = false;
    std::string playersFileName = "input/players.csv";
    std::string partsFileName = "input/pieces.csv";

public:
    IOHandler(int args, char *argsv[]);
    ~IOHandler();

    inline bool getUseConsole() { return this->useConsole; }
    inline std::string getPlayersFileName() { return this->playersFileName; }
    inline std::string getPartsFileName() { return this->partsFileName; }
    int menu();
    int pieceSubMenu();
    int tracksSubMenu(RBTree<traks> *tracks);
    int playerSubMenu(RBTree<Driver> *players);
    int cupSubMenu(RBTree<traks> *tracks, traks** tracksSelected);
};