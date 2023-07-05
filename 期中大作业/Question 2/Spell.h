#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
class Spell {
private:
	string* name = nullptr;
	int* Enduarance = nullptr;
	int* Destructive = nullptr;
public:
	Spell();
	Spell(string n, int ed, int des);
	Spell(const Spell& s);
	~Spell();
	string getName();
	int getEnduarance();
	int getDestructive();
};