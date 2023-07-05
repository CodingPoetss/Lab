#include"setRectangle.h"
//带框矩形

    setRectangle::setRectangle() {}         //会创建一个临时的setColor对象并调用其构造函数
    setRectangle::setRectangle(Dot d1, Dot d2, setColor c) :dot1{ d1 }, dot2{ d2 }, rectangle_color{ c }{   
        bar(d1.getX(), d1.getY(), d2.getX(), d2.getY());
        rectangle(d1.getX(), d1.getY(), d2.getX(), d2.getY());
    }

    void setRectangle::setDot1(Dot d1) { dot1 = d1; }
    void setRectangle::setDot2(Dot d2) { dot2 = d2; }
    Dot setRectangle::getDot1() { return dot1; }
    Dot setRectangle::getDot2() { return dot2; }

