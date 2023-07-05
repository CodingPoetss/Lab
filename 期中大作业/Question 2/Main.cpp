#include<iostream>
#include<string>
#include"Character.h"
#include"Warrior.h"
#include"Mage.h"
#include"Spell.h"
#include"Weapon.h"
using std::string;
using std::cout;
using std::endl;


int Character::count = 0;
int main() {
	

	Warrior w1{ "Saber",{5,8,9,4},{ "Ex-calibur",7,10 } };
	w1.introduce();

	Warrior w2{ w1 };
	w2.introduce();

	Mage m1{ "Archer",{3,10,7,3},{"the Treasury of King",10,8}};
	m1.introduce();

	Mage m2{ m1 };
	m2.introduce();

	return 0;
}