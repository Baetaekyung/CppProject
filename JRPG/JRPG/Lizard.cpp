#include "Lizard.h"

Lizard::Lizard(Stat lizardStat)
{
	stat.agility = lizardStat.agility;
	stat.armor = lizardStat.armor;
	stat.ciritalChance = lizardStat.ciritalChance;
	stat.ciritalDamage = lizardStat.ciritalDamage;
	stat.maxHealth = lizardStat.maxHealth;
	stat.strength = lizardStat.strength;

	currentHp = stat.maxHealth;

	enemyType = EnemyType::LIZARD;

	nameOfEnemy = L"µµ¸¶¹ì";
}
