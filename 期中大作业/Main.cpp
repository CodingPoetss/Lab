#include<iostream>
#include<string>
#include"Character.h"
#include"Archer.h"
#include"Lancer.h"
#include"Saber.h"
using std::string;
using std::cout;
using std::endl;



int Character::count = 0;
int main() {
	Saber c1{ "Sakura",{5,6,10,4} };
	c1.introduce();
	Lancer c2{ "Minader",{7,5,6,8} };
	c2.introduce();
	Archer c3{ "Bilin",{4,9,8,3} };
	c3.introduce();

	return 0;
}