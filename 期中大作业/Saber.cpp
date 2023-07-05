#include"Saber.h"

  Saber::Saber(){}
	Saber::Saber(string n, Character c) :name{ n }, saber{ c }{}
	void Saber::introduce() {
		cout << "Existing character(s):" << Character::getCount() << endl;
		cout << "Name;" << name << endl;
		cout << "HP:" << saber.getHP() << ' ' << "MP:" << saber.getMP() << endl;
		cout << "ATK:" << saber.getATK() << ' ' << "DEF:" << saber.getDEF() << endl << endl;
	}
