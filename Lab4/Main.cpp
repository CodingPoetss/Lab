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


//�ú����ǽ������Ѿ�������ͼ������д��file�󣬶�ȡ�����ĵ�������ͼ������
//���Ȼ����Shape��ľ�̬����������ͼ������ȷ�ϣ���һ�У�
//֮���ֻ���Shape��ľ�̬���������ø�������ר�����ݶ�ȡ����
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



//�ú����ǽ�vector���Ѵ��shape����д��һ���µ��ĵ��У�Ҳ���Լ�������д��ĳһ�ĵ�֮��
//����Ϊ�ĵ��ĳ�ʼ���ĺ�����Ԥ�Ƚ���ͼ��ָ�봢�浽vector�У�
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


//�������������Ϣ���浽��
std::array<std::array<bool,5>,5> Coodinary;




//�������꣬��������Ϣ���浽vector��
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


//����������
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
	//������Ҫ���Ƶ�ͼ��д������ļ�
	fs::path file1{ "Shapes.txt" };
	writeShapesToFile(shapes, file1);


	//�Ӵ����ļ��ж���
	auto nowfile = readShapeFromFile(file1);


	//��ʼ����
	initgraph(1000, 1000);
	for (auto it : nowfile) {
		it->draw();
	}

	getch();
	closegraph();
	return 0;
	*/
}