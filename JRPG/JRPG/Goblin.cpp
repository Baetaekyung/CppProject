#include "Goblin.h"

Goblin::Goblin(Stat goblinStat)
{
	stat.agility = goblinStat.agility;
	stat.armor = goblinStat.armor;
	stat.ciritalChance = goblinStat.ciritalChance;
	stat.ciritalDamage = goblinStat.ciritalDamage;
	stat.maxHealth = goblinStat.maxHealth;
	stat.strength = goblinStat.strength;

	currentHp = stat.maxHealth;

	enemyType = EnemyType::GOBLIN;

	nameOfEnemy = L"°íºí¸°";
}