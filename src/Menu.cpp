#include "Menu.hpp"

Menu::Menu()
{
}

void Menu::run(Garage* garage, IOHandler* ioHandler)
{
    int option = 0;
    int option2 = 0;
    traks *trackSelected = nullptr;
    Driver *driverSelected = nullptr;
    while (option != 6)
    {
        traks *cup[4] = {nullptr, nullptr, nullptr, nullptr};
        option = ioHandler->menu();
        switch (option)
        {
        case 1:
            option2 = ioHandler->pieceSubMenu();
            switch (option2)
            {
            case 1:
                std::cout << "Todos los vehiculos son:\n"
                          << std::endl;
                garage->getVehiclesT()->printTreeOrder();
                break;
            case 2:
                std::cout << "Todas las llantas son:\n"
                          << std::endl;
                garage->getTiresT()->printTreeOrder();
                break;
            case 3:
                std::cout << "Todos los planeador son:\n"
                          << std::endl;
                garage->getGlidersT()->printTreeOrder();
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
            }
            break;
        case 2:
            std::cout << "Encontrando la mejor combinacion para todas las pistas:\n"
                      << std::endl;
            garage->findBestCombinatioForAll();
            break;
        case 3:
            option2 = ioHandler->tracksSubMenu(garage->getTraksT());
            if (option2 > 0)
                trackSelected = garage->getTraksT()->searchPerNumber(option2);
            if (trackSelected)
            {
                garage->showStatsTrack(trackSelected);
            }
            else
            {
                std::cout << "Esa pista no se encontró" << std::endl;
            }
            break;
        case 4:
            option2 = ioHandler->playerSubMenu(garage->getDriversT());
            if (option2 > 0)
                driverSelected = garage->getDriversT()->searchPerNumber(option2);
            if (driverSelected != nullptr)
            {
                if (driverSelected->getValid())
                {
                    std::cout << "Encontrando la mejor combinacion para piloto # " << option2 << ":\n\t" << driverSelected->getTag()
                              << std::endl;
                    garage->findAveragePos(driverSelected);
                }
                else
                {
                    std::cout << "El piloto: " << driverSelected->getTag() << " no tiene una combinacion valida\n"
                              << std::endl;
                }
            }
            else
            {
                std::cout << "Ese conductor no se encontró" << std::endl;
            }
            break;
        case 5:
            for (int i = 0; i < 4; i++)
            {
                option2 = ioHandler->cupSubMenu(garage->getTraksT(), cup);
                if (option2 > 0)
                    cup[i] = garage->getTraksT()->searchPerNumber(option2);

                else if (option2 == 0)
                {
                    std::cout << "Esa pista no se encontró" << std::endl;
                    --i;
                }
                else
                {
                    break;
                }
            }
            if (option2 < 0)
                break;
            std::cout << "Encontrando la mejor combinacion para copa:\n\t"
                      << std::endl;
            garage->findBestCombinatioForCup(cup);
            break;
        case 6:
            std::cout << "Saliendo del programa" << std::endl;
            break;
        default:
            std::cout << "Opcion no valida" << std::endl;
            option = 0;
            break;
        }
        if (!std::cin.good())
        {
            std::cout << "Error de entrada ❌" << std::endl;
            break;
        }
    }
}
