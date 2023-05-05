#ifndef __INKY_H__
#define __INKY_H__

#include "ghost.h"
#include "timer.h"

class Inky : public Ghost
{
public:
    Inky();

protected:
    Direction chase(std::pair<int, int> target_position, Direction target_direction);
    long offset_i_ = scatter_position_.first;
    long offset_j_ = scatter_position_.second;
    Timer chase_timer_;
};

#endif