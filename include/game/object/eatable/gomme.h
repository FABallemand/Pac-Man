#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable<int>
{
public:
    static int nb_gommes_;

    Gomme() : Eatable{}
    {
    }

    Gomme(int x, int y) : Eatable{GOMME, x, y, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::size, &sprite_gomme_, [](int score) -> int
                                  { return score + gconst::object::eatable::gomme::score; }}
    {
    }

    ~Gomme()
    {
    }

    void fillGomme(int i, int j)
    {
        fillEatable(GOMME, j * gconst::object::cell::size + gconst::object::eatable::gomme::gomme_offset, i * gconst::object::cell::size + gconst::object::eatable::gomme::gomme_offset, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::size, &sprite_gomme_, [](int score) -> int
                    { return score + gconst::object::eatable::gomme::score; });
    }

private:
    // Sprites ================================================================
    static SDL_Rect sprite_gomme_; //!< Sprites
};

#endif