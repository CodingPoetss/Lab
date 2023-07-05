#include"setTriangle.h"
//三角形类

setTriangle::setTriangle() {}
setTriangle::setTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
    COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff) :dot1{ x1,y1 },dot2{ x2,y2 }, dot3{ x3,y3 } {
    color->setFrameColor(frame);
    color->setBackgroundColor(background);
    color->setWordsColor(words);
    color->setFilledColor(filled);
    color->setStuff(stuff);
    ExistingTriangleNumber++;
}
setTriangle::setTriangle(const setTriangle& triangle) {
    dot1 =triangle.dot1;
    dot2 = triangle.dot2;
    dot3 = triangle.dot3;
    color = new setColor{ *(triangle.color) };
    ExistingTriangleNumber++;
}
setTriangle::~setTriangle() {
    delete  color;
    ExistingTriangleNumber--;
    xyprintf(600, 0, "Now existing circle(s):%d", ExistingTriangleNumber);
}

void setTriangle::draw() {
    //清屏
    setbkcolor(color->getBackgroundColor());
    cleardevice();

    setbkcolor(color->getBackgroundColor());
    setfontbkcolor(color->getWordsColor());
    if (color->getStuff()) {
        setfillcolor(color->getFilledColor());
    }
    else {
        setfillcolor(color->getBackgroundColor());
    }
    
    auto line1 = new setLine{ {dot1.getX(),dot1.getY()},{dot2.getX(),dot2.getY()} };
    auto line2 = new setLine{ {dot2.getX(),dot2.getY()},{dot3.getX(),dot3.getY()} };
    auto line3 = new setLine{ {dot3.getX(),dot3.getY()},{dot1.getX(),dot1.getY()} };
}