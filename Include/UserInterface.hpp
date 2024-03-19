#pragma once

#include "Widget.hpp"
#include <vector>

class UserInterface
{
public:
    UserInterface() = default;
    ~UserInterface() = default;

    void Draw() const;

    template<typename T, std::enable_if_t<std::is_base_of_v<Widget, T>, bool> = true>
    void AddWidget(const T* widget)
    {
        _widgets.push_back(static_cast<const Widget*>(widget));
    }

private:
    std::vector<const Widget*> _widgets;
};