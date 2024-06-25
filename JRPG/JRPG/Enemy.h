#pragma once

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
	Enemy(EnemyType type, int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier, bool myTurn);
public:
	void GetDamage(int damage);
	void Dead();

	// Object을(를) 통해 상속됨
	void Update() override;

	void Render() override;

	void Attack() override;

	void Defence(int damage) override;

	void RunAway() override;

	void UseItem() override;

	void UseSkill() override;
public:
	wstring nameOfEnemy;
	Stat stat;
	int currentHp;
	EnemyType enemyType;
	bool enemyTurn = true;
	bool isDead = false;
};

