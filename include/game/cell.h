#ifndef __CELL_H__
#define __CELL_H__

#include <SDL.h>
#include <vector>
#include <memory> // Maybe useless

#include "const.h"
#include "logger.h"
#include "object.h"

// Moveable
#include "pac_man.h"
#include "ghost.h"

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
    EMPTY,
    WALL,
    GHOST_WALL
};

class Cell : public Object
{
public:
    Cell() {} // Used by Board type

    Cell(int i, int j) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, cell_type_{EMPTY}, objects_{}
    {
    }

    Cell(int i, int j, std::vector<Object *> objects) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, cell_type_{EMPTY}, objects_{objects}
    {
    }

    Cell(int i, int j, CellType type) : Object{CELL, j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, cell_type_{type}, objects_{}
    {
    }

    CellType getCelltype() const
    {
        return cell_type_;
    }

    std::vector<Object *> &getObjects()
    {
        return objects_;
    }

    std::vector<Object *> *getObjectsAdr()
    {
        return &objects_;
    }

    size_t getNbObjects() const
    {
        return objects_.size();
    }

    bool isEmpty() const
    {
        return objects_.empty();
    }

    void setObjects(std::vector<Object *> objects)
    {
        objects_ = objects;
    }

    /**
     * \brief Add a new object in the cell
     *
     * \param object Pointer to the object entering th cell
     */
    void addObject(Object *object)
    {
        objects_.emplace_back(object);
    }

    /**
     * \brief Search for objects of a given type inside the cell
     *
     * \param type Type of the object
     * \return Object* Pointer to the object of the given type (if found) or nullptr
     */
    Object *containObject(ObjectType type);

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
     * \brief
     *
     */
    void deletePacMan(PacMan *toDelete);

    bool isWall()
    {
        return (cell_type_ == WALL) || (cell_type_ == GHOST_WALL);
    }

    // void update();

private:
    CellType cell_type_;            //!< Type of the cell
    std::vector<Object *> objects_; //!< Objects currently in the cell (change type for moveable??)
public:
    Eatable *eatable = nullptr; // Test
};

#endif