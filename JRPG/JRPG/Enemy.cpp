#include "Object.h"
#include "Enemy.h"

Enemy::Enemy(int health, int damage, int agility, int armor, int criticalPercent, int criticalMultiplier)
{
	Stat::maxHealth = health;
}

void Enemy::GetDamage(int damage)
{
	
}
