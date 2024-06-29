#include "Player.h"

Player::Player(Stat stat)
{
	_playerstat = stat;
	_currnetHealth = stat.maxHealth;
	_objectType = ObejectType::Player;
	Skill strongAttack = Skill(L"강공격", 20);
	Skill sting = Skill(L"내려찍기", 20);
	Item item = Item(L"회복초", 100);
	skills.push_back(strongAttack);
	skills.push_back(sting);
	itmes.push_back(item);
}

void Player::AttackTarget()
{
	//if (rand() % 100 + 1 <= _playerstat.ciritalChance) {
	//	enemy.Defence(_playerstat.ciritalDamage);
	//}
	//else {
	//	enemy.Defence(_playerstat.strength);
	//}
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
	if (_isDefence)
	{
		_isDefence = false;
		return;
	}

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
	_currnetHealth += itmes[0]._value;
}

Skill::Skill(wstring name, int damage)
{
	this->name = name;
	this->damage = damage;
}
