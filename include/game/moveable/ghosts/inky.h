#ifndef __INKY_H__
#define __INKY_H__

#include "ghost.h"

class Inky : public Ghost
{
public:
    Inky();

protected:
    Direction chase(std::pair<int, int> target_position, Direction target_direction);
};

#endif