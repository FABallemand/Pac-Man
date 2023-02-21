#ifndef __EATABLE_H__
#define __EATABLE_H__

#include "object.h"

class Eatable : public Object
{
protected:
    Eatable(int x, int y, std::string &texture_path, Window &window, int score) : Object{x, y, NONE, texture_path, window}, score_{score}
    {
    }

    int score_; //!< Reward score when eaten
};

#endif