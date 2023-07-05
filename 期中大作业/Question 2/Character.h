#pragma once
//������
class Character {
private:
	int* HP = nullptr;        //����int*���ͳ�Ա������ʼ��Ϊ��ָ��
	int* MP = nullptr;
	int* ATK = nullptr;
	int* DEF = nullptr;
	static int count;
public:
	Character();
	Character(int hp, int mp, int atk, int def);
	Character(const Character& c);
	~Character();                                       //���������ж��ڴ���л���
	
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