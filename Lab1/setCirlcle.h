#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"setColor.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;

//´ø¿òÔ²Àà
class setCircle :public setColor {
private:
    int x{ 0 };
    int y{ 0 };
    int radius{ 0 };
    setColor circle_color{};
public:
    setCircle();
    setCircle(int x_, int y_, int r_, setColor c);

    void setX(int x);
    void setY(int y);
    void setRadius(int radius);
    int getX();
    int getY();
    int getRadius();
    string getCircleInfo();
        
        string getCircleColor();
};