#pragma once
//角色类
class Character {
private:
	int HP{};                                          //生命值
	int MP{};                                          //法力值
	int ATK{};                                         //攻击力
	int DEF{};                                         //防御力
	static int count;                                  //已存角色的数量
public:
	Character();
	Character(int hp, int mp, int atk, int def) ;      //使用初始化列表对角色属性进行初始化
	~Character();
	virtual void introduce();                          //创造虚函数，输出角色信息
	int getHP();                                       //getter
	int getMP();
	int getATK();
	int getDEF();
	void setHP(int hp);                                //setter
	void setMP(int mp);
	void setATK(int atk);
	void setDEF(int def);
	static int getCount();							   //存活角色数的getter     
};