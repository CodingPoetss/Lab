#pragma once
#include"Character.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Saber :public Character {
private:
	string name{};
	Character saber;
public:
	Saber();
	Saber(string n, Character c);
	void introduce() override;
};