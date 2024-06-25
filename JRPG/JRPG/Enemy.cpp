#include <conio.h>
#include "Console.h"
#include "Object.h"
#include "Enemy.h"
#include "Information.h"

Enemy::Enemy()
{
}

Enemy::Enemy(EnemyType type, int health, int damage, int agility,
	int armor, int criticalPercent,
	int criticalMultiplier, bool myTurn)
{
	this->stat.maxHealth = health;
	this->stat.strength = damage;
	this->stat.agility = agility;
	this->stat.armor = armor;
	this->stat.ciritalChance = criticalPercent;
	this->stat.ciritalDamage = criticalMultiplier;

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
		wcout << nameOfEnemy << L"의 공격!" << '\n';
		int damage = stat.strength;
		wcout << nameOfEnemy << L"이 " << damage << L"의 데미지를 주었다!" << '\n';
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
	wcout << nameOfEnemy << L"의 도망시도!!" << '\n';

	srand((unsigned int)time(NULL));
	int success = rand() % 3 + 1;

	if (success == 1)
	{
		wcout << nameOfEnemy << L"이 도망쳤다!" << '\n';
		wcout << nameOfEnemy << L"전투가 종료되었다." << '\n';
	}
	else 
	{
		wcout << nameOfEnemy << L"이 도망가는데에 실패했다!" << '\n';
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
		wcout << nameOfEnemy << L"이 회복포션을 사용하여 체력이 10 회복되었다!" << '\n';
	}
	break;
	case (int)EnemyItem::DAMAGEUPPOTION:
	{
		stat.strength += 5;
		wcout << nameOfEnemy << L"이 데미지포션을 사용하여 데미지가 5 증가하였다!" << '\n';
	}
	break;
	case (int)EnemyItem::AGILITYPOTION:
	{
		stat.agility += 5;
		wcout << nameOfEnemy << L"이 회피포션을 사용하여 회피확률이 5 증가하였다!" << '\n';
	}
	break;
	case (int)EnemyItem::ARMORPOTION:
	{
		stat.armor += 5;
		wcout << nameOfEnemy << L"이 방어력 포션을 사용하여 방어력이 5 증가하였다!" << '\n';
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
		wcout << L"더블어택 스킬 발동!" << '\n';
		Attack();
		Attack();
	}
	break;
	case (int)SkillType::ARMORUP:
	{
		wcout << nameOfEnemy << L"의 방어력 증가 스킬 발동!" << '\n';
		stat.armor += 5;
		wcout << nameOfEnemy << L"의 방어력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::AGILITYUP:
	{
		wcout << nameOfEnemy << L"의 회피력 증가 스킬 발동!" << '\n';
		stat.agility += 5;
		wcout << nameOfEnemy << L"의 회피력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::DAMAGEUP:
	{
		wcout << nameOfEnemy << L"의 공격력 증가 스킬 발동!" << '\n';
		stat.strength += 5;
		wcout << nameOfEnemy << L"의 공격력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::HEAL:
	{
		wcout << nameOfEnemy << L"의 체력 회복 스킬 발동!" << '\n';
		currentHp += 5;
		wcout << nameOfEnemy << L"의 체력이 5 회복되었다." << '\n';
	}
	break;
	}

	int curmode = _setmode(_fileno(stdout), prevmode);
}
