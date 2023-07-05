#pragma once
#include"Character.h"
#include"Spell.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

//Î×Ê¦
class Mage :public Character, public Spell {
private:
	string* name = nullptr;
	Character* mage = nullptr;
	Spell* spell = nullptr;
public:
	Mage();
	Mage(string n, Character c, Spell s);
	Mage(const Mage& m);
   ~Mage();
    void introduce()override;
};
