#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

class Game; // Forward declaration

class Gomme : public Eatable
{
public:
    Gomme() : Eatable{} {}

    Gomme(int x, int y) : Eatable{GOMME, x, y, GOMME_SIZE, GOMME_SIZE, GOMME_SCORE, &sprite_gomme_}
    {
        ++nb_gommes_;
    }

    ~Gomme()
    {
        --nb_gommes_;
    }

    int getNbGommes() const
    {
        return nb_gommes_;
    }

    bool getEaten()
    {
        return eaten_;
    }

    void eaten()
    {
        eaten_ = true;
    }

    void effect(Game &game);

private:
    static SDL_Rect sprite_gomme_;
    bool eaten_ = false;

public:
    static int nb_gommes_;
};

#endif