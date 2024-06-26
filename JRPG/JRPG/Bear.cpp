#include "Enemy.h"
#include "Bear.h"

Bear::Bear(Stat bearStat)
{
	stat.maxHealth = bearStat.maxHealth;
	stat.strength = bearStat.strength;
	stat.agility = bearStat.agility;
	stat.armor = bearStat.armor;
	stat.ciritalChance = bearStat.ciritalChance;
	stat.ciritalDamage = bearStat.ciritalDamage;

	currentHp = stat.maxHealth;

	enemyType = EnemyType::BEAR;

	nameOfEnemy = L"°õ";
}
