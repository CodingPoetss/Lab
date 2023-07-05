#pragma once
#include <graphics.h>
#include <string>
#include<iostream>
using namespace ege;
using std::string;
using std::stoi;
using std::cout;
using std::endl;
using std::cin;

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
    setColor() ;
    setColor(color_t f, color_t b, color_t w, color_t fil, bool s);
    setColor(COLORS f, COLORS b, COLORS w, COLORS fil, bool s);

    void setFrameColor(color_t f);

    void setFilledColor(color_t fil);

    COLORS getFrameColor();
    

    COLORS getFilledColor();

    string getAllColor();
};