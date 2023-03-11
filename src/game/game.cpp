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
        {EMPTY, PAC_MAN, EMPTY, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, GOMME, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, GOMME, WALL, EMPTY, WALL, WALL, WALL, WALL, WALL, EMPTY, WALL, GOMME, WALL, WALL, WALL, WALL, WALL},
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
                board_[i][j] = Cell{i, j};                                                          // Create empty cell
                gommes_.emplace_back(j * CELL_SIZE + offset_gomme_, i * CELL_SIZE + offset_gomme_); // Create gomme
                board_[i][j].addObject(&gommes_.back());                                            // Add gomme in the cell
                break;
            case SUPER_GOMME:
                board_[i][j] = Cell{i, j};                                                                            // Create empty cell
                gommes_.emplace_back(j * CELL_SIZE + offset_super_gomme_, i * CELL_SIZE + offset_super_gomme_, true); // Create gomme
                board_[i][j].addObject(&gommes_.back());                                                              // Add gomme in the cell
                break;
            case WALL:
                board_[i][j] = Cell{i, j, WALL}; // Create wall
                break;
            case GHOST_WALL:
                board_[i][j] = Cell{i, j, GHOST_WALL}; // Create special wall
                break;
            case PAC_MAN:
                board_[i][j] = Cell{i, j};                         // Create empty cell
                board_[i][j].addObject(&pacman_);                  // Add pacman in the cell
                pacman_.setNeighborhood(createNeighborhood(i, j)); // Tell pacman where he is
                break;
            default:
                LOG(ERROR) << "Incorrect maze";
                break;
            }
        }
    }
}

bool Game::update(const Uint8 *key_state, const float delta_t)
{
    pacman_.update(key_state, delta_t);
    if (pacman_.getNeighborhood()[1][1] != &board_[pacman_.getY() / 32][pacman_.getX() / 32])
    {
        pacman_.getNeighborhood()[1][1]->deletePacMan(&pacman_);
        board_[(pacman_.getY() + CELL_SIZE / 2) / CELL_SIZE][(pacman_.getX() + CELL_SIZE / 2) / CELL_SIZE].addObject(&pacman_);
        pacman_.setNeighborhood(createNeighborhood((pacman_.getY() + CELL_SIZE / 2) / CELL_SIZE, (pacman_.getX() + CELL_SIZE / 2) / CELL_SIZE));
    }

    if (pacman_.getState() == DEAD)
    {
        state_ = END;
        SDL_Delay(3000);
        return true;
    }
    return false;
}

void Game::display(SDL_Surface *sprite, SDL_Surface *window_surface)
{
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

CellNeighborhood Game::createNeighborhood(int i, int j)
{
    CellNeighborhood res;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            res[x][y] = &board_[(i + x - 1) % NB_ROWS][(j + y - 1) % NB_COLUMNS];
        }
    }
    return res;
}