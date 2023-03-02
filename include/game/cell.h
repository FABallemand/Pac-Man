#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>
#include <typeinfo> // Maybe useless

#include "const.h"
#include "display_utils.h"
#include "object.h"

// Eatable
#include "gomme.h"
#include "super_gomme.h"
#include "fruit.h"

/**
 * \brief Type of cell
 *
 */
enum CellType
{
    CLEAR,
    WALL,
    GHOST_WALL
};

class Cell : public Object
{
public:
    Cell() : type_{CLEAR}, objects_{}
    {
        position_.w = CELLSIZE;
        position_.h = CELLSIZE;
    }

    Cell(std::vector<Object *> objects) : type_{CLEAR}, objects_{objects}
    {
    }

    Cell(CellType type) : type_{type}, objects_{}
    {
    }

    CellType getCelltype() const
    {
        return type_;
    }

    std::vector<Object *> &getObjects()
    {
        return objects_;
    }

    /**
     * \brief Add a new object in the cell
     *
     * \param object Pointer to the object entering th cell
     */
    void addObject(Object *object);

    // TO BE TESTED...
    template <typename T>
    bool containObject()
    {
        for (Object *object : objects_)
        {
            if (typeid(object) == typeid(T))
            {
                return true;
            }
        }
        return false;
    }

    bool containGomme();

    bool containSuperGomme();

    bool containFruit();

    bool containGhost();

    bool containPacMan();

    /**
     * \brief
     *
     */
    void deleteEatable();

    /**
     * \brief
     *
     */
    void deleteGhost();

    /**
     * \brief Display each object in the cell
     *
     */
    void display(SDL_Surface *sprite, SDL_Surface *window_surface) const;

private:
    CellType type_;                 //!< Type of the cell
    std::vector<Object *> objects_; //!< Objects currently in the cell
};

#endif