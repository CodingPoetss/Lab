#include"Character.h"
	Character::Character() {}
	Character::Character(int hp, int mp, int atk, int def) :HP{ hp }, MP{ mp }, ATK{ atk }, DEF{ def }{       //ʹ�ó�ʼ���б�Խ�ɫ���Խ��г�ʼ��
		count++;
	}
	Character::~Character() {}
	void Character::introduce() {}
	int Character::getHP() { return HP; }
	int Character::getMP() { return MP; }
	int Character::getATK() { return ATK; }
	int Character::getDEF() { return DEF; }
	void Character::setHP(int hp) { HP = hp; }
	void Character::setMP(int mp) { MP = mp; }
	void Character::setATK(int atk) { ATK = atk; }
	void Character::setDEF(int def) { DEF = def; }
	int Character::getCount() { return count; }
