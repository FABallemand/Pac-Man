#include "gomme.h"

int Gomme::nb_gommes_ = 0;
SDL_Rect Gomme::sprite_gomme_ = SDL_Rect{3, 80, gconst::object::eatable::gomme::size_s, gconst::object::eatable::gomme::size_s};