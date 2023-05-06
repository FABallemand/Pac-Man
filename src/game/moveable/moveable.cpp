#include "moveable.h"

void Moveable::handleShortcut()
{
    // Handle x-axis position
    if (position_.x <= 0)
    {
        position_.x = gconst::window::w - 1;
    }
    else if (position_.x >= gconst::window::w)
    {
        position_.x = 0;
    }

    // Fix dimensions
    fixDimensions();
}