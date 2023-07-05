#include"Character.h"

	Character::Character() {}
	Character::Character(int hp, int mp, int atk, int def) :HP{ new int(hp) }, MP{ new int(mp) },
		ATK{ new int(atk) }, DEF{ new int(def) }{
		count++;
	}
	Character::Character(const Character& c) :HP{ new int{ *(c.HP) } }, MP{ new int{ *(c.MP) } },      //对传入对象进行深拷贝
		ATK{ new int{ *(c.ATK) } }, DEF{ new int{ *(c.DEF) } } {}

	Character::~Character() {
		delete HP; delete MP; delete ATK; delete DEF;                                       //析构函数中对内存进行回收
	}
    void Character::introduce() {}
	int Character::getHP() { return *HP; }
	int Character::getMP() { return *MP; }
	int Character::getATK() { return *ATK; }
	int Character::getDEF() { return *DEF; }
	void Character::setHP(int hp) { HP = &hp; }
	void Character::setMP(int mp) { MP = &mp; }
	void Character::setATK(int atk) { ATK = &atk; }
	void Character::setDEF(int def) { DEF = &def; }
	int Character::getCount() { return count; }
	void Character::AddAliveCharacterNumber() { count++; }
