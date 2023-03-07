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

    // Gomme(int x, int y, bool super_gomme = false) : super_gomme ? Eatable{x, y, super_gomme ? SUPER_GOMME_W : GOMME_W, super_gomme ? SUPER_GOMME_H : GOMME_H, super_gomme ? SUPER_GOMME_SCORE : GOMME_SCORE, super_gomme ? SDL_Rect{8, 78, 9, 9} : SDL_Rect{3, 80, 3, 3}}
    //                                                             : Eatable{x, y, super_gomme ? SUPER_GOMME_W : GOMME_W, super_gomme ? SUPER_GOMME_H : GOMME_H, super_gomme ? SUPER_GOMME_SCORE : GOMME_SCORE, super_gomme ? SDL_Rect{8, 78, 9, 9} : SDL_Rect{3, 80, 3, 3}}
    // {
    // }

    ~Gomme()
    {
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;
    static SDL_Rect sprite_super_gomme_;
};

#endif