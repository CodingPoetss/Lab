#pragma once
#pragma once
//µ„¿‡
class Dot {
private:
    int x{ 0 };
    int y{ 0 };
public:
    Dot();
    Dot(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void getCoordinate();
};