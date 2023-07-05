#pragma once
#include"Shape.h"

class theRectangle :public Shape {
private:
	int x1{}, y1{}, x2{}, y2{};
	string color{};
	bool filled{};
public:
	theRectangle();
	theRectangle(int x1_, int y1_, int x2_, int y2_, string color_, bool filled_);
	void draw();
	void writeToFile(ofstream& out);
	static theRectangle* readFromFile(ifstream& in);
};