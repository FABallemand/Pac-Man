#ifndef __PATH_FINDER_H__
#define __PATH_FINDER_H__

#include <array>
#include <utility>
#include <cmath>
#include <vector>
#include <functional>

#include "const.h"
#include "logger.h"
#include "priority_queue.h"
#include "moveable.h"

#define MAX_PATH_LENGTH 999999

using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;
using APriorityQueue = PriorityQueue<std::pair<float, std::pair<int, int>>, std::vector<std::pair<float, std::pair<int, int>>>, std::greater<std::pair<float, std::pair<int, int>>>>;
using ACost = std::array<std::array<float, gconst::game::nb_columns>, gconst::game::nb_rows>;
using Neighbors = std::array<std::pair<int, int>, 4>;

/**
 * \class PathFinder
 *
 * \brief Path finding functor
 *
 */
class PathFinder
{
public:
    /**
     * \brief Find path to the target
     *
     * \param maze Representation of the maze
     * \param ghost_i Ghost row position
     * \param ghost_j Ghost column position
     * \param target_i Target row position
     * \param target_j Target column position
     * \return Direction Direction to follow in order to meet the target
     */
    Direction operator()(SimpleMaze &maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position);

private:
    static std::array<float, gconst::game::nb_columns> init_row_; //!< Row to initialise cost and heuristic array in AStar

    /**
     * \brief Find best direction according to the result of AStar
     *
     * \param ghost_position Position of the ghost
     * \param cost Array of cost
     * \return Direction Direction to follow
     */
    Direction bestDirection(std::pair<int, int> ghost_position, ACost &cost);

    /**
     * \brief AStar algoorithm, find the best path to go from one position to another
     *
     * \param maze Representation of the maze
     * \param ghost_position Position of the ghost
     * \param target_position Position of the target
     * \return Direction Direction to follow
     */
    Direction AStar(SimpleMaze &maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position);

    /**
     * \brief Compute euclidian distance between two positions
     *
     * \param position_1 First position
     * \param position_2 Second position
     * \return int Euclidian distance between position_1 and position_2
     */
    float distance(std::pair<int, int> position_1, std::pair<int, int> position_2);
};

#endif