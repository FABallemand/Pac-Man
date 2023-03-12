#ifndef __EATABLE_H__
#define __EATABLE_H__

#include "object.h"

class Game; // Forward declaration

class Eatable : public Object
{
protected:
    Eatable(ObjectType type, int x, int y, int w, int h, int score, SDL_Rect *sprite) : Object{type, x, y, w, h, sprite}, score_{score}
    {
    }

    virtual ~Eatable()
    {
    }

    int getScore()
    {
        return score_;
    }

public:
    /**
     * \brief Effect of the object when eaten
     *
     * \param game The game
     */
    virtual void effect(Game &game) = 0;

protected:
    int score_; //!< Reward score when eaten
};

#endif