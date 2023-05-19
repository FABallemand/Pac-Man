#ifndef __INKY_H__
#define __INKY_H__

#include "ghost.h"
#include "timer.h"

/**
 * \class Inky
 *
 * \brief Blue Ghost
 *
 */
class Inky : public Ghost
{
public:
    Inky();

protected:
    long offset_i_ = scatter_position_.first;  //!< Row offset for chase strategy
    long offset_j_ = scatter_position_.second; //!< Column offset for chase strategy
    Timer chase_timer_;                        //!< Timer for chase strategy

    Direction chase(std::pair<int, int> target_position, Direction target_direction) override;
};

#endif