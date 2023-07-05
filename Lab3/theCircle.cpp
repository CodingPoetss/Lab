#include"theCircle.h"

theCircle::theCircle(){}
theCircle::theCircle(int x_, int y_, int r_, string color_, bool filled_)
 :x{ x_ }, y{ y_ }, radius{ r_ }, color{ color_ }, filled{filled_} {}
void theCircle::draw(){
    setbkcolor(WHITE);
	setcolor(Shape::ChangeToColor(color));
	//Ìî³äµÄÔ²
    if (filled) {
        setfillcolor(Shape::ChangeToColor(color));
        fillellipse(x, y, radius, radius);
    }
	//¿ÕÐÄµÄÔ²
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
