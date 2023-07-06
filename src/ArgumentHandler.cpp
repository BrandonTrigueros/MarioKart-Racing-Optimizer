#include "ArgumentHandler.hpp"


ArgumentHandler::ArgumentHandler(int argc, char* argv[])
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

ArgumentHandler::~ArgumentHandler()
{
}

