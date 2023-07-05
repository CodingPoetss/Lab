#include "Shape.h"
#include"theCircle.h"
#include"theRectangle.h"
#include"theTriangle.h"
//�ú������ص���ָ��ͼ�����͵�ָ�루����ʽת������Shape��ָ�룩
//��Ϊ����ʹ�û���ָ��ָ������Ķ���
Shape* Shape::readFromFile(ifstream& in) {
	int id;
	in >> id;
	if (id == 1) {
		//IDΪ1����Բ����Ϣ���ж�ȡ
		return theCircle::readFromFile(in);
	}
	
	else if (id == 2) {
		return theRectangle::readFromFile(in);
	}

	else if (id == 3) {
		return theTriangle::readFromFile(in);
	}
	else{
		return nullptr;
	}
}

COLORS Shape::ChangeToColor(string str) {
	string s = str;
	if (s == "BLACK" || s == "black") { return BLACK; }
	else if (s == "BLUE" || s == "blue") { return BLUE; }
	else if (s == "GREEN" || s == "green") { return GREEN; }
	else if (s == "CYAN" || s == "cyan") { return CYAN; }
	else if (s == "RED" || s == "red") { return RED; }
	else if (s == "MAGENTA" || s == "magenta") { return MAGENTA; }
	else if (s == "BROWN" || s == "brown") { return BROWN; }
	else if (s == "LIGHTGRAY" || s == "lightgray") { return LIGHTGRAY; }
	else if (s == "DARKGRAY" || s == "darkgray") { return DARKGRAY; }
	else if (s == "LIGHTBLUE" || s == "lightblue") { return LIGHTBLUE; }
	else if (s == "LIGHTGREEN" || s == "lightgreen") { return LIGHTGREEN; }
	else if (s == "LIGHTCYAN" || s == "lightcyan") { return LIGHTCYAN; }
	else if (s == "LIGHTRED" || s == "lightred") { return LIGHTRED; }
	else if (s == "LIGHTMAGENTA" || s == "lightmagenta") { return LIGHTMAGENTA; }
	else if (s == "YELLOW" || s == "yellow") { return YELLOW; }
	else if (s == "WHITE" || s == "white") { return WHITE; }
	else {
		throw std::out_of_range("Do not use the definite color!");
	}
}