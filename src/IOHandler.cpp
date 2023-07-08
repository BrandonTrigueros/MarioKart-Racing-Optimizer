#include "IOHandler.hpp"

IOHandler::IOHandler(int argc, char *argv[])
{
    for (int arg = 1; arg < argc; ++arg)
    {
        if (argv[arg] == std::string("-f") || argv[arg] == std::string("--file"))
        {
            this->partsFileName = argv[++arg];
            this->playersFileName = argv[++arg];
        }
        if (argv[arg] == std::string("-c") || argv[arg] == std::string("--console"))
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

int IOHandler::menu()
{
    int choice;
    std::cout << "\nSeleccione una opción:" << std::endl;
    std::cout << "\t1. Mostrar todas las opciones disponibles para una pieza" << std::endl;
    std::cout << "\t2. Encontrar la combinación de piezas que tiene la mejor suma de tiempos para todas las pistas" << std::endl;
    std::cout << "\t3. Encontrar la mejor combinación de piezas para una pista en específico" << std::endl;
    std::cout << "\t4. Obtener la posición promedio de un jugador a lo largo de todas las pistas" << std::endl;
    std::cout << "\t5. Elegir un grupo de 4 pistas para formar una copa y encontrar la mejor combinación de piezas para esta copa" << std::endl;
    std::cout << "\t6. Salir" << std::endl
              << "---->";
    std::cin >> choice;
    return choice;
}

int IOHandler::pieceSubMenu()
{
    std::cout << "\nSeleccione una pieza para mostrar sus opciones:" << std::endl;
    std::cout << "\t1. Vehiculos" << std::endl;
    std::cout << "\t2. Ruedas" << std::endl;
    std::cout << "\t3. Planeadores" << std::endl
              << "---->";

    int choice = 0;
    std::cin >> choice;
    return choice;
}

int IOHandler::tracksSubMenu(RBTree<traks> *tracks)
{
    std::cout << "Seleccione una pista para calcular la mejor combinación: \n"
              << std::endl;
    tracks->printTreeOrder();
    std::cout << "---->";
    int choice = 0;

    std::cin >> choice;
    return choice;
}

int IOHandler::playerSubMenu(RBTree<Driver> *players)
{
    std::cout << "Seleccione un jugador para calcular su posición promedio a lo largo de todas las pistas: \n"
              << std::endl;
    players->printTreeOrder();
    std::cout << "---->";
    int choice = 0;

    std::cin >> choice;
    return choice;
}

int IOHandler::cupSubMenu(RBTree<traks> *tracks, traks** cup)
{
    int choice = 0;
    std::cout << "Pistas disponibles para la copa: \n"
              << std::endl;
    tracks->printTreeOrder();
    std::cout << "/n Pistas ya seleccionadas: \n"
              << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (cup[i] != nullptr)
        {
            std::cout << i + 1 << ". " << cup[i]->getName() << std::endl;
        }
    }
    std::cin >> choice;
    for (int i = 0; i < 4; i++)
    {
        if (tracks->searchPerNumber(choice - 1) == cup[i])
        {
            std::cout << "Pista ya seleccionada, seleccione una pista valida" << std::endl;
            cupSubMenu(tracks, cup);
        }
    }
    return choice;
}