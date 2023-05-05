#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Eatable<int>
{
public:
    static int nb_super_gommes_;

    SuperGomme() : Eatable{}
    {
    }

    SuperGomme(int x, int y) : Eatable{SUPER_GOMME, x, y, gconst::object::eatable::super_gomme::size, gconst::object::eatable::super_gomme::size, &sprite_super_gomme_, [](int score) -> int
                                            { return score + gconst::object::eatable::super_gomme::score; }}
    {
    }

    ~SuperGomme()
    {
    }

    void fillSuperGomme(int i, int j)
    {
        fillEatable(SUPER_GOMME, j * gconst::object::cell::size + gconst::object::eatable::super_gomme::super_gomme_offset, i * gconst::object::cell::size + gconst::object::eatable::super_gomme::super_gomme_offset, gconst::object::eatable::super_gomme::size, gconst::object::eatable::super_gomme::size, gconst::object::eatable::super_gomme::score, &sprite_super_gomme_, [](int score) -> int
                    { return score + gconst::object::eatable::super_gomme::score; });
    }

protected:
    // Sprites ================================================================
    static SDL_Rect sprite_super_gomme_; //!< Sprites
};

#endif