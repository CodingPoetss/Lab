#pragma once
#include"Character.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Archer :public Character {
private:
	string name{};
	Character archer;
public:
	Archer();
	Archer(string n, Character c);
	void introduce()override;
};