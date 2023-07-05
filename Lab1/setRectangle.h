#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"setColor.h"
#include"Dot.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;
//´ø¿ò¾ØÐÎ
class setRectangle :public Dot, setColor {
private:
    Dot dot1{};
    Dot dot2{};
    setColor rectangle_color{};

public:
    setRectangle();
    setRectangle(Dot d1, Dot d2, setColor c);

    void setDot1(Dot d1);
    void setDot2(Dot d2);
    Dot getDot1();
    Dot getDot2();

};