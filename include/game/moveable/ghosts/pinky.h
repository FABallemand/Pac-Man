#ifndef __PINKY_H__
#define __PINKY_H__

#include "ghost.h"

class Pinky : public Ghost
{
public:
    Pinky();

protected:
    Direction chase(std::pair<int, int> target_position, Direction target_direction);
};

#endif