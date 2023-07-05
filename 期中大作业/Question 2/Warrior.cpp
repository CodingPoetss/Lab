#include"Warrior.h"


	Warrior::Warrior() {}
	Warrior::Warrior(string n, Character c, Weapon w) :name{ new string(n) }, warrior{ new Character(c) }, weapon{ new Weapon(w) } {}
	Warrior::Warrior(const Warrior& w) :name{ new string{*(w.name)} }, warrior{ new Character{*(w.warrior)} },
		weapon{ new Weapon{*(w.weapon)} }{
		Character::AddAliveCharacterNumber();
	}
	Warrior::~Warrior() {
		delete name; delete warrior; delete weapon;
	}
	void Warrior::introduce() {
		cout << "Existing character(s):" << Character::getCount() << endl;
		cout << "Name:" << *name << endl;
		cout << "HP:" << warrior->getHP() << ' ' << "MP:" << warrior->getMP() << ' ';
		cout << "ATK:" << warrior->getATK() << ' ' << "DEF:" << warrior->getDEF() << endl;
		cout << "Weapon:" << weapon->getName() << endl;
		cout << "Enduarance:" << weapon->getEnduarance() << ' ' << "Destructive:" << weapon->getDestructive() << endl << endl;
	}

