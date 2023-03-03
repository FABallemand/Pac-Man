#include "game.h"

Game::Game()
{
    int maze_walls[NB_ROWS][NB_COLUMNS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 2, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 3, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 0, 2, 2, 1, 0, 0, 0, 1, 2, 2, 0, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    for (int i = 0; i < NB_ROWS; i++)
    {
        for (int j = 0; j < NB_COLUMNS; j++)
        {
            switch (maze_walls[i][j])
            {
            case 0:
                /* Create empty cell and add pac-gomme */
                break;
            case 1:
                /* Create Wall */
                break;
            case 2:
                /* Create empty cell without gomme*/
                break;
            case 3:
                /* code fantome Wall*/
                break;
            case 4:
                /* code empty cell and add super-pac-gomme*/
                break;
            default:
                break;
            }
        }
    }
}

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
    SDL_BlitScaled(sprite, &(bg_[NORMAL]), window_surface, nullptr);

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