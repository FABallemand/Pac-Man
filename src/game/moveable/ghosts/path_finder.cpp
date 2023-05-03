#include "path_finder.h"

Direction PathFinder::operator()(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j)
{
    // Mark the current position
    maze[ghost_i][ghost_j] = 1;

    if (target_i == ghost_i && target_j == ghost_j)
    {
        return NONE;
    }

    // Compute the length of the shortest path to target going in th efour directions
    int path_length[4];
    path_length[LEFT] = pathFindingRec(maze, ghost_i, ghost_j - 1, target_i, target_j);
    path_length[RIGHT] = pathFindingRec(maze, ghost_i, ghost_j + 1, target_i, target_j);
    path_length[UP] = pathFindingRec(maze, ghost_i - 1, ghost_j, target_i, target_j);
    path_length[DOWN] = pathFindingRec(maze, ghost_i + 1, ghost_j, target_i, target_j);
    int length = path_length[LEFT];
    Direction direction = NONE;
    for (int i = 1; i < 4; ++i)
    {
        if(path_length[i] >= LIMIT_PATH_LENGTH)
            continue;
        if (path_length[i] < length)
        {
            direction = (Direction)i;
            length = path_length[i];
        }
    }

    return direction;
}

int PathFinder::pathFindingRec(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j)
{
    int res = LIMIT_PATH_LENGTH;
    int tmp;

    // Check if position has already been explored
    if (maze[ghost_i][ghost_j] == 1)
    {
        LOG(DEBUG) << " ghost_i : " << ghost_i << " ghost_j : " << ghost_j ;
        return res;
    }
    else
    {
        maze[ghost_i][ghost_j] = 1; // Mark the position
    }

    // Compute path length
    if (target_i == ghost_i && target_j == ghost_j) // Already handled in wraper
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
                return pathFindingRec(maze, ghost_i, ghost_j - 1, target_i, target_j) + 1;
                break;
            case RIGHT:
                return pathFindingRec(maze, ghost_i, ghost_j + 1, target_i, target_j) + 1;
                break;
            case UP:
                return pathFindingRec(maze, ghost_i - 1, ghost_j, target_i, target_j) + 1;
                break;
            case DOWN:
                return pathFindingRec(maze, ghost_i + 1, ghost_j, target_i, target_j) + 1;
                break;
            default:
                LOG(ERROR) << "Invalid direction";
                return -1;
            }
        }
        else // Only one possible direction
        {
            if (maze[ghost_i - 1][ghost_j] == 0)
            {
                return pathFindingRec(maze, ghost_i - 1, ghost_j, target_i, target_j) + 1;
            }
            else if (maze[ghost_i + 1][ghost_j] == 0)
            {
                return pathFindingRec(maze, ghost_i + 1, ghost_j, target_i, target_j) + 1;
            }
            else if (maze[ghost_i][ghost_j - 1] == 0)
            {
                return pathFindingRec(maze, ghost_i, ghost_j - 1, target_i, target_j) + 1;
            }
            else if (maze[ghost_i][ghost_j + 1] == 0)
            {
                return pathFindingRec(maze, ghost_i, ghost_j + 1, target_i, target_j) + 1;
            }
        }
    }
    return res;
}

int PathFinder::distance(int i1, int j1, int i2, int j2)
{
    int delta_i = (i1 - i2) * (i1 - i2);
    int delta_j = (j1 - j2) * (j1 - j2);
    return sqrt(delta_i + delta_j);
}