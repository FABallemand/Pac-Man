#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "eatable.h"

class Game; // Forward declaration

enum FruitType
{
    CHERRY,
    STRAWBERRY,
    ORANGE,
    APPLE,
    MELON,
    STICK_OF_FIRE,
    BELL,
    KEY
};

class Fruit : public Eatable
{
public:
    Fruit(int x, int y, FruitType fruit_type) : Eatable{FRUIT, x, y, gconst::object::eatable::fruit::size, gconst::object::eatable::fruit::size, nullptr, [](int score) -> int
                                                        { return score + gconst::object::eatable::fruit::score; }},
                                                fruit_type_{fruit_type}
    {
    }

private:
    std::array<std::array<SDL_Rect,2>8> fruit_sprite_ = {{{SDL_Rect{288,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{288,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{304,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{304,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{320,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{320,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{336,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{336,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{352,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{352,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{369,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{369,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{385,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{385,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }},
                                                          {SDL_Rect{401,236 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }, SDL_Rect{401,256 ,gconst::object::eatable::fruit::size_s ,gconst::object::eatable::fruit::size_s }}}};

    FruitType fruit_type_; //!< Fruit type
};

#endif