#include "game.h"

Game::Game()
{
    loadMaze();
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

void Game::createCell(int i, int j, int type)
{
    LOG(DEBUG) << "Game::createCell(" << i << "," << j << "," << type << ")";
    switch (type)
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

void Game::loadMaze()
{
    // Open file
    std::ifstream level{"../assets/level/maze.lvl", std::ios::in};

    if (level.is_open())
    {
        int row = 0;
        std::string line;
        const std::string delimiter = ",";
        while (std::getline(level, line))
        {
            size_t start_pos = 0;
            size_t end_pos;
            int col = 0;
            while ((end_pos = line.find(delimiter, start_pos)) != std::string::npos)
            {
                std::string cell_type = line.substr(start_pos, end_pos);
                createCell(row, col, std::stoi(cell_type));
                start_pos = end_pos + delimiter.length();
                ++col;
            }
            ++row;
        }
    }
    else
    {
        LOG(ERROR) << "Unable to open level file";
    }

    // Close file
    level.close();
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