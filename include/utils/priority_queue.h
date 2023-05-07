#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <queue>
#include <vector>

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
    class Compare = std::less<typename Container::value_type>>
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

#endif