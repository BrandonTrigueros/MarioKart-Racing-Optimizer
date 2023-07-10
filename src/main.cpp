#include "IOHandler.hpp"
#include "Garage.hpp"
#include "Menu.hpp"

#include <iostream>
int main (int argc, char* argv[])
{
    IOHandler* ioHandler = new IOHandler(argc, argv);
    Garage* garage = new Garage();
    Menu* menu = new Menu();
    garage->loadFiles(ioHandler->getUseConsole(),ioHandler->getPlayersFileName(), ioHandler->getPartsFileName());
    //garage->testR5();
    menu->run(garage, ioHandler);
    delete ioHandler;
    delete garage;
    delete menu;
}