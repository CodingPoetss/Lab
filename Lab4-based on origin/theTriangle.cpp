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
	out << "3" << endl << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl << color << ' ' << filled << endl;
}
theTriangle* theTriangle::readFromFile(ifstream& in) {
	int x1, y1, x2, y2, x3, y3;
	string color;
	bool filled;
	in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> color >> filled;
	return new theTriangle{ x1, y1, x2, y2, x3, y3 ,color,filled };
}
double theTriangle::abs(double a, double b) {
	if ((a - b) >= 0) {
		return (a - b);
	}
	else {
		return (b - a);
	}
}
bool theTriangle::operator==(const theTriangle& t) {
	double s1 = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1, x2 * y1 + x3 * y2 + x1 * y3);
	double s2 = 0.5 * abs(t.x1 * t.y2 + t.x2 * t.y3 + t.x3 * t.y1, t.x2 * t.y1 + t.x3 * t.y2 + t.x1 * t.y3);
	if (s1 == s2 && color == t.color && filled == t.filled) {
		return true;
	}
	else {
		return false;
	}
}
bool theTriangle::operator!=(const theTriangle& t) {
	if (*this == t) {
		return false;
	}
	else {
		return true;
	}
}
void theTriangle::operator++() {
	y1 += 100; y2 += 100; y3 += 100;
}
void theTriangle::operator++(int dummy) {
	x1 += 100; x2 += 100; x3 += 100;
}
void theTriangle::operator--() {
	y1 -= 100; y2 -= 100; y3 -= 100;
}
void theTriangle::operator--(int dummy) {
	x1 -= 100; x2 -= 100; x3 -= 100;

}
std::ostream& operator<<(std::ostream& out, const theTriangle& t) {
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(t.color));
	if (t.filled) {
		setfillcolor(Shape::ChangeToColor(t.color));
		fillpoly(3, new int[6]{ t.x1, t.y1, t.x2, t.y2, t.x3, t.y3 });
	}
	else {
		line(t.x1, t.y1, t.x2, t.y2);
		line(t.x2,t.y2, t.x3, t.y3);
		line(t.x3, t.y3, t.x1, t.y1);
	}
	return out;
}