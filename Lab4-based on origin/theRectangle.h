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
	double abs(double a, double b);
	bool operator==(const theRectangle& r);
	bool operator!=(const theRectangle& r);
	void operator++(); //前加 向下移动
	void operator++(int dummy); //后加 向右移动
	void operator--(); //前减 向上移动
	void operator--(int dummy); //后减 向左移动
	friend std::ostream& operator<<(std::ostream& out, const theRectangle& r);
};