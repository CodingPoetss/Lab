#pragma once
#include <graphics.h>
#include<iostream>
#include"setColor.h"
#include"Dot.h"

using namespace ege;
using std::cout;
using std::endl;
using std::cin;

class Shape {
private:
	setColor* color = nullptr;
	
public:
	virtual void draw() = 0;
};