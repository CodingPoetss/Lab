#include"Mage.h"
	Mage::Mage() {}
	Mage::Mage(string n, Character c, Spell s) :name{ new string(n) }, mage{ new Character(c) }, spell{ new Spell(s) }{}
	Mage::Mage(const Mage& m) :name{ new string{*(m.name)} }, mage{ new Character{*(m.mage)} }, spell{ new Spell{*(m.spell)} } {
		Character::AddAliveCharacterNumber();
	}
	Mage::~Mage() {
		delete name; delete mage; delete spell;
	}
	void Mage::introduce() {
		cout << "Existing character(s):" << Character::getCount() << endl;
		cout << "Name;" << *name << endl;
		cout << "HP:" << mage->getHP() << ' ' << "MP:" << mage->getMP() << endl;
		cout << "ATK:" << mage->getATK() << ' ' << "DEF:" << mage->getDEF() << endl;
		cout << "Spell:" << spell->getName() << endl;
		cout << "Enduarance:" << spell->getEnduarance() << ' ' << "Destructive:" << spell->getDestructive() << endl << endl;
	}

