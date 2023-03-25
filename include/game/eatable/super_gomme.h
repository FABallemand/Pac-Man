#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Eatable
{
public:
    SuperGomme() : Eatable{}
    {
    }

    SuperGomme(int x, int y) : Eatable{SUPER_GOMME, x, y, gconst::object::eatable::super_gomme::size, gconst::object::eatable::super_gomme::size, gconst::object::eatable::super_gomme::score, &sprite_super_gomme_, [](int score) -> int
                                       { return score + gconst::object::eatable::super_gomme::score; }}
    {
    }

    ~SuperGomme()
    {
    }

    void fillSuperGomme(int i, int j)
    {
        fillEatable(SUPER_GOMME, j * gconst::object::cell::size + super_gomme_offset_, i * gconst::object::cell::size + super_gomme_offset_, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::score, &sprite_super_gomme_, [](int score) -> int
                    { return score + gconst::object::eatable::super_gomme::score; });
    }

protected:
    static SDL_Rect sprite_super_gomme_;

public:
    static int nb_super_gommes_;
    static constexpr int super_gomme_offset_ = (gconst::object::cell::size - gconst::object::eatable::super_gomme::size) / 2;
};

#endif