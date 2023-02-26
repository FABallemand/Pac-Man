#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme(int x, int y, int score) : Eatable(x, y, score)
    {
        LOG(DEBUG) << "Gomme:Gomme";
    }

    // Gomme(int x, int y, int score)
    // {
    //     position_{x, y, 0, 0};
    //     score_{score};
    // }

    ~Gomme()
    {
    }

    void effect(Game &game);
};

#endif