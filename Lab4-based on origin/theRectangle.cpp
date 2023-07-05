#include"theRectangle.h"

theRectangle::theRectangle() : x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 }, color{ "" }, filled{ false } {}
theRectangle::theRectangle(int x1_, int y1_, int x2_, int y2_, string color_, bool filled_):
	x1{ x1_ }, y1{ y1_ } ,x2{x2_},y2{y2_},color{color_},filled{filled_}{}
void theRectangle::draw() {
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(color));
	if (filled) {
		setfillcolor(Shape::ChangeToColor(color));
		bar(x1, y1, x2, y2);
	}
	else {
		rectangle(x1, y1, x2, y2);
	}
}
void theRectangle::writeToFile(ofstream& out){
	out << "2" << '\n' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n' << color << ' ' << filled << endl;
}
theRectangle* theRectangle::readFromFile(ifstream& in) {
	int x1, y1,x2,y2;
	string color;
	bool filled;
	in >> x1 >> y1 >> x2 >> y2 >> color >> filled;
	return new theRectangle(x1, y1, x2, y2, color, filled);
}
double theRectangle::abs(double a, double b) {
	if ((a - b) >= 0) {
		return (a - b);
	}
	else {
		return (b - a);
	}
}
bool theRectangle::operator==(const theRectangle& r) {
	double s1 = abs(x1, x2) * abs(y1, y2);
	double s2 = abs(r.x1, r.x2) * abs(r.y1, r.y2);
	//double s1 = abs(x1, x2);
	//double s2 = abs(r.x1, r.x2);
	if (s1 == s2 && color == r.color && filled == r.filled) {
		return true;
	}
	else {
		return false;
	}
}
bool theRectangle::operator!=(const theRectangle& r) {
	if (*this == r) {
		return false;
	}
	else {
		return true;
	}
}
void theRectangle::operator++() {
	y1 += 100; y2 += 100;
}
void theRectangle::operator++(int dummy) {
	x1 += 100; x2 += 100;
}
void theRectangle::operator--() {
	y1 -= 100; y2 -= 100;
}
void theRectangle::operator--(int dummy) {
	x1 -= 100; x2 -= 100;
}
std::ostream& operator<<(std::ostream& out, const theRectangle& r) {
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(r.color));
	if (r.filled) {
		setfillcolor(Shape::ChangeToColor(r.color));
		bar(r.x1, r.y1, r.x2, r.y2);
	}
	else {
		rectangle(r.x1, r.y1, r.x2, r.y2);
	}
	return out;
}
