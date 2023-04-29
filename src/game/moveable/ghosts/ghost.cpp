#include "ghost.h"

Direction Ghost::strategy(int target_i, int target_j)
{
    switch (state_)
    {
    case ALIVE:
        return chase(target_i, target_j);
        break;
    default:
        LOG(ERROR) << "Invalid Ghost state";
        return NONE;
    }
}

Direction Ghost::chase(int target_i, int target_j)
{
    // Mark the current position
    SimpleMaze maze = ghost_board_;
    int ghost_i = getI();
    int ghost_j = getJ();
    maze[ghost_i][ghost_j] = 1;

    // Compute the length of the shortest path to target going in th efour directions
    int path_length[4];
    path_length[LEFT] = chaseRec(maze, ghost_i, ghost_j - 1, target_i, target_j);
    path_length[RIGHT] = chaseRec(maze, ghost_i, ghost_j + 1, target_i, target_j);
    path_length[UP] = chaseRec(maze, ghost_i - 1, ghost_j, target_i, target_j);
    path_length[DOWN] = chaseRec(maze, ghost_i + 1, ghost_j, target_i, target_j);
    int length = path_length[LEFT];
    Direction direction = LEFT;
    for (int i = 1; i < 4; ++i)
    {
        if (path_length[i] < length)
        {
            direction = (Direction)i;
            length = path_length[i];
        }
    }

    return direction;
}

int Ghost::chaseRec(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j)
{
    int res = 9999999;
    int tmp;

    // Check if position has already been explored
    if (maze[ghost_i][ghost_j] == 1)
    {
        return res;
    }
    else
    {
        maze[ghost_i][ghost_j] = 1; // Mark the position
    }

    // Compute path length
    if (target_i == ghost_i && target_j == ghost_j)
    {
        return 0;
    }
    else
    {
        // Check if there are more than 1 possible direction
        if (maze[ghost_i + 1][ghost_j] + maze[ghost_i][ghost_j + 1] + maze[ghost_i - 1][ghost_j] + maze[ghost_i][ghost_j - 1] < 3)
        {
            // Compute euclidian distance to the target from each of the neighboring positions
            int path_length[4];
            path_length[LEFT] = (maze[ghost_i][ghost_j - 1] == 1) ? -1 : distance(ghost_i, ghost_j - 1, target_i, target_j);
            path_length[RIGHT] = (maze[ghost_i][ghost_j + 1] == 1) ? -1 : distance(ghost_i, ghost_j + 1, target_i, target_j);
            path_length[UP] = (maze[ghost_i + 1][ghost_j] == 1) ? -1 : distance(ghost_i - 1, ghost_j, target_i, target_j);
            path_length[DOWN] = (maze[ghost_i + 1][ghost_j] == 1) ? -1 : distance(ghost_i + 1, ghost_j, target_i, target_j);

            int length = 99999999;
            Direction direction = NONE;
            for (int i = 0; i < 4; ++i)
            {

                if (path_length[i] != -1 && path_length[i] < length)
                {
                    direction = (Direction)i;
                    length = path_length[i];
                }
            }
            switch (direction)
            {
            case LEFT:
                return chaseRec(maze, ghost_i, ghost_j - 1, target_i, target_j) + 1;
                break;
            case RIGHT:
                return chaseRec(maze, ghost_i, ghost_j + 1, target_i, target_j) + 1;
                break;
            case UP:
                return chaseRec(maze, ghost_i - 1, ghost_j, target_i, target_j) + 1;
                break;
            case DOWN:
                return chaseRec(maze, ghost_i + 1, ghost_j, target_i, target_j) + 1;
                break;
            default:
                LOG(ERROR) << "OSKOUR";
                return -1;
            }
        }
        else // Only one possible direction
        {
            if (maze[ghost_i - 1][ghost_j] == 0)
            {
                return chaseRec(maze, ghost_i - 1, ghost_j, target_i, target_j) + 1;
            }
            else if (maze[ghost_i + 1][ghost_j] == 0)
            {
                return chaseRec(maze, ghost_i + 1, ghost_j, target_i, target_j) + 1;
            }
            else if (maze[ghost_i][ghost_j - 1] == 0)
            {
                return chaseRec(maze, ghost_i, ghost_j - 1, target_i, target_j) + 1;
            }
            else if (maze[ghost_i][ghost_j + 1] == 0)
            {
                return chaseRec(maze, ghost_i, ghost_j + 1, target_i, target_j) + 1;
            }
        }
    }
    return res;
}

void Ghost::update(const float delta_t, int target_i, int target_j)
{
    Direction direction = strategy(target_i, target_j);
    LOG(DEBUG) << name_ << " | Pathfinding direction = " << direction;
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

    // Create a path to escape the ghost house
    ghost_board_[13][9] = 1;
    ghost_board_[13][11] = 1;
    ghost_board_[14][9] = 1;
    ghost_board_[14][11] = 1;
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

int Ghost::distance(int i1, int j1, int i2, int j2)
{
    int delta_i = (i1 - i2) * (i1 - i2);
    int delta_j = (j1 - j2) * (j1 - j2);
    return sqrt(delta_i + delta_j);
}