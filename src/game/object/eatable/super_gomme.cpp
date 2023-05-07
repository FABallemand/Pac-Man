#include "super_gomme.h"

int SuperGomme::nb_super_gommes_ = 0;
std::array<SDL_Rect,2> SuperGomme::sprite_super_gomme_ = {{SDL_Rect{8, 78, gconst::game::object::eatable::super_gomme::size_s, gconst::game::object::eatable::super_gomme::size_s},
                                                           SDL_Rect{500, 300, gconst::game::object::eatable::super_gomme::size_s, gconst::game::object::eatable::super_gomme::size_s}}};

void SuperGomme::updateSprite()
{
    if (++frame_count_ == gconst::game::object::moveable::nb_sprite_frame*3)
    {
        frame_count_ = 0;
        sprite_count_ = (++sprite_count_) % 2;
    }
    current_sprite_ = &(sprite_super_gomme_[sprite_count_]);
}