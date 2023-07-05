#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"Dot.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;

//œﬂ∂Œ¿‡
class setLine :public Dot {
private:
    Dot dot1{};
    Dot dot2{};
public:
    setLine();
    setLine(Dot d1, Dot d2);

    void setDot1(Dot d1);   
    void setDot2(Dot d2);
    Dot getDot1();
    Dot getDot2();
};