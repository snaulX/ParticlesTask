#include "VBox.hpp"

void VBox::Draw() const
{
    int posY = _posY;
    for (Widget* child : _children)
    {
        child->SetPos(_posX, posY);
        child->Draw();
        posY += child->GetHeight() + _padY;
    }
}

int VBox::GetHeight() const
{
    int height = 0;
    int len = 0;
    for (Widget* child : _children)
    {
        height += child->GetHeight() + _padY;
        len++;
    }
    return len == 0 ? 0 : height - _padY;
}

int VBox::GetWidth() const
{
    int maxWidth = 0;
    for (Widget* child : _children)
    {
        int w = child->GetWidth();
        maxWidth = w > maxWidth ? w : maxWidth;
    }
    return maxWidth;
}
