#include"setCircle.h"
//带框圆类

setCircle::setCircle() {}
setCircle::setCircle(int x_, int y_, int r_ ,
    COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff):x{ &x_ }, y{ &y_ }, radius{ &r_ }{
    color->setFrameColor(frame);
    color->setBackgroundColor(background);
    color->setWordsColor(words);
    color->setFilledColor(filled);
    color->setStuff(stuff);
    ExistingCircleNumber++;
    xyprintf(600, 0, "Now existing circle(s):%d", ExistingCircleNumber);
}
setCircle::setCircle(const setCircle& circle) {
    x = new int{ *(circle.x) };
    y = new int{ *(circle.y) };
    radius = new int{ *(circle.radius) };
    color = new setColor{ *(circle.color) };
    ExistingCircleNumber++;
    xyprintf(600, 0, "Now existing circle(s):%d", ExistingCircleNumber);
}

setCircle::~setCircle() {
    delete color;
    ExistingCircleNumber--;
    xyprintf(600, 0, "Now existing circle(s):%d",ExistingCircleNumber);
    
}

void setCircle::setX(int x) { this->x = &x; }
void setCircle::setY(int y) { this->y = &y; }
void setCircle::setRadius(int radius) { this->radius = &radius; }
int setCircle::getX() { return *x; }
int setCircle::getY() { return *y; }
int setCircle::getRadius() { return *radius; }
int setCircle::getExistingCircleNumber() { return ExistingCircleNumber; }
void setCircle::draw() {
    //清屏
    setbkcolor(color->getBackgroundColor());
    cleardevice();
    
    //重置颜色
    //setColor c{ RED,GREEN,BLACK,BROWN,true };
    setbkcolor(color->getBackgroundColor());
    setfontbkcolor(color->getWordsColor());
    if (color->getStuff()) {
        setfillcolor(color->getFilledColor());
    }
    else {
        setfillcolor(color->getBackgroundColor());
    }
    setlinestyle(NULL_LINE);
    pieslice(*x, *y ,0, 0, *radius);
    setcolor(color->getFrameColor());
    setlinestyle(SOLID_LINE);
    circle(*x, *y, *radius);
    //floodfill(300,300, BLACK );
    
}
