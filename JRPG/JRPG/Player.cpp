#include "Player.h"

Player::Player(Stat stat)
{
	_playerstat = stat;
	_currnetHealth = stat.maxHealth;
	_objectType = ObejectType::Player;
	Skill strongAttack = Skill(L"강공격", 20);
	Skill sting = Skill(L"내려찍기", 20);
	skills.push_back(strongAttack);
	skills.push_back(sting);
}

void Player::AttackTarget(Enemy enemy)
{
	if (rand() % 100 + 1 <= _playerstat.ciritalChance) {
		enemy.Defence(_playerstat.ciritalDamage);
	}
	else {
		enemy.Defence(_playerstat.strength);
	}
}

void Player::Update()
{ 

}

void Player::Render()
{

}

void Player::Attack()
{

}

void Player::Defence(int damage)
{
	int applyDamage =
		(damage - _playerstat.armor) > 1 ? (damage - _playerstat.armor) : 1;
	
	_currnetHealth -= damage;

	if (_currnetHealth <= 0)
	{
		//Dead();
		return;
	}
}

void Player::UseItem()
{

}

void Player::UseSkill()
{

}

Skill::Skill(wstring name, int damage)
{
	this->name = name;
	this->damage = damage;
}
