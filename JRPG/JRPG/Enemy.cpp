#include <io.h>
#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(EnemyType type, Stat enemyStat, bool myTurn)
{
	this->stat.maxHealth = enemyStat.maxHealth;
	this->stat.strength = enemyStat.strength;
	this->stat.agility = enemyStat.agility;
	this->stat.armor = enemyStat.armor;
	this->stat.ciritalChance = enemyStat.ciritalChance;
	this->stat.ciritalDamage = enemyStat.ciritalDamage;

	enemyType = type;

	enemyTurn = myTurn;
	currentHp = this->stat.maxHealth;

	switch (enemyType)
	{
	case EnemyType::GOBLIN:
		nameOfEnemy = L"고블린";
		break;
	case EnemyType::SPIDER:
		nameOfEnemy = L"거미";
		break;
	case EnemyType::BEAR:
		nameOfEnemy = L"곰";
		break;
	case EnemyType::LIZARD:
		nameOfEnemy = L"도마뱀";
		break;
	case EnemyType::SLIME:
		nameOfEnemy = L"슬라임";
	default:
		break;
	}
}

void Enemy::GetDamage(int damage)
{
	currentHp -= damage;

	if (currentHp <= 0)
	{
		Dead();
		return;
	}
}

void Enemy::Dead()
{
	isDead = true;
}

void Enemy::Update()
{
	if (isDead) return;
	if (!enemyTurn) return;
	
	srand((unsigned int)time(NULL));
	int randNum = rand() % 3 + 1;

	Render();

	switch (randNum)
	{
	case (int)Behavior::USEITEM:
	{
		UseItem();
	}
	break;
	case (int)Behavior::ATTACK:
	{
		Attack();
	}
	break;
	case (int)Behavior::RUNAWAY:
	{
		RunAway();
	}
	break;
	}

	enemyTurn = false;
}

void Enemy::Render()
{
	
}

void Enemy::Attack()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 2 + 1;
	
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	if (randNum == 1)
	{
		
		int damage = stat.strength;
		
	}
	else
	{
		UseSkill();
	}
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void Enemy::Defence(int damage)
{
	int applyDamage = 
		(damage - stat.armor) > 1 ? (damage - stat.armor) : 1;
	GetDamage(applyDamage);
}

void Enemy::RunAway()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	

	srand((unsigned int)time(NULL));
	int success = rand() % 3 + 1;

	if (success == 1)
	{
		
	}
	else 
	{
		
	}
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void Enemy::UseItem()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	srand((unsigned int)time(NULL));
	int randNum = rand() % 4 + 1;

	switch (randNum)
	{
	case (int)EnemyItem::HEALTHPOTION:
	{
		currentHp += 10;
		
	}
	break;
	case (int)EnemyItem::DAMAGEUPPOTION:
	{
		stat.strength += 5;
	}
	break;
	case (int)EnemyItem::AGILITYPOTION:
	{
		stat.agility += 5;
	}
	break;
	case (int)EnemyItem::ARMORPOTION:
	{
		stat.armor += 5;
	}
	break;
	}

	int curmode = _setmode(_fileno(stdout), prevmode);
}

void Enemy::UseSkill()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	srand((unsigned int)time(NULL));
	int randNum = rand() % 5 + 1;

	switch (randNum)
	{
	case (int)SkillType::DOUBLEATTACK:
	{
		Attack();
		Attack();
	}
	break;
	case (int)SkillType::ARMORUP:
	{
		stat.armor += 5;
	}
	break;
	case (int)SkillType::AGILITYUP:
	{
		stat.agility += 5;
	}
	break;
	case (int)SkillType::DAMAGEUP:
	{
		stat.strength += 5;
	}
	break;
	case (int)SkillType::HEAL:
	{
		currentHp += 5;
	}
	break;
	}

	int curmode = _setmode(_fileno(stdout), prevmode);
}
