#include "ArgumentHandler.hpp"
#include "Garage.hpp"

#include <iostream>
int main (int argc, char* argv[]){
    ArgumentHandler* argHandler = new ArgumentHandler(argc, argv);
    Garage* garage = new Garage();
    garage->run(argHandler->getUseConsole(),argHandler->getPlayersFileName(), argHandler->getPartsFileName());


    return 0;
}