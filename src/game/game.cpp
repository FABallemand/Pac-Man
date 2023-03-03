#include "game.h"

Game::Game()
{
    CellType maze_walls[NB_ROWS][NB_COLUMNS] = {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, GHOST_WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, GOMME, GOMME, GOMME, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, WALL, GOMME, GOMME, GOMME, WALL, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, GOMME, GOMME, GOMME, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, EMPTY, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL},
        {WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL},
        {WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}};

    for (int i = 0; i < NB_ROWS; ++i)
    {
        for (int j = 0; j < NB_COLUMNS; ++j)
        {
            switch (maze_walls[i][j])
            {
            case EMPTY:
                /* Create empty cell */
                board_[i][j] = Cell{i, j};
                break;
            case GOMME:
                /* Create empty cell with gomme */
                break;
            case SUPER_GOMME:
                /* Create empty cell with super-gomme */
                break;
            case WALL:
                /* Create wall cell */
                break;
            case GHOST_WALL:
                /* Create special wall cell */
                break;
            default:
                break;
            }
        }
    }
}

void Game::update(const Uint8 *key_state)
{
    LOG(DEBUG) << "Game::update";

    pacman_.update(key_state);
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