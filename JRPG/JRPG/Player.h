#pragma once

struct PlayerStat
{
	int strength; // 힘
	int	maxHealth; // 체력
	int agility; // 민첩성
	float ciritalChance; // 크리티컬 확률
	float ciritalDamage; // 크리티컬 데미지
	int armor; // 방어
};

class Player
{
public:
	PlayerStat _stat; // 스탯
	int _currnetHealth; // 현재 체력
	
	Player(PlayerStat stat) {
		this->_stat = stat;
		_currnetHealth = stat.maxHealth;
	}
	
	bool Attack() {

	}
	bool Defense(int damage) {
		if (damage <= _stat.armor) {
			--_currnetHealth;
		}
		else {
			_currnetHealth -= (damage - _stat.armor);
		}
	}
private:
};

