#include "UserInterface.hpp"

void UserInterface::Draw() const
{
    for (const Widget* widget : _widgets)
    {
        widget->Draw();
    }
}
