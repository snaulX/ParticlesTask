#include "Label.hpp"

Label::Label(const char* text, int fontSize, Color color) :
    _text(text), _fontSize(fontSize), _color(color) {}

void Label::Draw() const
{
    DrawText(_text.c_str(), _posX, _posY, _fontSize, _color);
}

int Label::GetHeight() const
{
    // NOTE: Assume that Label is single-lined
    return _fontSize;
}

int Label::GetWidth() const
{
    return _text.length() * _fontSize;
}
