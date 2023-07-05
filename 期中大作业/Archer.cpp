#include"Archer.h"

	Archer::Archer() {}
	Archer::Archer(string n, Character c) :name{ n }, archer{ c }{}
	void Archer::introduce() {
		cout << "Existing character(s):" << Character::getCount() << endl;
		cout << "Name;" << name << endl;
		cout << "HP:" << archer.getHP() << ' ' << "MP:" << archer.getMP() << endl;
		cout << "ATK:" << archer.getATK() << ' ' << "DEF:" << archer.getDEF() << endl << endl;
	}
