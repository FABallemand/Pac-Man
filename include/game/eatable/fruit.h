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
    KEY,
    BELL
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
    FruitType fruit_type_; //!< Fruit type
};

#endif