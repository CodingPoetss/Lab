#include"Weapon.h"


	Weapon::Weapon() {}
	Weapon::Weapon(string n, int ed, int des) : name{ new string{n} }, Enduarance{ new int{ed} }, Destructive{ new int{des} } {}
	// «∑Ò”√µΩ£ø
	Weapon::Weapon(const Weapon& w) :name{ new string{*(w.name)} },
		Enduarance{ new int{*(w.Enduarance)} }, Destructive{ new int{*(w.Destructive)} } {}
	Weapon::~Weapon() {
		delete name; delete Enduarance; delete Destructive;
	}
	string Weapon::getName() { return *name; }
	int Weapon::getEnduarance() { return *Enduarance; }
	int Weapon::getDestructive() { return *Destructive; }

