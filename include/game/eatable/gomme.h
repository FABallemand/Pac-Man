#ifndef __GOMME_H__
#define __GOMME_H__

#include "eatable.h"

/**
 * \brief Type of gomme
 *
 */
enum GommeType
{
    BASIC,
    ENERGIZER
};

class Gomme : public Eatable
{
public:
    Gomme(int x, int y, std::string &texture_path, Window &window, int score) : Eatable(x, y, texture_path, window, score)
    {
    }

private:
    GommeType type_; // Redondant with score ??
};

#endif