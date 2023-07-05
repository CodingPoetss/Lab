#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<filesystem>
#include <graphics.h>
#include"Shape.h"
#include"theCircle.h"
#include"theRectangle.h"
#include"theTriangle.h"
using namespace ege;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
namespace fs = std::filesystem;


//该函数是建立在已经将各个图形数据写入file后，读取整个文档的所有图形数据
//首先会调用Shape类的静态函数，进行图形类别的确认（第一行）
//之后又会由Shape类的静态函数来调用各个类别的专属数据读取函数
vector<Shape*> readShapeFromFile(fs::path file) {
	vector<Shape*> shapes;
	ifstream in{ file };
	if (!in.is_open()) {
		cout << "The file " << file << " failed to open!" << endl;
	}
	while (!in.eof()) {
		Shape* CurrentShape = Shape::readFromFile(in);
		if (CurrentShape != nullptr) {
			shapes.push_back(CurrentShape);
		}
	}

	in.close();
	return shapes;
}



//该函数是将vector中已存的shape类型写到一个新的文档中（也可以继续接着写到某一文档之后）
//可作为文档的初始化的函数（预先将各图形指针储存到vector中）
void writeShapesToFile(vector<Shape*>shapes, fs::path newfile) {
	ofstream out{ newfile,std::ios::out | std::ios::trunc };
	if (!out.is_open()) {
		cout << "The file " << newfile << " failed to open!" << endl;
		return;
	}

	for (auto it : shapes) {
		it->writeToFile(out);
	}

	out.close();
}



//主函数部分
int main() {
	


	vector<Shape*>shapes;
	shapes.push_back(new theCircle{ 300,300,100,"yellow",true});  //s1
	shapes.push_back(new theCircle{600,300,100,"yellow",true});   //s2
	shapes.push_back(new theCircle{ 450,450,100,"green",true });  //s3
	shapes.push_back(new theRectangle{ 300,600,450,700,"brown",true });   //s4
	shapes.push_back(new theRectangle{ 500,600,600,750,"brown",true });   //s5
	shapes.push_back(new theTriangle{ 700,600,500,700,800,700,"green",true });  //s6
	shapes.push_back(new theTriangle{ 800,300,900,300,700,600,"green",true });  //s6



	//将所有要绘制的图形写入磁盘文件
	fs::path file1{ "Shapes.txt" };
	writeShapesToFile(shapes, file1);


	//从磁盘文件中读出
	auto nowfile = readShapeFromFile(file1);


	//开始绘制
	initgraph(900, 900);
	try {
		for (auto it : nowfile) {

			if (dynamic_cast<theCircle*>(it) != nullptr) {
				theCircle* now = dynamic_cast<theCircle*>(it);
				cout << *now;
			}
			else if (dynamic_cast<theRectangle*>(it) != nullptr) {
				theRectangle* now = dynamic_cast<theRectangle*>(it);
				cout << *now;
			}
			else if (dynamic_cast<theTriangle*>(it) != nullptr) {
				theTriangle* now = dynamic_cast<theTriangle*>(it);
				cout << *now;
			}
			else continue;

			//(*now)++;
			//cout << *now;
			//it->draw();
		}
	}
	catch (const std::exception& e) {
		outtextxy(50, 50,e.what());
	}

	theCircle* s1 = dynamic_cast<theCircle*>(shapes[0]);
	theCircle* s2 = dynamic_cast<theCircle*>(shapes[1]);
	theCircle* s3 = dynamic_cast<theCircle*>(shapes[2]);
	theRectangle* s4 = dynamic_cast<theRectangle*>(shapes[3]);
	theRectangle* s5 = dynamic_cast<theRectangle*>(shapes[4]);
	theTriangle* s6 = dynamic_cast<theTriangle*>(shapes[5]);
	theTriangle* s7 = dynamic_cast<theTriangle*>(shapes[6]);



	if (*s1 == *s2) {
		outtextxy(50, 100, "s1与s2相同");
	}
	else {
		outtextxy(50, 100, "s1与s2不同");
	}

	if (*s2 != *s3) {
		outtextxy(50, 150, "s2与s3不同");
	}
	
	else {
		outtextxy(50, 150, "s2与s3相同");
	}
	if (*s4 == *s5) {
		outtextxy(50, 200, "s4与s5相同");
	}
	else {
		outtextxy(50, 200, "s4与s5不同");
	}
	
	if (*s6 == *s7) {
		outtextxy(50, 250, "s6与s7相同");
	}
	else {
		outtextxy(50, 250, "s6与s7不同");
	}
	
	getch(); 
	closegraph();
	return 0;
}