#include"Dot.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
//µãÀà

Dot::Dot() {}
Dot::Dot(int x, int y) {
    this->x = x;
    this->y = y;
}
int Dot::getX() { return x; }
int Dot::getY() { return y; }
void Dot::setX(int x) { this->x = x; }
void Dot::setY(int y) { this->y = y; }
void Dot::getCoordinate() {
    std::cout << '(' + std::to_string(x) + ',' + std::to_string(y) + ')' + '\n';
}
