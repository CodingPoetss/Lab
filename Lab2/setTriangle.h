#pragma once
#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"setColor.h"
#include"Dot.h"
#include"setLine.h"
#include"Shape.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;
//Èý½ÇÐÎÀà
class setTriangle :public Dot,public setLine,public setColor,public Shape{
private:
    Dot dot1{};
    Dot dot2{};
    Dot dot3{};
    setColor* color = new setColor{};
    static int ExistingTriangleNumber;
public:
    setTriangle();
    setTriangle(int x1,int y1,int x2,int y2,int x3,int y3,
        COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff);
    setTriangle(const setTriangle& triangle);
    ~setTriangle();
    void draw()override;
};
