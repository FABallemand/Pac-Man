#ifndef __BLINKY_H__
#define __BLINKY_H__

#include "ghost.h"

class Blinky : public Ghost
{
public:
    Blinky();
protected:
    Direction chase(std::pair<int,int> target_position, Direction target_direction) override;
};

#endif