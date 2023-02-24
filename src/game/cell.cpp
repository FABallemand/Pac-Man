#include "cell.h"

void Cell::addObject(Object *object)
{
    objects_.push_back(object);
}

bool Cell::containGomme()
{
    for (Object *object : objects_)
    {
        if (typeid(object) == typeid(Gomme *))
        {
            return true;
        }
    }
    return false;
}

bool Cell::containSuperGomme()
{
}

bool Cell::containFruit()
{
}

bool Cell::containGhost()
{
}

bool Cell::containPacMan()
{
}

void Cell::deleteEatable()
{
}

void Cell::deleteGhost()
{
}

void Cell::display() const
{
    for (Object *object : objects_)
    {
        object->display();
    }
}