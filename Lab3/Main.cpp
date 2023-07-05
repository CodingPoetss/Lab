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
	
	/*
	//用户在端口输入所要绘制的图形
	vector<Shape*>shapes;
	while (1) {
		cout << "Please enter the ID of the graph you wanna draw while '1' means circle,'2' means rectangle and '3' means triangle:" << endl;
		int id{};
		cin >> id;
		if (id == 1) {
			cout << "Please enter coordinaries of circle center and radius:" << endl;
			int x, y, r;
			cin >> x >> y >> r;
			cout << "Please enter color and fill it or not:" << endl;
			string s;
			bool f;
			cin >> s >> f;
			shapes.push_back(new theCircle{ x,y,r,s,f });
		}

		else if (id == 2) {
			cout << "Please enter coordinaries of top left corner and bottom right corner:" << endl;
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << "Please enter color and fill it or not:" << endl;
			string s;
			bool f;
			cin >> s >> f;
			shapes.push_back(new theRectangle{x1,y1,x2,y2,s,f});
		}

		else if (id == 3) {
			cout << "Please enter coordinaries of three points of the triangle:" << endl;
			int x1, y1, x2, y2, x3, y3;
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			cout << "Please enter color and fill it or not:" << endl;
			string s;
			bool f;
			cin >> s >> f;
			shapes.push_back(new theTriangle{ x1,y1,x2,y2,x3,y3,s,f });
		}
		
		cout << "Wanna continue or not?" << endl;
		bool judge{};
		cin >> judge;
		if (judge) {
			continue;
		}
		else {
			break;
		}
	}
	*/



	vector<Shape*>shapes;
	shapes.push_back(new theCircle{ 300,300,100,"yellow",true});
	shapes.push_back(new theCircle{ 600,300,100,"blue",true });
	shapes.push_back(new theCircle{ 450,450,100,"green",true });
	shapes.push_back(new theRectangle{ 300,600,450,700,"brown",true });
	shapes.push_back(new theTriangle{ 700,600,500,700,800,700,"opppps",true });




	//将所有要绘制的图形写入磁盘文件
	fs::path file1{ "Shapes.txt" };
	writeShapesToFile(shapes, file1);


	//从磁盘文件中读出
	auto nowfile = readShapeFromFile(file1);


	//开始绘制
	initgraph(900, 900);
	for (auto it : nowfile) {
		it->draw();
	}

	getch();
	closegraph();
	return 0;
}