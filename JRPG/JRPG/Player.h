#pragma once

struct PlayerStat
{
	int strength; // ��
	int	maxHealth; // ü��
	int agility; // ��ø��
	float ciritalChance; // ũ��Ƽ�� Ȯ��
	float ciritalDamage; // ũ��Ƽ�� ������
	int armor; // ���
};

class Player
{
public:
	PlayerStat _stat; // ����
	int _currnetHealth; // ���� ü��
	
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

