#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
//武器类
class Weapon {
private:
	string* name = nullptr;
	int* Enduarance = nullptr;
	int* Destructive = nullptr;
public:
	Weapon();
	Weapon(string n, int ed, int des);
	//是否用到？
	Weapon(const Weapon& w);
	~Weapon(); 
	string getName();
	int getEnduarance();
	int getDestructive();
};
