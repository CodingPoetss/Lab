#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"setColor.h"
#include"Dot.h"
#include"Shape.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;
//´ø¿ò¾ØÐÎ
class setRectangle :public Dot,public setColor,public Shape {
private:
    Dot dot1 = {};
    Dot dot2 = {};
    setColor* color = new setColor {};
    static int ExistingRectangleNumber;

public:
    setRectangle();
    setRectangle(int x1,int y1,int x2,int y2, COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff);
    setRectangle(const setRectangle& rectangle);
    ~setRectangle();
    void setDot1(Dot d1);
    void setDot2(Dot d2);
    Dot getDot1();
    Dot getDot2();

    void draw() override;
};