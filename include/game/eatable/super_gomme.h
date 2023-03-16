#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Eatable
{
public:
    SuperGomme() : Eatable{}
    {
    }

    SuperGomme(int x, int y) : Eatable{SUPER_GOMME, x, y, SUPER_GOMME_SIZE, SUPER_GOMME_SIZE, SUPER_GOMME_SCORE, &sprite_super_gomme_}
    {
    }

    ~SuperGomme()
    {
    }

    void fillSuperGomme(int i, int j)
    {
        fillEatable(SUPER_GOMME, j * CELL_SIZE + super_gomme_offset_, i * CELL_SIZE + super_gomme_offset_, GOMME_SIZE, GOMME_SIZE, GOMME_SCORE, &sprite_super_gomme_);
    }

    void effect(Game &game);

protected:
    static SDL_Rect sprite_super_gomme_;

public:
    static int nb_super_gommes_;
    static constexpr int super_gomme_offset_ = (CELL_SIZE - SUPER_GOMME_SIZE) / 2;
};

#endif