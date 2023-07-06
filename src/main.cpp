#include "ArgumentHandler.hpp"
#include "Garage.hpp"

#include <iostream>
int main (int argc, char* argv[]){
    ArgumentHandler* manager = new ArgumentHandler(argc, argv);
    Garage* garage = new Garage();
    


    return 0;
}