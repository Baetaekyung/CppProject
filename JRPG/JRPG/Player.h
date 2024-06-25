#include "Object.h"
#pragma once

enum class PlayerState
{
	Attack = 1, Skill, Item, Defence, None
};

class Player : public Object
{
public: // Deafult
	Stat _stat; // ����
	int _currnetHealth; // ���� ü��
	ObejectType _objectType;
	
	Player(Stat stat);
public: // Fnc
	// Object��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	void Attack() override;
	void Defence(int damage) override;
	void UseItem() override;
	void UseSkill() override;
};

