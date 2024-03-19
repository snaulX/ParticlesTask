#pragma once

#include "Widget.hpp"
#include "raylib.h"
#include <string>

class Label : public Widget
{
public:
    explicit Label(const char* text, int fontSize = 14, Color color = BLACK);
    ~Label() = default;

    void Draw() const override;

    void SetText(const char* text) { _text = text; }
    void SetText(std::string&& text) { _text = std::move(text); }
    [[nodiscard]] const char* GetText() const { return _text.c_str(); }
    void SetFontSize(int size) { _fontSize = size; }
    [[nodiscard]] int GetFontSize() const { return _fontSize; }
    void SetColor(Color color) { _color = color; }
    [[nodiscard]] Color GetColor() const { return _color; }

    [[nodiscard]] int GetHeight() const override;
    [[nodiscard]] int GetWidth() const override;

private:
    std::string _text;
    int _fontSize;
    Color _color;
};