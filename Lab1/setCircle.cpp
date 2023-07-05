#include"setCirlcle.h"
//´ø¿òÔ²Àà

    setCircle::setCircle() {}
    setCircle::setCircle(int x_, int y_, int r_, setColor c) :x{ x_ }, y{ y_ }, radius{ r_ }, circle_color{ c } {
        setlinestyle(NULL_LINE);
        pieslice(x_, y_, 0, 0, r_);
        setlinestyle(SOLID_LINE);
        circle(x_, y_, r_);

    }

    void setCircle::setX(int x) { this->x = x; }
    void setCircle::setY(int y) { this->y = y; }
    void setCircle::setRadius(int radius) { this->radius = radius; }
    int setCircle::getX() { return x; }
    int setCircle::getY() { return y; }
    int setCircle::getRadius() { return radius; }
    string setCircle::getCircleInfo() {
        return "X is:" + std::to_string(x) + " Y is:" + std::to_string(y) + " R is:" + std::to_string(radius) + '\n';
    }
    string setCircle::getCircleColor() {
        return getCircleInfo() + circle_color.getAllColor();
    }
