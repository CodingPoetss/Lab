#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
//������
class Weapon {
private:
	string* name = nullptr;
	int* Enduarance = nullptr;
	int* Destructive = nullptr;
public:
	Weapon();
	Weapon(string n, int ed, int des);
	//�Ƿ��õ���
	Weapon(const Weapon& w);
	~Weapon(); 
	string getName();
	int getEnduarance();
	int getDestructive();
};
