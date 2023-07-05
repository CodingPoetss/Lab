#pragma once
#include"Shape.h"

class theTriangle :public Shape {
private:
	int x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
	string color{};
	bool filled{};
public:
	theTriangle();
	theTriangle(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, string color_, bool filled_);
	void draw();
	void writeToFile(ofstream& out);
	static theTriangle* readFromFile(ifstream& in);
};