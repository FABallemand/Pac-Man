#ifndef __PATH_FINDER_H__
#define __PATH_FINDER_H__

#include <array>
#include <utility>
#include <cmath>
#include <queue>
#include <vector>
#include <functional>

#include "const.h"
#include "logger.h"
#include "moveable.h"

#define LIMIT_PATH_LENGTH 999999

// Inspired by: https://stackoverflow.com/questions/16749723/how-i-can-find-value-in-priority-queue
template <
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>>
class PriorityQueue : public std::priority_queue<T, Container, Compare>
{
public:
    // typedef typename std::priority_queue<
    //     T,
    //     Container,
    //     Compare>::container_type::const_iterator const_iterator;

    bool find(const T &val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first != last)
        {
            if (*first == val)
                return true;
            ++first;
        }
        return false;
    }

    // const_iterator find(const T &val) const
    // {
    //     auto first = this->c.cbegin();
    //     auto last = this->c.cend();
    //     while (first != last)
    //     {
    //         if (*first == val)
    //             return first;
    //         ++first;
    //     }
    //     return last;
    // }
};

using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;
using AQueue = PriorityQueue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>>;
using ACost = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;
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
    Direction operator()(SimpleMaze maze, int ghost_i, int ghost_j, int target_i, int target_j);

private:
    int pathFinderAStar(SimpleMaze maze, std::pair<int, int> ghost_position, std::pair<int, int> target_position);

    int recreatePath(std::pair<int, int> current);

    /**
     * \brief Compute euclidian distance between two positions
     *
     * \param position_1 First position
     * \param position_2 Second position
     * \return int Euclidian distance between position_1 and position_2
     */
    int distance(std::pair<int, int> position_1, std::pair<int, int> position_2);
};

#endif