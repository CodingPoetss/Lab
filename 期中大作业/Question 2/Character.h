#pragma once
//属性类
class Character {
private:
	int* HP = nullptr;        //定义int*类型成员并都初始化为空指针
	int* MP = nullptr;
	int* ATK = nullptr;
	int* DEF = nullptr;
	static int count;
public:
	Character();
	Character(int hp, int mp, int atk, int def);
	Character(const Character& c);
	~Character();                                       //析构函数中对内存进行回收
	
    virtual void introduce();
	int getHP();
	int getMP();
	int getATK();
	int getDEF();
	void setHP(int hp);
	void setMP(int mp);
	void setATK(int atk);
	void setDEF(int def);
	static int getCount();
	static void AddAliveCharacterNumber();
};