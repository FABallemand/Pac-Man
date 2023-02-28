#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Gomme
{
public:
    SuperGomme(int x, int y, int score) : Gomme(x, y, score)
    {
        sprite = SDL_Rect{8,78,9,9};
    }

    void effect(Game &game);
protected:
};

#endif