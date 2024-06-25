#include "Object.h"
#include "Player.h"

Player::Player(Stat stat)
{
	this->_stat = stat;
	_currnetHealth = stat.maxHealth;
	_objectType = ObejectType::Player;
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

}

void Player::UseItem()
{

}

void Player::UseSkill()
{

}
