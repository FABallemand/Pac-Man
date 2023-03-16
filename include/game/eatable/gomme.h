#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme(int x, int y) : Eatable{GOMME, x, y, GOMME_SIZE, GOMME_SIZE, GOMME_SCORE, &sprite_gomme_}
    {
    }

    ~Gomme()
    {
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;
};

#endif