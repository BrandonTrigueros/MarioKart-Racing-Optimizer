#include "common.hpp"

#include <cstring>


class ArgumentHandler
{
private:

    bool useConsole = false;
    std::string playersFileName = "input/players.csv";
    std::string partsFileName = "input/pieces.csv";

public:
    ArgumentHandler(int args, char* argsv[]);
    ~ArgumentHandler();

    inline bool getUseConsole(){return this->useConsole;}
    inline std::string getPlayersFileName(){return this->playersFileName;}
    inline std::string getPartsFileName(){return this->partsFileName;}
};


