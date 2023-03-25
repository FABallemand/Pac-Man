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

    Gomme(int x, int y) : Eatable{GOMME, x, y, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::score, &sprite_gomme_}
    {
        ++nb_gommes_;
    }

    ~Gomme()
    {
        --nb_gommes_;
    }

    void fillGomme(int i, int j)
    {
        fillEatable(GOMME, j * gconst::object::cell::size + gomme_offset_, i * gconst::object::cell::size + gomme_offset_, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::size, gconst::object::eatable::gomme::score, &sprite_gomme_);
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;

public:
    static int nb_gommes_;
    static constexpr int gomme_offset_ = (gconst::object::cell::size - gconst::object::eatable::gomme::size) / 2;
    
};

#endif