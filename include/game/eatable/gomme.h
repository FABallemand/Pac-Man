#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Gomme : public Eatable
{
public:
    Gomme(int x, int y, int score) : Eatable(x, y, score)
    {
    }

private:
    void effect(Game &game);
};

#endif