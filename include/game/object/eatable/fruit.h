#ifndef __FRUIT_H__
#define __FRUIT_H__

#include <array>

#include "eatable.h"
#include "timer.h"

class Game; // Forward declaration

/**
 * \enum FruitType
 * \brief Type of fruit
 *
 */
enum FruitType
{
    FRUIT_NONE,
    FRUIT_CHERRY,
    FRUIT_STRAWBERRY,
    FRUIT_ORANGE,
    FRUIT_APPLE,
    FRUIT_MELON,
    FRUIT_STICK_OF_FIRE,
    FRUIT_BELL,
    FRUIT_KEY
};

class Fruit : public Eatable<std::pair<int, int>>
{
public:
    Fruit() : Eatable<std::pair<int, int>>{
                  FRUIT, gconst::game::object::eatable::fruit::j * gconst::game::object::cell::size, gconst::game::object::eatable::fruit::i * gconst::game::object::cell::size, gconst::game::object::eatable::fruit::size, gconst::game::object::eatable::fruit::size, nullptr, [](std::pair<int, int> params) -> int
                  {
                      return params.first + gconst::game::object::eatable::fruit::score[params.second];
                  }}
    {
    }

    void setFruitType(FruitType fruit_type);

    FruitType getFruitType() const
    {
        return fruit_type_;
    }

    void update();

private:
    // State ==================================================================
    FruitType fruit_type_ = FRUIT_NONE; //!< Fruit type
    Timer despawn_timer_{};             //!< Timer before the fruit disappear
    // Sprites ================================================================
    static std::array<std::array<SDL_Rect, 2>, 8> fruit_sprite_; //!< Fruit sprites (one sprite per type of fruit)
};

#endif