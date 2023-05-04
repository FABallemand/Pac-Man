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

#define MAX_PATH_LENGTH 999999

/**
 * \class Queue
 *
 * \brief queue (std::queue) with find method.
 *
 * \remark Inspired by: https://stackoverflow.com/questions/16749723/how-i-can-find-value-in-priority-queue
 *
 * \tparam T
 * \tparam Container
 */
// template <
//     class T,
//     class Container = std::vector<T>
//     >
// class Queue : public std::queue<T, Container>
// {
// public:
//     /**
//      * \brief Indicate if a value is in the queue
//      *
//      * \param val Value to look for in the queue
//      * \return true If the value is in the queue
//      * \return false If the value is not in the queue
//      */
//     bool find(const T &val) const
//     {
//         auto first = this->c.cbegin();
//         auto last = this->c.cend();
//         while (first != last)
//         {
//             if (*first == val)
//                 return true;
//             ++first;
//         }
//         return false;
//     }
// };

/**
 * \class PriorityQueue
 *
 * \brief Priority queue (std::priority_queue) with find method.
 *
 * \remark Inspired by: https://stackoverflow.com/questions/16749723/how-i-can-find-value-in-priority-queue
 *
 * \tparam T
 * \tparam Container
 * \tparam std::less<typename Container::value_type>
 */
template <
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
    >
class PriorityQueue : public std::priority_queue<T, Container, Compare>
{
public:
    /**
     * \brief Indicate if a value is in the queue
     *
     * \param val Value to look for in the queue
     * \return true If the value is in the queue
     * \return false If the value is not in the queue
     */
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
};

using SimpleMaze = std::array<std::array<int, gconst::game::nb_columns>, gconst::game::nb_rows>;
using APriorityQueue = PriorityQueue<std::pair<float, std::pair<int, int>>, std::vector<std::pair<float, std::pair<int, int>>>, std::greater<std::pair<float, std::pair<int, int>>>>;
// using AQueue = Queue<std::pair<int, int>, std::vector<std::pair<int, int>>>;
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
    Direction bestDirection(std::pair<int, int> ghost_position, ACost &cost);

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