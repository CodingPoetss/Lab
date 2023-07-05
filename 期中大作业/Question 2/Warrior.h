#pragma once
#include"Character.h"
#include"Weapon.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

class Warrior :public Character, public Weapon {
private:
	string* name = nullptr;
	Character* warrior = nullptr;
	Weapon* weapon = nullptr;
public:
	Warrior();
	Warrior(string n, Character c, Weapon w);
	Warrior(const Warrior& w);
	~Warrior();
	void introduce() override;

};