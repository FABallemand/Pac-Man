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

template <typename T>
class Eatable : public Object
{
protected:
    Eatable() : Object{}
    {
    }

    Eatable(
        ObjectType type, int x, int y, int w, int h, SDL_Rect *sprite, std::function<int(T)> effect = [](T values) -> int
        { return 0; }) : Object{type, x, y, w, h, sprite}, effect_{effect}
    {
    }

public:
    virtual ~Eatable()
    {
    }

    void fillEatable(ObjectType object_type, int x, int y, int w, int h, int score, SDL_Rect *sprite, std::function<int(int)> effect)
    {
        fillObject(object_type, x, y, w, h, sprite);
        effect_ = effect;
    }

    EatableState getState() const
    {
        return state_;
    }

    std::function<int(T)> getEffect() const
    {
        return effect_;
    }

    void setState(const EatableState state)
    {
        state_ = state;
    }

protected:
    EatableState state_ = EATABLE_DEFAULT; //!< State of the object
    std::function<int(T)> effect_;         //!< Effect
};

#endif