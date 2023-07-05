#include"theCircle.h"

theCircle::theCircle(){}
theCircle::theCircle(int x_, int y_, int r_, string color_, bool filled_)
 :x{ x_ }, y{ y_ }, radius{ r_ }, color{ color_ }, filled{filled_} {}
void theCircle::draw(){
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(color));
	//填充的圆
	if (filled) {
		setfillcolor(Shape::ChangeToColor(color));
		fillellipse(x, y, radius, radius);
	}
	//空心的圆
	else {
		circle(x, y, radius);
	}
}
void theCircle::writeToFile(ofstream& out){
	out << "1" << '\n' << x << " " << y << " " << radius << '\n' << color << " " << filled << endl;

}
theCircle* theCircle::readFromFile(ifstream& in) {
	int x, y, r;
	string color;
	bool filled;
	in >> x >> y >> r >> color >> filled;
	return new theCircle(x, y, r, color, filled); 
 }

bool theCircle::operator==(const theCircle& c) {
	if (radius == c.radius && color == c.color && filled == c.filled) {
		return true;
	}
	return false;
}
bool theCircle::operator!=(const theCircle& c) {
	if (radius == c.radius && color == c.color && filled == c.filled) {
		return false;
	}
	return true;
}
void theCircle::operator++() {
	y += 100;
}
void theCircle::operator++(int dummy) {
	x += 100;
}
void theCircle::operator--() {
	y -= 100;
}
void theCircle::operator--(int dummy) {
	x -= 100;
}

std::ostream& operator<<(std::ostream& out, const theCircle& c) {
	setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(c.color));
	//填充的圆
	if (c.filled) {
		setfillcolor(Shape::ChangeToColor(c.color));
		fillellipse(c.x, c.y, c.radius, c.radius);
	}
	//空心的圆
	else {
		circle(c.x, c.y, c.radius);
	}
	return out;
}
double theCircle::getX() {
	return x;
}
double theCircle::getY() {
	return y;
}
/*
std::ostream& operator<<(std::ostream& os, const theCircle& s) {
	// 将形状对象转换为字符串
	string str = "Hello";
	// 在ege图形库中打印字符串
	outtextxy(s.x, s.y, str.c_str());
	// 返回输出流以支持级联操作
	return os;
}
*/