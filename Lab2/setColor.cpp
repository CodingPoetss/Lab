#include"setColor.h"
//颜色基类(图形类都得继承)

setColor::setColor() {}
setColor::setColor(color_t f, color_t b, color_t w, color_t fil, bool s) :front{ f }, back{ b }, words{ w }, filled{ fil }, stuff{ s } {
    setcolor(f);
    setbkcolor(b);
    setfontbkcolor(w);
    if (stuff) {
        setfillcolor(fil);
    }
    else {
        setfillcolor(back);
    }
}
setColor::setColor(COLORS f, COLORS b, COLORS w, COLORS fil, bool s) : setColor(static_cast<color_t>(f), static_cast<color_t>(b),      //代理构造
    static_cast<color_t>(w), static_cast<color_t>(fil), s) {}


void setColor::setFrameColor(COLORS f) {
    front = static_cast<color_t>(f);
    setcolor(f);
}
void setColor::setBackgroundColor(COLORS b) {
    back = static_cast<color_t>(b);
    setbkcolor(b);
}
void setColor::setWordsColor(COLORS w) {
    words = static_cast<color_t>(w);
    setfontbkcolor(w);
}
void setColor::setFilledColor(COLORS fil) {
    filled = static_cast<color_t>(fil);
}
void setColor::setStuff(bool s) {
    if (s) {
        setfillcolor(stuff);
    }
    else {
        setfillcolor(back);
    }
}
color_t setColor::getFrameColor() {
    return front;
}

color_t setColor::getFilledColor() {
    return filled;
}

color_t setColor::getBackgroundColor() {
    return back;
}
color_t setColor::getWordsColor() {
    return words;
}
bool setColor::getStuff() {
    return stuff;
}