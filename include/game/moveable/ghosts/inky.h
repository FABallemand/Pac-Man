#ifndef __INKY_H__
#define __INKY_H__

#include "ghost.h"

class Inky : public Ghost
{
public:
    Inky();

    void strategy();
};

#endif