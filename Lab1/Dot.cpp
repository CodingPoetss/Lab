#include"Dot.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
//µ„¿‡

    Dot::Dot() {}
    Dot::Dot(int x_, int y_) {
        x = x_;
        y = y_;
    }
    int Dot::getX() { return x; }
    int Dot::getY() { return y; }
    void Dot::setX(int x_) { x = x_; }
    void Dot::setY(int y_) { y = y_; }
    void Dot::getCoordinate() {
        std::cout << '(' + std::to_string(x) + ',' + std::to_string(y) + ')' + '\n';
    }
