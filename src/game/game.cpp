#include "game.h"

void Game::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
    LOG(DEBUG) << "Game::display";

    // Clear window
    SDL_FillRect(window_surface, nullptr, 0);

    // Background/Maze
    if (SDL_SetColorKey(sprite, SDL_FALSE, 0) != 0)
    {
        LOG(ERROR) << "Color key could not be set! SDL Error: " << SDL_GetError();
    }
    // SDL_BlitScaled(sprite, &(bg_[NORMAL]), window_surface, nullptr);
    SDL_BlitScaled(sprite, &(bg_[NORMAL]), window_surface, &maze_position_);

    // Eatable
    // for (auto row : board_)
    // {
    //     for (Cell *cell : row)
    //     {
    //         cell->display();
    //     }
    // }

    // Ghosts

    // Pac-Man
    pacman_.display(sprite, window_surface);
}

void Game::handleUserInputs(const Uint8 *key_state)
{
    pacman_.handleUserInputs(key_state);
}