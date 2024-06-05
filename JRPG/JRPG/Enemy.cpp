#include "Object.h"
#include "Enemy.h"

Enemy::Enemy(int health, int damage, int agility, int armor, int criticalPercent, int criticalMultiplier)
{
	stat.maxHealth = health;
	stat.strength = damage;
	stat.agility = agility;
	stat.armor = armor;
	stat.ciritalChance = criticalPercent;
	stat.ciritalDamage = criticalMultiplier;
}

void Enemy::GetDamage(int damage)
{
	
}

void Enemy::Update()
{

}

void Enemy::Render()
{

}

void Enemy::Attack(IDamageable target)
{

}

void Enemy::Defence(int damage)
{

}

void Enemy::RunAway()
{

}

void Enemy::UseItem()
{

}

void Enemy::UseSkill()
{

}
