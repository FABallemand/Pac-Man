#ifndef __EATABLE_H__
#define __EATABLE_H__

#include <SDL.h>

#include "game.h"
#include "object.h"

class Game; // Forward declaration

class Eatable : public Object
{
protected:
    Eatable(int x, int y, int score) : Object{x, y}, score_{score}
    {
    }

    virtual ~Eatable()
    {
    }

public:
    /**
     * \brief Effect of the object when eaten
     *
     * \param game The game
     */
    virtual void effect(Game &game) = 0;

    void display() const;

protected:
    int score_;       //!< Reward score when eaten
    SDL_Rect sprite_; //!< Sprite location
};

#endif