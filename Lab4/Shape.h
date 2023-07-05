#pragma once
#include<fstream>
#include<string>
#include <graphics.h>
#include<stdexcept>
using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;
using namespace ege;

class Shape{
public:
	virtual void draw() = 0;
	virtual void writeToFile(ofstream& out) = 0;
	static Shape* readFromFile(ifstream& in);
	static COLORS ChangeToColor(string str);
};


