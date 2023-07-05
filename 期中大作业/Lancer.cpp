#include"Lancer.h"

	Lancer::Lancer() {}
	Lancer::Lancer(string n, Character c) :name{ n }, lancer{ c }{}
	void Lancer::introduce(){
		cout << "Existing character(s):" << Character::getCount() << endl;
		cout << "Name;" << name << endl;
		cout << "HP:" << lancer.getHP() << ' ' << "MP:" << lancer.getMP() << endl;
		cout << "ATK:" << lancer.getATK() << ' ' << "DEF:" << lancer.getDEF() << endl << endl;
	}
