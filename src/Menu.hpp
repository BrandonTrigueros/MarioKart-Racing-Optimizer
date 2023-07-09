#pragma once

#include "IOHandler.hpp"
#include "Garage.hpp"
#include <fstream>
#include <limits>
#include <sstream>

class Menu
{
private:
public:
    Menu();
    void run(Garage* garage, IOHandler* ioHandler);
};