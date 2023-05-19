#include "logger.h"

std::string LOG::getHeader(LogType type)
{
    std::string header;
    switch (type)
    {
    case DEBUG:
        header = BPURPLE + std::string{"[DEBUG] "} + RESET;
        break;
    case INFO:
        header = BBLUE + std::string{"[INFO] "} + RESET;
        break;
    case WARNING:
        header = BORANGE + std::string{"[WARNING] "} + RESET;
        break;
    case ERROR:
        header = BRED + std::string{"[ERROR] "} + RESET;
        break;
    case GAME:
        header = BGREEN + std::string{"[GAME] "} + RESET;
        break;
    }
    return header;
}