#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Eatable
{
public:
    SuperGomme(int x, int y) : Eatable{SUPER_GOMME, x, y, SUPER_GOMME_SIZE, SUPER_GOMME_SIZE, SUPER_GOMME_SCORE, &sprite_super_gomme_}
    {
    }

    ~SuperGomme()
    {
    }

    void effect(Game &game);

protected:
    static SDL_Rect sprite_super_gomme_; // Why here ?
};

#endif