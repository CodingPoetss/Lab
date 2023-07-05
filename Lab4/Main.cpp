#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<filesystem>
#include <graphics.h>
#include<array>
#include<stdexcept>
#include<exception>
#include"Shape.h"
#include"theRectangle.h"
using namespace ege;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::array;
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


//将输入的坐标信息储存到中
std::array<std::array<bool,5>,5> Coodinary;




//传入坐标，将方块信息储存到vector中
void CoordinaryExchange(array<array<bool, 5>, 5> coodinary,vector<Shape*> shapes) {
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 5; j++) {
			if(coodinary[i][j])
			shapes.push_back(new theRectangle{ i * 100, j * 100, (i+1) * 100, (j+1) * 100, "brown", true });
		}
		
			
	}
	
}


bool equalfunction(array<array<bool, 5>, 5> coodinary,int row){
	for (auto it : coodinary[row]) {
		if (!it) {
			return false;
		}
	}
	return true;
}
void addfunction(){

}


//主函数部分
int main() {
	
	vector<Shape*> shapes;

	for (int i = 0; i < 5; i++) {
		Coodinary[0][i] = true;
	}
	
	if (equalfunction(Coodinary, 1)) {
		cout << "yes" << endl;
	}
	else {
		cout << "noooooo" << endl;
	}

	/*
	//将所有要绘制的图形写入磁盘文件
	fs::path file1{ "Shapes.txt" };
	writeShapesToFile(shapes, file1);


	//从磁盘文件中读出
	auto nowfile = readShapeFromFile(file1);


	//开始绘制
	initgraph(1000, 1000);
	for (auto it : nowfile) {
		it->draw();
	}

	getch();
	closegraph();
	return 0;
	*/
}