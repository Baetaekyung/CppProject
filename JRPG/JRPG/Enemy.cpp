#include "Enemy.h"

Enemy::Enemy(int health, int damage, int agility, int armor, int criticalPercent, int criticalMultiplier)
{
	_health = health;
	_damage = damage;
	_agility = agility;
	_armor = armor;
	_criticalPercent = criticalPercent;
	_criticalMultiplier = criticalMultiplier;
	_isCritical = false;
}

void Enemy::GetDamage(int damage)
{
	int applyDamage;
	applyDamage = (_armor - damage) < 0 ? (_armor - damage) : 1; // 방어력보다 공격력이 높으면 데미지가 들어가고 아니면 1의 데미지를 줌
	Enemy::SetHealth(Enemy::GetHealth() + applyDamage);
}
