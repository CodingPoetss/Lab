#pragma once
//��ɫ��
class Character {
private:
	int HP{};                                          //����ֵ
	int MP{};                                          //����ֵ
	int ATK{};                                         //������
	int DEF{};                                         //������
	static int count;                                  //�Ѵ��ɫ������
public:
	Character();
	Character(int hp, int mp, int atk, int def) ;      //ʹ�ó�ʼ���б�Խ�ɫ���Խ��г�ʼ��
	~Character();
	virtual void introduce();                          //�����麯���������ɫ��Ϣ
	int getHP();                                       //getter
	int getMP();
	int getATK();
	int getDEF();
	void setHP(int hp);                                //setter
	void setMP(int mp);
	void setATK(int atk);
	void setDEF(int def);
	static int getCount();							   //����ɫ����getter     
};