#include "super_gomme.h"

int SuperGomme::nb_super_gommes_ = 0;
SDL_Rect SuperGomme::sprite_super_gomme_ = SDL_Rect{8, 78, gconst::object::eatable::super_gomme::size_s, gconst::object::eatable::super_gomme::size_s};