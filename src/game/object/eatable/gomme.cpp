#include "gomme.h"

int Gomme::nb_gommes_ = 0;
SDL_Rect Gomme::sprite_gomme_ = SDL_Rect{3, 80, gconst::game::object::eatable::gomme::size_s, gconst::game::object::eatable::gomme::size_s};

void Gomme::fillGomme(int i, int j)
{
    fillEatable(GOMME, j * gconst::game::object::cell::size + gconst::game::object::eatable::gomme::gomme_offset, i * gconst::game::object::cell::size + gconst::game::object::eatable::gomme::gomme_offset, gconst::game::object::eatable::gomme::size, gconst::game::object::eatable::gomme::size, &sprite_gomme_, [](int score) -> int
                { return score + gconst::game::object::eatable::gomme::score; });
}