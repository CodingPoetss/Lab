#include"theTriangle.h"

theTriangle::theTriangle(){}
theTriangle::theTriangle(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, string color_, bool filled_)
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), color(color_), filled(filled_) {}
void theTriangle::draw() {
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(color));
	if (filled) {
		setfillcolor(Shape::ChangeToColor(color));
		fillpoly(3, new int[6]{ x1, y1, x2, y2, x3, y3 });
	}
	else {
		line(x1, y1, x2, y2);
		line(x2, y2, x3, y3);
		line(x3, y3, x1, y1);
	}
}
void theTriangle::writeToFile(ofstream& out) {
	out << "3" << endl << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl << color << ' ' << filled;
}
theTriangle* theTriangle::readFromFile(ifstream& in) {
	int x1, y1, x2, y2, x3, y3;
	string color;
	bool filled;
	in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> color >> filled;
	return new theTriangle{ x1, y1, x2, y2, x3, y3 ,color,filled };
}