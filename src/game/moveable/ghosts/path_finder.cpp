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
    // path_length[LEFT] = pathFindingRec(maze, ghost_i, ghost_j - 1, target_i, target_j);
    // path_length[RIGHT] = pathFindingRec(maze, ghost_i, ghost_j + 1, target_i, target_j);
    // path_length[UP] = pathFindingRec(maze, ghost_i - 1, ghost_j, target_i, target_j);
    // path_length[DOWN] = pathFindingRec(maze, ghost_i + 1, ghost_j, target_i, target_j);
    int length = path_length[LEFT];
    Direction direction = NONE;
    for (int i = 1; i < 4; ++i)
    {
        if (path_length[i] >= LIMIT_PATH_LENGTH)
            continue;
        if (path_length[i] < length)
        {
            direction = (Direction)i;
            length = path_length[i];
        }
    }

    return direction;
}

int PathFinder::recreatePath(std::pair<int, int> current)
{
    return 0;
}

int PathFinder::pathFinderAStar(SimpleMaze maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position)
{
    // Initialize
    AQueue closed_list{};
    AQueue open_list{};

    ACost cost{};
    for (auto row : cost)
        row.fill(LIMIT_PATH_LENGTH);
    ACost heuristic{};
    for (auto row : heuristic)
        row.fill(LIMIT_PATH_LENGTH);

    open_list.push({0, ghost_position});

    // Main loop
    while (!open_list.empty())
    {
        std::pair<int, int> current = open_list.top().second;
        open_list.pop();

        // Target reached
        if (current == target_position)
        {
            return recreatePath(current); // TO DO
        }

        // Target not yet reached
        Neighbors current_neighbors{{{ghost_position.first, ghost_position.second - 1},
                                     {ghost_position.first, ghost_position.second + 1},
                                     {ghost_position.first - 1, ghost_position.second},
                                     {ghost_position.first + 1, ghost_position.second}}};
        for (auto neighbor : current_neighbors)
        {
            // Neighbor is a wall
            if (maze[neighbor.first][neighbor.second] == 1)
                continue;

            // If neighbor is not a wall
            if (!(closed_list.find({0, neighbor}) || (open_list.find({heuristic[neighbor.first][neighbor.second], neighbor}) && cost[neighbor.first][neighbor.second] < cost[current.first][current.second])))
            {
                cost[neighbor.first][neighbor.second] = cost[current.first][current.second] + 1;
                heuristic[neighbor.first][neighbor.second] = cost[current.first][current.second] + distance(neighbor, target_position);
                open_list.push({heuristic[neighbor.first][neighbor.second], neighbor});
            }
        }
        closed_list.push({0, current});
    }
}

int PathFinder::distance(std::pair<int, int> position_1, std::pair<int, int> position_2)
{
    int delta_i = (position_1.first - position_2.first) * (position_1.first - position_2.first);
    int delta_j = (position_1.second - position_2.second) * (position_1.second - position_2.second);
    return sqrt(delta_i + delta_j);
}