#pragma once
class Enemy
{
public:
	Enemy(int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier);
private:
	int _health; // ü��
	int _damage; // ���ݷ�
	int _agility; // ȸ��Ȯ��
	int _armor; // ����
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

