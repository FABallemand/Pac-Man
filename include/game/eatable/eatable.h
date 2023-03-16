#ifndef __EATABLE_H__
#define __EATABLE_H__

#include "object.h"

class Game; // Forward declaration

/**
 * \enum EatableState
 * \brief Describe the state of an eatable object
 *
 */
enum EatableState
{
    PRESENT,
    EATEN
};

class Eatable : public Object
{
protected:
    Eatable() : Object{} {}

    Eatable(ObjectType type, int x, int y, int w, int h, int score, SDL_Rect *sprite) : Object{type, x, y, w, h, sprite}, score_{score}
    {
    }

public:
    virtual ~Eatable()
    {
    }

    void fillEatable(ObjectType object_type, int x, int y, int w, int h, int score, SDL_Rect *sprite)
    {
        fillObject(object_type, x, y, w, h, sprite);
        score_ = score;
    }

    EatableState getState() const
    {
        return state_;
    }

    int getScore() const
    {
        return score_;
    }

    void setState(const EatableState state)
    {
        LOG(DEBUG) << "Gomme::setState";
        state_ = state;
    }

public:
    /**
     * \brief Effect of the object when eaten
     *
     * \param game The game
     */
    virtual void effect(Game &game) = 0;

protected:
    EatableState state_ = PRESENT; //!< State of the object (TEMPLATE??)
    int score_;                    //!< Reward score when eaten
};

#endif