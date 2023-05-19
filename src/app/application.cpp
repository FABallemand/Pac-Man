#include "application.h"

void Application::run()
{
    // Init SDL
    initSDL(window, window_surface, (char *)"Pac-Man", gconst::window::w, gconst::window::h, false);

    // Load assets
    loadAssets(sprite);

    // New game
    LOG(GAME) << "Entering the game";
    Game game{};

    game.run(window, window_surface, sprite);

    LOG(GAME) << "Quitting the game";

    SDL_Delay(500); // Delay

    // Unload assets
    unloadAssets(sprite);

    // Quit SDL
    quitSDL(window, window_surface);
}