#pragma once
class Enemy : public Object
{
public:
	Enemy(int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier);
public:
	void GetDamage(int damage);
public:
	Stat stat;

	// Object��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	void Attack(IDamageable target) override;
	void Defence(int damage) override;
	void RunAway() override;
	void UseItem() override;
	void UseSkill() override;
};

