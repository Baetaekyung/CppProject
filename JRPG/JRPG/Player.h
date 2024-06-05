#include "Object.h"
#pragma once

class Player : virtual public Object
{
public: // Deafult
	Stat _stat; // ����
	int _currnetHealth; // ���� ü��
	
	Player(Stat stat);
public: // Fnc
	// Object��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	void Attack() override;
	void Defence(int damage) override;
	void RunAway() override;
	void UseItem() override;
	void UseSkill() override;
};

