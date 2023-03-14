#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme(ObjectType type, int x, int y) : Eatable{type, x, y, type == SUPER_GOMME ? SUPER_GOMME_SIZE : GOMME_SIZE, type == SUPER_GOMME ? SUPER_GOMME_SIZE : GOMME_SIZE, type == SUPER_GOMME ? SUPER_GOMME_SCORE : GOMME_SCORE, type == SUPER_GOMME ? &sprite_super_gomme_ : &sprite_gomme_}
    {
    }

    ~Gomme()
    {
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;
    static SDL_Rect sprite_super_gomme_; // Why here ?
};

#endif