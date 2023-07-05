#include"Spell.h"


	Spell::Spell() {}
	Spell::Spell(string n, int ed, int des) :name{ new string{n} }, Enduarance{ new int{ed} }, Destructive{ new int{des} }{}
	Spell::Spell(const Spell& s) :name{ new string{*(s.name)} },
		Enduarance{ new int{*(s.Enduarance)} }, Destructive{ new int{*(s.Destructive)} } {}
	Spell::~Spell() {
		delete name; delete Enduarance; delete Destructive;
	}
	string Spell::getName() { return *name; }
	int Spell::getEnduarance() { return *Enduarance; }
	int Spell::getDestructive() { return *Destructive; }
