#ifndef __PATH_FINDER_H__
#define __PATH_FINDER_H__

#include <array>
#include <cmath>

#include "const.h"
#include "logger.h"
#include "moveable.h"

#define LIMIT_PATH_LENGTH 999999
using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;

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
    Direction operator()(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j);

private:
    int pathFindingRec(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j);

    /**
     * \brief Compute euclidian distance between two positions on the board
     *
     * \param i1 Row of the first point
     * \param j1 Column of the first point
     * \param i2 Row of the second point
     * \param j2 Column of the second point
     * \return int Euclidian distance bewteen the points
     */
    int distance(int i1, int j1, int i2, int j2);
};

#endif