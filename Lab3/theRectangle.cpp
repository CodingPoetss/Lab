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