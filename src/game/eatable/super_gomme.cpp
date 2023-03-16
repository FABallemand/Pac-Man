#include "super_gomme.h"

int SuperGomme::nb_super_gommes_ = 0;
SDL_Rect SuperGomme::sprite_super_gomme_ = SDL_Rect{8, 78, S_SUPER_GOMME_SIZE, S_SUPER_GOMME_SIZE};

void SuperGomme::effect(Game &game)
{
    LOG(DEBUG) << "SuperGomme::effect";
}