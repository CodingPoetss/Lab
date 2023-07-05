#pragma once
#include"Character.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

class Lancer :public Character {
private:
	string name{};
	Character lancer;
public:
	Lancer();
	Lancer(string n, Character c);
	void introduce()override;
};