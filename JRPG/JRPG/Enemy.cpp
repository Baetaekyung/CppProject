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

	cout << "이 " << damage << " 만큼의 공격을 받았다!!" << '\n';
	cout << "의 남은 체력은 " << currentHp << "이다.";
}

void Enemy::Dead()
{
	isDead = true;
	cout << "의 체력이 0이 되었다..." << '\n';
	cout << "전투가 종료되었다." << '\n';
}

void Enemy::Update()
{
	if (isDead) return;
	if (!enemyTurn) return;
	
	srand((unsigned int)time(NULL));
	int randNum = rand() % 3 + 1;
	cout << randNum << endl;

	cout << "의 턴이다." << '\n';

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
	cout <<  "의 공격력: " << stat.strength << '\n';
	cout << "의 현재 체력: " << currentHp << '\n';
	cout << "의 방어력: " << stat.armor << '\n';
	cout << "의 회피력: " << stat.agility << '\n';
	cout << "의 치명타 확률: " << stat.ciritalChance << '\n';
	cout << "의 치명타 데미지: " << stat.ciritalDamage << '\n';
	cout << "◈" << '\n';
}

void Enemy::Attack()
{
	srand((unsigned int)time(NULL));
	int randNum = rand() % 2 + 1;
	
	if (randNum == 1)
	{
		cout << "의 공격!" << '\n';
		int damage = stat.strength;
		cout << "이 " << damage << "의 데미지를 주었다!" << '\n';
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
	cout << "의 도망시도!!" << '\n';

	srand((unsigned int)time(NULL));
	int success = rand() % 3 + 1;

	if (success == 1)
	{
		cout << "이 도망쳤다!" << '\n';
		cout << "전투가 종료되었다." << '\n';
	}
	else 
	{
		cout << "이 도망가는데에 실패했다!" << '\n';
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
		cout << "이 회복포션을 사용하여 체력이 10 회복되었다!" << '\n';
	}
	break;
	case (int)EnemyItem::DAMAGEUPPOTION:
	{
		stat.strength += 5;
		cout << "이 데미지포션을 사용하여 데미지가 5 증가하였다!" << '\n';
	}
	break;
	case (int)EnemyItem::AGILITYPOTION:
	{
		stat.agility += 5;
		cout << "이 회피포션을 사용하여 회피확률이 5 증가하였다!" << '\n';
	}
	break;
	case (int)EnemyItem::ARMORPOTION:
	{
		stat.armor += 5;
		cout << "이 방어력 포션을 사용하여 방어력이 5 증가하였다!" << '\n';
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
		cout << "더블어택 스킬 발동!" << '\n';
		Attack();
		Attack();
	}
	break;
	case (int)SkillType::ARMORUP:
	{
		cout <<  "의 방어력 증가 스킬 발동!" << '\n';
		stat.armor += 5;
		cout <<  "의 방어력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::AGILITYUP:
	{
		cout <<  "의 회피력 증가 스킬 발동!" << '\n';
		stat.agility += 5;
		cout <<  "의 회피력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::DAMAGEUP:
	{
		cout <<  "의 공격력 증가 스킬 발동!" << '\n';
		stat.strength += 5;
		cout << "의 공격력이 5 증가 하였다." << '\n';
	}
	break;
	case (int)SkillType::HEAL:
	{
		cout << "의 체력 회복 스킬 발동!" << '\n';
		currentHp += 5;
		cout << "의 체력이 5 회복되었다." << '\n';
	}
	break;
	}
}
