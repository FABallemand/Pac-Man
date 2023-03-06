#include "game.h"

Game::Game()
{
    CellType maze_walls[NB_ROWS][NB_COLUMNS] = {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, SUPER_GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, SUPER_GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, GHOST_WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, GOMME, WALL},
        {WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL, WALL, WALL, GOMME, WALL},
        {WALL, SUPER_GOMME, GOMME, GOMME, WALL, GOMME, GOMME, GOMME, GOMME, GOMME, EMPTY, GOMME, GOMME, GOMME, GOMME, GOMME, WALL, GOMME, GOMME, SUPER_GOMME, WALL},
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
                board_[i][j] = Cell{i, j}; // Create empty cell
                break;
            case GOMME:
                board_[i][j] = Cell{i, j};                                                        // Create empty cell
                gommes_.emplace_back(j * CELL_SIZE + GOMME_OFFSET, i * CELL_SIZE + GOMME_OFFSET); // Create gomme
                board_[i][j].addObject(&gommes_.back());                                          // Add gomme in the cell
                break;
            case SUPER_GOMME:
                board_[i][j] = Cell{i, j};                                                                          // Create empty cell
                gommes_.emplace_back(j * CELL_SIZE + SUPER_GOMME_OFFSET, i * CELL_SIZE + SUPER_GOMME_OFFSET, true); // Create gomme
                board_[i][j].addObject(&gommes_.back());                                                            // Add gomme in the cell
                break;
            case WALL:
                board_[i][j] = Cell{i, j, WALL}; // Create wall
                break;
            case GHOST_WALL:
                board_[i][j] = Cell{i, j, GHOST_WALL}; // Create special wall
                break;
            default:
                LOG(ERROR) << "Incorrect maze";
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
    SDL_BlitScaled(sprite, &(bg_[state_]), window_surface, nullptr);

    // Eatable
    for (Gomme g : gommes_) // Gommes
    {
        g.display(sprite, window_surface);
    }
    // for (auto f : fruits_) // Fruits
    // {
    //     f.display();
    // }

    // Ghosts

    // Pac-Man
    pacman_.display(sprite, window_surface);
}