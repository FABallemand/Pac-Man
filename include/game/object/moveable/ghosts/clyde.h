#ifndef __CLYDE_H__
#define __CLYDE_H__

#include "ghost.h"

/**
 * \class Clyde
 * 
 * \brief Orange Ghost
 * 
 */
class Clyde : public Ghost
{
public:
    Clyde();

protected:
    Direction chase(std::pair<int, int> target_position, Direction target_direction) override;
};

#endif