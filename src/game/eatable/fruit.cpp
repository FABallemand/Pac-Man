#include "fruit.h"

std::array<std::array<SDL_Rect, 2>, 8> Fruit::fruit_sprite_ = {{{SDL_Rect{288, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{288, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{304, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{304, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{320, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{320, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{336, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{336, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{352, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{352, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{369, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{369, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{385, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{385, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}},
                                                                {SDL_Rect{401, 256, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}, SDL_Rect{401, 236, gconst::object::eatable::fruit::size_s, gconst::object::eatable::fruit::size_s}}}};

void Fruit::update()
{
    if (despawn_timer_.isStarted() && despawn_timer_.getTicks() > gconst::object::eatable::fruit::time)
    {
        fruit_type_ = FRUIT_NONE;
        despawn_timer_.stop();
    }
}
