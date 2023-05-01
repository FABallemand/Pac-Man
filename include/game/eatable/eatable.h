#ifndef __EATABLE_H__
#define __EATABLE_H__

#include <functional>

#include "object.h"

class Game; // Forward declaration

/**
 * \enum EatableState
 * \brief Describe the state of an eatable object
 *
 */
enum EatableState
{
    EATABLE_DEFAULT,
    EATABLE_EATEN
};

class Eatable : public Object
{
protected:
    Eatable() : Object{} {}

    Eatable(ObjectType type, int x, int y, int w, int h, int score, SDL_Rect *sprite, std::function<int(int)> effect) : Object{type, x, y, w, h, sprite}, score_{score}, effect_{effect}
    {
    }

public:
    virtual ~Eatable()
    {
    }

    void fillEatable(ObjectType object_type, int x, int y, int w, int h, int score, SDL_Rect *sprite, std::function<int(int)> effect)
    {
        fillObject(object_type, x, y, w, h, sprite);
        score_ = score;
        effect_ = effect;
    }

    EatableState getState() const
    {
        return state_;
    }

    int getScore() const
    {
        return score_;
    }

    std::function<int(int)> getEffect() const
    {
        return effect_;
    }

    void setState(const EatableState state)
    {
        state_ = state;
    }

public:
    /**
     * \brief Effect of the object when eaten
     *
     * \param game The game
     */
    // virtual void effect(Game &game) = 0;

protected:
    EatableState state_ = EATABLE_DEFAULT; //!< State of the object (TEMPLATE??)
    int score_;                            //!< Reward score when eaten (USELESS -> lambda ??)
    std::function<int(int)> effect_;       //!< Effect
};

#endif