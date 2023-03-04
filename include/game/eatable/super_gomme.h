#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Gomme
{
public:
    SuperGomme(int x, int y) : Gomme(x, y, true)
    {
    }

    void effect(Game &game);

protected:
};

#endif