#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "eatable.h"
#include <array>

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
    Fruit(int x, int y, FruitType fruit_type) : Eatable{FRUIT, x, y, gconst::object::eatable::fruit::size, gconst::object::eatable::fruit::size, nullptr, [fruit_type](int score) -> int
                                                        { return score + gconst::object::eatable::fruit::score[fruit_type]; }},
                                                fruit_type_{fruit_type}
    {
    }

private:
    FruitType fruit_type_;                                       //!< Fruit type
    static std::array<std::array<SDL_Rect, 2>, 8> fruit_sprite_; //!< Fruit sprites (one sprite per type of fruit)
};

#endif