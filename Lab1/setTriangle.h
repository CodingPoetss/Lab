#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"setColor.h"
#include"Dot.h"
#include"setLine.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;
//Èý½ÇÐÎÀà
class setTriangle :public Dot, setLine, setColor {
private:
    setLine line1;
    setLine line2;
    setLine line3;
    setColor color;
public:
    setTriangle();
    setTriangle(Dot d1, Dot d2, Dot d3, setColor c);
};
