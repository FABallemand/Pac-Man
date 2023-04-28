#include "ghost.h"

void Ghost::strategy()
{
    switch (state_)
    {
    case ALIVE:
        chase();
        break;
    default:
        LOG(ERROR) << "Invalid Ghost state";
    }
}

void Ghost::chase()
{
}

void Ghost::update(const float delta_t)
{
}

void Ghost::loadSimpleMaze()
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
                int cell_type = std::stoi(line.substr(start_pos, end_pos));
                ghost_board_[row][col] = cell_type == 3 ? 1 : 0; // Keep only walls
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

void Ghost::turn()
{
}

void Ghost::move()
{
}

void Ghost::handleMovement()
{
}

void Ghost::updateSprite()
{
}