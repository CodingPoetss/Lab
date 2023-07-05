#pragma once
/*
//初始化
class InitGraph {
private:
    int Width{ 0 };
    int Height{ 0 };

public:
    InitGraph() {}
    InitGraph(int w, int h) :Width{ w }, Height{ h } {
        initgraph(w, h);
    }
    ~InitGraph() {
        closegraph();
    }


    //重载一个清屏函数，可输入清屏的颜色
    void clean() {
        cleardevice();
    }
    void clean(COLORS c) {
        setbkcolor_f(c);
        cleardevice();
    }


    void setSize(int w,int h){
        closegraph();
        initgraph(w, h);
        Width = w;
        Height = h;
    }

    int getWidth() {
        return Width;
     }

    int getHeight() {
        return Height;
    }

};



//颜色基类(图形类都得继承)
class setColor {
private:
    //可用static_cast将color_t和COLORS类型相互转换
    color_t front{ 0 };       //前景色，表示绘制的线条的颜色，即边框色（同时还表示文字的颜色）
    color_t back{ 0xFCFCFC };        //背景色，表示背景颜色
    color_t words{ 0 };       //文字色，表示文字背景色
    color_t filled{ 0 };      //填充色，填充到几何形状中的颜色，即填充色
    bool stuff{ true };       //是否填充？
public:
    setColor() {};
    setColor(color_t f, color_t b, color_t w, color_t fil, bool s) :front{ f }, back{ b }, words{ w }, filled{ fil }, stuff{ s } {
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
    setColor(COLORS f, COLORS b, COLORS w,COLORS fil,bool s) : setColor(static_cast<color_t>(f),static_cast<color_t>(b),      //代理构造
         static_cast<color_t>(w),static_cast<color_t>(fil),s ){}

    void setFrameColor(color_t f) {
        front = f;
    }

    void setFilledColor(color_t fil) {
        front = fil;
    }

    COLORS getFrameColor() {
        return static_cast<COLORS>(front);
    }

    COLORS getFilledColor() {
        return static_cast<COLORS>(filled);
    }

    string getAllColor() {
        return "The FrameColor is:" + std::to_string(static_cast<COLORS>(front)) + '\n' +
            "The FilledColor is:" + std::to_string(static_cast<COLORS>(filled)) +" Filled? "+std::to_string(stuff) + '\n' +
            "The BackgroundColor is:" + std::to_string(static_cast<COLORS>(back)) + '\n';
    }
};



//点类
class Dot {
private:
    int x{0};
    int y{0};
public:
    Dot() {}
    Dot(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void getCoordinate() {
        std::cout<< '(' + std::to_string(x) + ',' + std::to_string(y) + ')' + '\n';
    }
};



//带框圆类
class setCircle:public setColor {
private:
    int x{0};
    int y{0};
    int radius{ 0 };
    setColor circle_color{};
public:
    setCircle() {}
    setCircle(int x_, int y_, int r_, setColor c) :x{ x_ }, y{ y_ }, radius{ r_ }, circle_color{c} {
        setlinestyle(NULL_LINE);
        pieslice(x_, y_, 0, 0, r_);
        setlinestyle(SOLID_LINE);
        circle(x_, y_, r_);

    }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setRadius(int radius) { this->radius = radius; }
    int getX() { return x; }
    int getY() { return y; }
    int getRadius() { return radius; }
    string getCircleInfo() {
        return "X is:" + std::to_string(x) + " Y is:" + std::to_string(y) + " R is:" + std::to_string(radius)+'\n';
    }
    string getCircleColor(){
        return getCircleInfo() + circle_color.getAllColor();
    }
};


//带框矩形
class setRectangle :public Dot,setColor{
private:
    Dot dot1{};
    Dot dot2{};
    setColor rectangle_color{};

public:
    setRectangle(){}
    setRectangle(Dot d1, Dot d2, setColor c) :dot1{ d1 }, dot2{ d2 }, rectangle_color{c}{
        bar(d1.getX(), d1.getY(), d2.getX(), d2.getY());
        rectangle(d1.getX(), d1.getY(), d2.getX(), d2.getY());
    }

    void setDot1(Dot d1) { dot1 = d1; }
    void setDot2(Dot d2) { dot2 = d2; }
    Dot getDot1() { return dot1; }
    Dot getDot2() { return dot2; }

};


//线段类
class setLine:public Dot {
private:
    Dot dot1{};
    Dot dot2{};
public:
    setLine() {}
    setLine(Dot d1, Dot d2) :dot1{ d1 }, dot2{ d2 }{
        line(d1.getX(), d1.getY(), d2.getX(), d2.getY());
    }

    void setDot1(Dot d1) { dot1 = d1; }
    void setDot2(Dot d2) { dot2 = d2; }
    Dot getDot1() { return dot1; }
    Dot getDot2() { return dot2; }
};



//三角形类
class setTriangle:public Dot,setLine,setColor{
private:
    setLine line1;
    setLine line2;
    setLine line3;
    setColor color;
public:
    setTriangle(){}
    setTriangle(Dot d1, Dot d2, Dot d3, setColor c) :color{ c } {
        setLine{ d1,d2 };
        setLine{ d2,d3 };
        setLine{ d3,d1 };

    }
};

*/