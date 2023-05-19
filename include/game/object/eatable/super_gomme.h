#ifndef __SUPER_GOMME_H__
#define __SUPER_GOMME_H__

#include "gomme.h"

class SuperGomme : public Eatable<int>
{
public:
    static int nb_super_gommes_;

    SuperGomme() : Eatable{}
    {
    }

    SuperGomme(int x, int y) : Eatable{SUPER_GOMME, x, y, gconst::game::object::eatable::super_gomme::size, gconst::game::object::eatable::super_gomme::size, &sprite_super_gomme_[0], [](int score) -> int
                                       { return score + gconst::game::object::eatable::super_gomme::score; }}
    {
    }

    /**
     * \brief Fill attributes of a SuperGomme object
     * 
     * \param i Row index
     * \param j Column index
     */
    void fillSuperGomme(int i, int j);

    /**
     * \brief Update sprite to display
     *
     */
    void updateSprite();

protected:
    // Sprites ================================================================
    static std::array<SDL_Rect,2> sprite_super_gomme_; //!< Sprites
    int frame_count_ = 0;          //!< Frame count
    int sprite_count_ = 0;         //!< Sprite count (for animation)

};

#endif