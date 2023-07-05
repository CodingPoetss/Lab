#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
#include"Shape.h"

using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;

//´ø¿òÔ²Àà
class setCircle :public Shape {
private:
    int* x = nullptr;
    int* y = nullptr;
    int* radius = nullptr;
    setColor* color = new setColor{};
    static int ExistingCircleNumber;
public:
    setCircle();
    setCircle(int x_, int y_, int r_,
        COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff);
    setCircle(const setCircle& circle);
    ~setCircle();
    void setX(int x);
    void setY(int y);
    void setRadius(int radius);
    int getX();
    int getY();
    int getRadius();
    static int getExistingCircleNumber();
  
    void draw() override;
   

};