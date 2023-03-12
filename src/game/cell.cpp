#include "cell.h"

Object *Cell::containObject(ObjectType type)
{
    for (Object *object : objects_)
    {
        if (object->getType() == type)
        {
            return object;
        }
    }
    return nullptr;
}

void Cell::deleteEatable()
{
}

void Cell::deleteGhost()
{
}

void Cell::deletePacMan(PacMan *toDelete)
{
    auto f = std::find(objects_.begin(), objects_.end(), toDelete);
    if (f == objects_.end())
    {
        LOG(ERROR) << "PACMAN NOT FOUND";
    }
    else
    {
        objects_.erase(f);
    }
}

// void Cell::update()
// {
//     Object *pacman = nullptr;
//     if (pacman = containObject(PACMAN))
//     {
//         // LOG(DEBUG) << "CELL (" << position_.x << "," << position_.y << ") contains PacMan";

//         Object *eatable = nullptr;

//         // std::vector<ObjectType> eatable_types{GOMME, SUPER_GOMME, FRUIT};
//         // for (ObjectType eatable_type : eatable_types)
//         // {
//         //     if (eatable = containObject(eatable_type))
//         //     {
//         //     }
//         // }

//         // if (eatable = containObject(GOMME))
//         // {
//         //     // objects_.erase(eatable);
//         //     ((Gomme *)eatable)->~Gomme();
//         // }
//         // if (eatable = containObject(GOMME))
//         // {
//         //     ((SuperGomme *)eatable)->~SuperGomme();
//         // }
//         // if (eatable = containObject(GOMME))
//         // {
//         // }

//         int i = 0;
//         for (std::vector<Object *>::iterator it = objects_.begin(); it != objects_.end(); ++it)
//         {
//             Object *eatable = objects_[i];
//             ObjectType object_type = eatable->getType();
//             if (object_type == GOMME)
//             {
//                 LOG(DEBUG) << "EATING A GOMME!!";
//                 objects_.erase(it);
//                 ((Gomme *)eatable)->~Gomme();
//                 break;
//             }
//             else if (object_type == SUPER_GOMME)
//             {
//                 objects_.erase(it);
//                 ((SuperGomme *)eatable)->~SuperGomme();
//                 break;
//             }
//             else if (object_type == FRUIT)
//             {
//                 objects_.erase(it);
//                 ((Fruit *)eatable)->~Fruit();
//                 break;
//             }
//             ++i;
//         }
//     }
// }