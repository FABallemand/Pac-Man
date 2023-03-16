#include "gomme.h"

SDL_Rect Gomme::sprite_gomme_ = SDL_Rect{3, 80, S_GOMME_SIZE, S_GOMME_SIZE};

void Gomme::effect(Game &game)
{
    LOG(ERROR) << "Gomme::effect";
    // game.incGameScore(); // WHYYYYYYYYYYYYYYYYYYY
}