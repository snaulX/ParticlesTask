#pragma once

#include "Widget.hpp"
#include <vector>

class VBox : public Widget
{
public:
    VBox() = default;
    ~VBox() = default;

    template<typename T, std::enable_if_t<std::is_base_of_v<Widget, T>, bool> = true>
    void AddChild(T* widget)
    {
        _children.push_back(static_cast<Widget*>(widget));
    }

    void Draw() const override;

    void SetPadY(int y) { _padY = y; }
    [[nodiscard]] int GetPadY() const { return _padY; }

    [[nodiscard]] int GetHeight() const override;
    [[nodiscard]] int GetWidth() const override;

private:
    int _padY = 10;
    std::vector<Widget*> _children;
};