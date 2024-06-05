#include "Object.h"
#pragma once

class Player : public Object
{
public: // Deafult
	Stat _stat; // 스탯
	int _currnetHealth; // 현재 체력
	ObejectType _objectType;
	
	Player(Stat stat);
public: // Fnc
	// Object을(를) 통해 상속됨
	void Update() override;
	void Render() override;
	void Attack() override;
	void Defence(int damage) override;
	void RunAway() override;
	void UseItem() override;
	void UseSkill() override;
};

