#pragma once
#include <vector>
#include <conio.h>
#include <fcntl.h>
#include "Console.h"
#include "Object.h"
#include "Player.h"

enum class EnemyType
{
	GOBLIN = 1,
	SPIDER = 2,
	BEAR   = 3,
	LIZARD = 4,
	SLIME  = 5,
};

enum class SkillType
{
	DOUBLEATTACK,
	ARMORUP,
	AGILITYUP,
	DAMAGEUP,
	HEAL,
};

enum class EnemyItem
{
	HEALTHPOTION = 1,
	DAMAGEUPPOTION = 2,
	AGILITYPOTION = 3,
	ARMORPOTION = 4,
};

enum class Behavior 
{
	USEITEM = 1,
	ATTACK = 2,
	RUNAWAY = 3,
};

class Enemy : public Object
{
public:
	Enemy();
	Enemy(EnemyType type, Stat enemyStat, bool myTurn = false);
public:
	void AttackPlayer();
	void GetDamage(int damage);
	void Dead();

	// Object을(를) 통해 상속됨
	void Update() override;

	void Render() override;

	void Attack() override;

	void Defence(int damage) override;

	void UseItem() override;

	void UseSkill() override;
public:
	std::vector<wstring> visual;
	wstring nameOfEnemy;
	Stat stat;
	int currentHp;
	int enemyDamage;
	EnemyType enemyType;
	bool enemyTurn = true;
	bool isDead = false;
};

