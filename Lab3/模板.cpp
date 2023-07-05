#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <graphics.h>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual void writeToFile(ofstream& out) = 0;
    static Shape* readFromFile(ifstream& in);
};

class theCircle : public Shape {
private:
    double x, y;
    double radius;
    string color;
    bool filled;
public:
    theCircle(double x, double y, double r, string color, bool filled)
        : x(x), y(y), radius(r), color(color), filled(filled) {}
    void draw();
    void writeToFile(ofstream& out);
    static theCircle* readFromFile(ifstream& in);
};

class Triangle : public Shape {
private:
    double x1, y1, x2, y2, x3, y3;
    string color;
    bool filled;
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3, string color, bool filled)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), color(color), filled(filled) {}
    void draw();
    void writeToFile(ofstream& out);
    static Triangle* readFromFile(ifstream& in);
};

class theRectangle : public Shape {
private:
    double x, y;
    double width, height;
    string color;
    bool filled;
public:
    theRectangle(double x, double y, double w, double h, string color, bool filled)
        : x(x), y(y), width(w), height(h), color(color), filled(filled) {}
    void draw();
    void writeToFile(ofstream& out);
    static theRectangle* readFromFile(ifstream& in);
};

Shape* Shape::readFromFile(ifstream& in) {
    int id;
    in >> id;
    if (id == 1) {
        return theCircle::readFromFile(in);
    }
    else if (id == 2) {
        return Triangle::readFromFile(in);
    }
    else if (id == 3) {
        return theRectangle::readFromFile(in);
    }
    else {
        return nullptr;
    }
}

theCircle* theCircle::readFromFile(ifstream& in) {
    double x, y, r;
    string color;
    bool filled;
    in >> x >> y >> r >> color >> filled;
    return new theCircle(x, y, r, color, filled);
}

Triangle* Triangle::readFromFile(ifstream& in) {
    double x1, y1, x2, y2, x3, y3;
    string color;
    bool filled;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> color >> filled;
    return new Triangle(x1, y1, x2, y2, x3, y3, color, filled);
}

Rectangle* theRectangle::readFromFile(ifstream& in) {
    double x, y, w, h;
    string color;
    bool filled;
    in >> x >> y >> w >> h >> color >> filled;
    return new theRectangle(x, y, w, h, color, filled);
}

void theCircle::draw() {
    setcolor(colorToRGB(color));
    if (filled) {
        setfillstyle(SOLID_FILL, colorToRGB(color));
        fillellipse(x, y, radius, radius);
    }
    else {
        circle(x, y, radius);
    }
}

void Triangle::draw() {
    setcolor(colorToRGB(color));
    if (filled) {
        setfillstyle(SOLID_FILL, colorToRGB(color));
        fillpoly(3, new int[6]{ x1, y1, x2, y2, x3, y3 });
    }
    else {
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    }
}

void theRectangle::draw() {
    setcolor(colorToRGB(color));
    if (filled) {
        setfillstyle(SOLID_FILL, colorToRGB(color));
        bar(x, y, x + width, y + height);
    }
    else {
        rectangle(x, y, x + width, y + height);
    }
}

void theCircle::writeToFile(ofstream& out) {
    out << "1 " << x << " " << y << " " << radius << " " << color << " " << filled << endl;
}

void Triangle::writeToFile(ofstream& out) {
    out << "2 " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << color << " " << filled << endl;
}

void theRectangle::writeToFile(ofstream& out) {
    out << "3 " << x << " " << y << " " << width << " " << height << " " << color << " " << filled << endl;
}



vector<Shape*> readShapesFromFile(string filename) {
    vector<Shape*> shapes;
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Failed to open file." << endl;
        return shapes;
    }
    while (!in.eof()) {
        Shape* shape = Shape::readFromFile(in);
        if (shape != nullptr) {
            shapes.push_back(shape);
        }
    }
    in.close();
    return shapes;
}

void writeShapesToFile(vector<Shape*>& shapes, string filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    for (Shape* shape : shapes) {
        shape->writeToFile(out);
    }
    out.close();
}

int main() {
    initwindow(800, 600);
    vector<Shape*> shapes = readShapesFromFile("shapes.txt");
    for (Shape* shape : shapes) {
        shape->draw();
    }
    writeShapesToFile(shapes, "new_shapes.txt");
    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}