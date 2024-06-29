#include <vector>
#include <conio.h>
#include <fcntl.h>
#include "Console.h"
#include "Object.h"

#pragma once
using std::vector;

enum class PlayerState
{
	Attack = 1, Skill = 2, Item = 3, Defence= 4, None = 5
};
enum class SKillType {
	StrongAttack = 1, Sting = 2
};

struct Skill
{
	wstring name;
	int damage;
	Skill(wstring name, int damage);
};

class Player : public Object
{
public: // Deafult
	Stat _playerstat; // 스탯
	int _currnetHealth; // 현재 체력
	ObejectType _objectType;
	vector<Skill> skills;
	
	Player(Stat stat);
public: // Fnc
	void AttackTarget(Enemy enemy);
	// Object을(를) 통해 상속됨
	void Update() override;
	void Render() override;
	void Attack() override;
	void Defence(int damage) override;
	void UseItem() override;
	void UseSkill() override;
};
