#include "IOHandler.hpp"


IOHandler::IOHandler(int argc, char* argv[])
{
    for(int arg = 1; arg < argc; ++arg)
    {
        if(argv[arg] == std::string("-f") || argv[arg] == std::string("--file"))
        {
            this->partsFileName = argv[++arg];
            this->playersFileName = argv[++arg];
        }
        if(argv[arg] == std::string("-c") || argv[arg] == std::string("--console"))
        {
            this->useConsole = true;
            this->partsFileName = "";
            this->playersFileName = "";
        }
    }
}

IOHandler::~IOHandler()
{
}

int IOHandler::menu () {
     /*
● Mostrar todas las opciones disponibles para una pieza específica y sus características.
● Encontrar la combinación de piezas que tiene la mejor suma de tiempos para todas las pistas que se hayan agregado.
● Encontrar la mejor combinación de piezas para una pista en específico
● Obtener la posición promedio de un jugador a lo largo de todas las pistas
● Elegir un grupo de 4 pistas para formar una copa y encontrar la mejor combinación de piezas para esta copa.*/
    int choice;
    std::cout << "Seleccione una opción: \n" << std::endl;
    std::cout << "1. Mostrar todas las opciones disponibles para una pieza" << std::endl;
    std::cout << "2. Encontrar la combinación de piezas que tiene la mejor suma de tiempos para todas las pistas" << std::endl;
    std::cout << "3. Encontrar la mejor combinación de piezas para una pista en específico" << std::endl;
    std::cout << "4. Obtener la posición promedio de un jugador a lo largo de todas las pistas" << std::endl;
    std::cout << "5. Elegir un grupo de 4 pistas para formar una copa y encontrar la mejor combinación de piezas para esta copa" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cin >> choice;
    return choice;

}

int IOHandler::pieceSubMenu () {
    std::cout << "Seleccione una pieza para mostrar sus opciones: \n" << std::endl;
    std::cout << "1. Vehiculos" << std::endl;
    std::cout << "2. Ruedas" << std::endl;
    std::cout << "3. Planeadores" << std::endl;

    int choice = 0;
    std::cin >> choice;
    return choice;
}


int IOHandler::tracksSubMenu(RBTree<traks>* tracks) {
    std::cout << "Seleccione una pista para calcular la mejor combinación: \n" << std::endl;
    tracks->printTreeOrder();
    int choice = 0;

    std::cin >> choice;
    return choice;
}

int IOHandler::playerSubMenu(RBTree<Driver>* players) {
    std::cout << "Seleccione un jugador para calcular su posición promedio a lo largo de todas las pistas: \n" << std::endl;
    players->printTreeOrder();
    int choice = 0;

    std::cin >> choice;
    return choice;
}

int IOHandler::cupSubMenu(RBTree<traks>* tracks) {
    std::cout << "Seleccione cuatro pistas para creear una copa y calcular la mejor combinación para la copa: \n" << std::endl;
    tracks->printTreeOrder();
    int choice = 0;

    std::cin >> choice;
    return choice;
}