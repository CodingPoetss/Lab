#pragma once
#include "Shape.h"
class theCircle :public Shape {
private:
	int x{};
	int y{};
	int radius{};
	string color{};
	bool filled{};

public:
	theCircle();
	theCircle(int x_, int y_, int r_, string color_, bool filled_);
	void draw();
	void writeToFile(ofstream& out)override;
	static theCircle* readFromFile(ifstream& in);
	bool operator==(const theCircle& c);
	bool operator!=(const theCircle& c);
	void operator++(); //ǰ�� �����ƶ�
	void operator++(int dummy); //��� �����ƶ�
	void operator--(); //ǰ�� �����ƶ�
	void operator--(int dummy); //��� �����ƶ�
	friend std::ostream& operator<<(std::ostream& out, const theCircle& c);
	double getX();
	double getY();
};


