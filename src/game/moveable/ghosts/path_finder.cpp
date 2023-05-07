#include "path_finder.h"

std::array<float, gconst::game::nb_columns> PathFinder::init_row_ = {{MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH, MAX_PATH_LENGTH}};

Direction PathFinder::operator()(SimpleMaze &maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position)
{
    if (ghost_position == target_position)
    {
        return NONE;
    }
    return AStar(maze, target_position, ghost_position);
}

Direction PathFinder::bestDirection(std::pair<int, int> target_position, ACost &cost) // change for source and target
{
    // Target position
    int target_i = target_position.first;
    int target_j = target_position.second;

    // Find minimum cost (ie: where the path comes...)
    std::array<float,4> neighbor_cost;
    neighbor_cost[LEFT] = cost[target_i][target_j - 1];
    neighbor_cost[RIGHT] = cost[target_i][target_j + 1];
    neighbor_cost[UP] = cost[target_i - 1][target_j];
    neighbor_cost[DOWN] = cost[target_i + 1][target_j];

    Direction direction = LEFT;
    float min_cost = neighbor_cost[LEFT];
    for (int i = 1; i < 4; ++i)
    {
        if (neighbor_cost[i] < min_cost)
        {
            min_cost = neighbor_cost[i];
            direction = (Direction)i;
        }
    }
    return direction;
}

Direction PathFinder::AStar(SimpleMaze &maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position)
{
    // Initialize
    APriorityQueue closed_list{};
    APriorityQueue open_list{};

    ACost cost{};
    cost.fill(init_row_);

    ACost heuristic{};
    heuristic.fill(init_row_);

    open_list.push({0.0, ghost_position});
    cost[ghost_position.first][ghost_position.second] = 0;

    // Main loop
    while (!open_list.empty())
    {
        std::pair<int, int> current = open_list.top().second;
        open_list.pop();
        // LOG(DEBUG) << "CURRENT : " << current.first << " | " << current.second << " -> " << heuristic[current.first][current.second];

        // Target reached
        if (current == target_position)
        {
            return bestDirection(target_position, cost);
        }

        // Target not yet reached
        Neighbors current_neighbors{{{current.first, current.second - 1},
                                     {current.first, current.second + 1},
                                     {current.first - 1, current.second},
                                     {current.first + 1, current.second}}};
        for (auto neighbor : current_neighbors)
        {
            // Neighbor is a wall
            if (maze[neighbor.first][neighbor.second] == 1)
            {
                continue;
            }

            // If neighbor is not a wall
            if (!(closed_list.find({0.0, neighbor}) || (open_list.find({heuristic[neighbor.first][neighbor.second], neighbor}) && cost[neighbor.first][neighbor.second] < cost[current.first][current.second])))
            {
                cost[neighbor.first][neighbor.second] = cost[current.first][current.second] + 1;
                heuristic[neighbor.first][neighbor.second] = cost[current.first][current.second] + distance(neighbor, target_position);
                open_list.push({heuristic[neighbor.first][neighbor.second], neighbor});
            }
        }
        closed_list.push({0.0, current});
    }

    // Error
    LOG(ERROR) << "AStar is broken...";
    return NONE;
}

float PathFinder::distance(std::pair<int, int> position_1, std::pair<int, int> position_2)
{
    float delta_i = (position_1.first - position_2.first) * (position_1.first - position_2.first);
    float delta_j = (position_1.second - position_2.second) * (position_1.second - position_2.second);
    return sqrt(delta_i + delta_j);
}