#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme(int x, int y, bool super_gomme = false) : Eatable{x, y, super_gomme ? SUPER_GOMME_SIZE : GOMME_SIZE, super_gomme ? SUPER_GOMME_SIZE : GOMME_SIZE, super_gomme ? SUPER_GOMME_SCORE : GOMME_SCORE, super_gomme ? &sprite_super_gomme_ : &sprite_gomme_} // Use const
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