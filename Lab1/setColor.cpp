#include"setColor.h"
//颜色基类(图形类都得继承)

    setColor::setColor(){}
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

    void setColor::setFrameColor(color_t f) {
        front = f;
    }

    void setColor::setFilledColor(color_t fil) {
        front = fil;
    }

    COLORS setColor::getFrameColor() {
        return static_cast<COLORS>(front);
    }

    COLORS setColor::getFilledColor() {
        return static_cast<COLORS>(filled);
    }

    string setColor::getAllColor() {
        return "The FrameColor is:" + std::to_string(static_cast<COLORS>(front)) + '\n' +
            "The FilledColor is:" + std::to_string(static_cast<COLORS>(filled)) + " Filled? " + std::to_string(stuff) + '\n' +
            "The BackgroundColor is:" + std::to_string(static_cast<COLORS>(back)) + '\n';
    }
