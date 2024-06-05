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
	applyDamage = (_armor - damage) < 0 ? (_armor - damage) : 1; // ���º��� ���ݷ��� ������ �������� ���� �ƴϸ� 1�� �������� ��
	Enemy::SetHealth(Enemy::GetHealth() + applyDamage);
}
