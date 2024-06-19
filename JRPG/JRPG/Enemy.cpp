#include "Object.h"
#include "Enemy.h"
#include "Console.h"

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
}

void Enemy::GetDamage(int damage)
{
	currentHp -= damage;

	if (currentHp <= 0)
	{
		Dead();
		return;
	}

	cout << "�� " << damage << " ��ŭ�� ������ �޾Ҵ�!!" << '\n';
	cout << "�� ���� ü���� " << currentHp << "�̴�.";
}

void Enemy::Dead()
{
	isDead = true;
	cout << "�� ü���� 0�� �Ǿ���..." << '\n';
	cout << "������ ����Ǿ���." << '\n';
}

void Enemy::Update()
{
	if (isDead) return;
	if (!enemyTurn) return;
	
	srand((unsigned int)time(NULL));
	int randNum = rand() % 3 + 1;
	cout << randNum << endl;

	cout << "�� ���̴�." << '\n';

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
	cout <<  "�� ���ݷ�: " << stat.strength << '\n';
	cout << "�� ���� ü��: " << currentHp << '\n';
	cout << "�� ����: " << stat.armor << '\n';
	cout << "�� ȸ�Ƿ�: " << stat.agility << '\n';
	cout << "�� ġ��Ÿ Ȯ��: " << stat.ciritalChance << '\n';
	cout << "�� ġ��Ÿ ������: " << stat.ciritalDamage << '\n';
	cout << "��" << '\n';
}

void Enemy::Attack()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 2 + 1;
	
	if (randNum == 1)
	{
		cout << "�� ����!" << '\n';
		int damage = stat.strength;
		cout << "�� " << damage << "�� �������� �־���!" << '\n';
	}
	else
	{
		UseSkill();
	}
}

void Enemy::Defence(int damage)
{
	int applyDamage = 
		(damage - stat.armor) > 1 ? (damage - stat.armor) : 1;
	GetDamage(applyDamage);
}

void Enemy::RunAway()
{
	cout << "�� �����õ�!!" << '\n';

	srand((unsigned int)time(NULL));
	int success = rand() % 3 + 1;

	if (success == 1)
	{
		cout << "�� �����ƴ�!" << '\n';
		cout << "������ ����Ǿ���." << '\n';
	}
	else 
	{
		cout << "�� �������µ��� �����ߴ�!" << '\n';
	}
}

void Enemy::UseItem()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 4 + 1;

	switch (randNum)
	{
	case (int)EnemyItem::HEALTHPOTION:
	{
		currentHp += 10;
		cout << "�� ȸ�������� ����Ͽ� ü���� 10 ȸ���Ǿ���!" << '\n';
	}
	break;
	case (int)EnemyItem::DAMAGEUPPOTION:
	{
		stat.strength += 5;
		cout << "�� ������������ ����Ͽ� �������� 5 �����Ͽ���!" << '\n';
	}
	break;
	case (int)EnemyItem::AGILITYPOTION:
	{
		stat.agility += 5;
		cout << "�� ȸ�������� ����Ͽ� ȸ��Ȯ���� 5 �����Ͽ���!" << '\n';
	}
	break;
	case (int)EnemyItem::ARMORPOTION:
	{
		stat.armor += 5;
		cout << "�� ���� ������ ����Ͽ� ������ 5 �����Ͽ���!" << '\n';
	}
	break;
	}
}

void Enemy::UseSkill()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 5 + 1;

	switch (randNum)
	{
	case (int)SkillType::DOUBLEATTACK:
	{
		cout << "������� ��ų �ߵ�!" << '\n';
		Attack();
		Attack();
	}
	break;
	case (int)SkillType::ARMORUP:
	{
		cout <<  "�� ���� ���� ��ų �ߵ�!" << '\n';
		stat.armor += 5;
		cout <<  "�� ������ 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::AGILITYUP:
	{
		cout <<  "�� ȸ�Ƿ� ���� ��ų �ߵ�!" << '\n';
		stat.agility += 5;
		cout <<  "�� ȸ�Ƿ��� 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::DAMAGEUP:
	{
		cout <<  "�� ���ݷ� ���� ��ų �ߵ�!" << '\n';
		stat.strength += 5;
		cout << "�� ���ݷ��� 5 ���� �Ͽ���." << '\n';
	}
	break;
	case (int)SkillType::HEAL:
	{
		cout << "�� ü�� ȸ�� ��ų �ߵ�!" << '\n';
		currentHp += 5;
		cout << "�� ü���� 5 ȸ���Ǿ���." << '\n';
	}
	break;
	}
}
