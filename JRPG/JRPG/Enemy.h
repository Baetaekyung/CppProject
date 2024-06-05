#pragma once
class Enemy : public Object
{
public:
	Enemy(int health, int damage,
		int agility, int armor,
		int criticalPercent, int criticalMultiplier);
public:
	void GetDamage(int damage);

	// Object을(를) 통해 상속됨
	void Update() override;

	void Render() override;

	void Attack() override;

	void Defence(int damage) override;

	void RunAway() override;

	void UseItem() override;

	void UseSkill() override;
public:
	Stat stat;
};

