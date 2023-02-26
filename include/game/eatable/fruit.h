#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "eatable.h"
#include "game.h"

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
    void effect(Game &game);

private:
    FruitType type_; //!< Fruit type
};

#endif