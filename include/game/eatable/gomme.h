#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme(int x, int y, int score) : Eatable{x, y, score}
    {
        LOG(DEBUG) << "Gomme:Gomme";
    }

    ~Gomme()
    {
    }

    void effect(Game &game);
protected:
    SDL_Rect sprite = SDL_Rect{3,80,4,4};
};

#endif