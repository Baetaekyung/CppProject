#pragma once
class Enemy : public Object
{
public:
	Enemy(int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier);
public:
	void GetDamage(int damage);
};

