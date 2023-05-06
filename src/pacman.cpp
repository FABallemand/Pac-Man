#include "application.h"

LogConf LOGGER_CONFIG; //!< Logger configuration

int main()
{
    // Create and run application
    Application pacman_game{};
    pacman_game.run();

    return 0;
}
