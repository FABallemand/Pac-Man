#include "application.h"

LogConf LOGGER_CONFIG; //!< Logger configuration

int main(int argc, char **argv)
{
    // Create and run application
    Application pacman_game{};
    pacman_game.run();

    return 0;
}
