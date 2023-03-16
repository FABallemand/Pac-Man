#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme() : Eatable{}
    {
    }

    Gomme(int x, int y) : Eatable{GOMME, x, y, GOMME_SIZE, GOMME_SIZE, GOMME_SCORE, &sprite_gomme_}
    {
        ++nb_gommes_;
    }

    ~Gomme()
    {
        --nb_gommes_;
    }

    void fillGomme(int i, int j)
    {
        fillEatable(GOMME, j * CELL_SIZE + gomme_offset_, i * CELL_SIZE + gomme_offset_, GOMME_SIZE, GOMME_SIZE, GOMME_SCORE, &sprite_gomme_);
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;

public:
    static int nb_gommes_;
    static constexpr int gomme_offset_ = (CELL_SIZE - GOMME_SIZE) / 2;
    
};

#endif