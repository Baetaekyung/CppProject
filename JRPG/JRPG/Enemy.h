#pragma once
class Enemy
{
public:
	Enemy(int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier);
private:
	int _health; // 체력
	int _damage; // 공격력
	int _agility; // 회피확률
	int _armor; // 방어력
	int _criticalPercent;
	bool _isCritical;
	float _criticalMultiplier;
public:
	int GetHealth()
	{
		return _health;
	}
	void SetHealth(int health)
	{
		_health = health;
	}
	void GetDamage(int damage);
};

