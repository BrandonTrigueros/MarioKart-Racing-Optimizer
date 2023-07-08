#include "IOHandler.hpp"
#include "Garage.hpp"

#include <iostream>
int main (int argc, char* argv[]){
    IOHandler* ioHandler = new IOHandler(argc, argv);
    Garage* garage = new Garage();
    garage->loadFiles(ioHandler->getUseConsole(),ioHandler->getPlayersFileName(), ioHandler->getPartsFileName());
    garage->runMenu(ioHandler);
}