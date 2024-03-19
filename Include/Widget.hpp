#pragma once

class Widget
{
public:
    virtual void Draw() const = 0;

    void SetPosX(int x) { _posX = x; }
    [[nodiscard]] int GetPosX() const { return _posX; }
    void SetPosY(int y) { _posY = y; }
    [[nodiscard]] int GetPosY() const { return _posY; }
    void SetPos(int x, int y) { _posX = x; _posY = y; }
    void GetPos(int& x, int& y) const { x = _posX; y = _posY; }

    [[nodiscard]] virtual int GetHeight() const = 0;
    [[nodiscard]] virtual int GetWidth() const = 0;

protected:
    int _posX = 0;
    int _posY = 0;
};