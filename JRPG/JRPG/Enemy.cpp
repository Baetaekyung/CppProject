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
		nameOfEnemy = L"���";
		break;
	case EnemyType::SPIDER:
		nameOfEnemy = L"�Ź�";
		break;
	case EnemyType::BEAR:
		nameOfEnemy = L"��";
		break;
	case EnemyType::LIZARD:
		nameOfEnemy = L"������";
		break;
	case EnemyType::SLIME:
		nameOfEnemy = L"������";
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
		wcout << nameOfEnemy << L"�� ����!" << '\n';
		int damage = stat.strength;
		wcout << nameOfEnemy << L"�� " << damage << L"�� �������� �־���!" << '\n';
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
	wcout << nameOfEnemy << L"�� �����õ�!!" << '\n';

	srand((unsigned int)time(NULL));
	int success = rand() % 3 + 1;

	if (success == 1)
	{
		wcout << nameOfEnemy << L"�� �����ƴ�!" << '\n';
		wcout << nameOfEnemy << L"������ ����Ǿ���." << '\n';
	}
	else 
	{
		wcout << nameOfEnemy << L"�� �������µ��� �����ߴ�!" << '\n';
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
		wcout << nameOfEnemy << L"�� ȸ�������� ����Ͽ� ü���� 10 ȸ���Ǿ���!" << '\n';
	}
	break;
	case (int)EnemyItem::DAMAGEUPPOTION:
	{
		stat.strength += 5;
		wcout << nameOfEnemy << L"�� ������������ ����Ͽ� �������� 5 �����Ͽ���!" << '\n';
	}
	break;
	case (int)EnemyItem::AGILITYPOTION:
	{
		stat.agility += 5;
		wcout << nameOfEnemy << L"�� ȸ�������� ����Ͽ� ȸ��Ȯ���� 5 �����Ͽ���!" << '\n';
	}
	break;
	case (int)EnemyItem::ARMORPOTION:
	{
		stat.armor += 5;
		wcout << nameOfEnemy << L"�� ���� ������ ����Ͽ� ������ 5 �����Ͽ���!" << '\n';
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
		wcout << L"������� ��ų �ߵ�!" << '\n';
		Attack();
		Attack();
	}
	break;
	case (int)SkillType::ARMORUP:
	{
		wcout << nameOfEnemy << L"�� ���� ���� ��ų �ߵ�!" << '\n';
		stat.armor += 5;
		wcout << nameOfEnemy << L"�� ������ 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::AGILITYUP:
	{
		wcout << nameOfEnemy << L"�� ȸ�Ƿ� ���� ��ų �ߵ�!" << '\n';
		stat.agility += 5;
		wcout << nameOfEnemy << L"�� ȸ�Ƿ��� 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::DAMAGEUP:
	{
		wcout << nameOfEnemy << L"�� ���ݷ� ���� ��ų �ߵ�!" << '\n';
		stat.strength += 5;
		wcout << nameOfEnemy << L"�� ���ݷ��� 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::HEAL:
	{
		wcout << nameOfEnemy << L"�� ü�� ȸ�� ��ų �ߵ�!" << '\n';
		currentHp += 5;
		wcout << nameOfEnemy << L"�� ü���� 5 ȸ���Ǿ���." << '\n';
	}
	break;
	}

	int curmode = _setmode(_fileno(stdout), prevmode);
}
