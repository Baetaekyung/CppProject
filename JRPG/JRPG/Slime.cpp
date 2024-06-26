#include "Slime.h"

Slime::Slime(Stat slimeStat)
{
	stat.agility = slimeStat.agility;
	stat.armor = slimeStat.armor;
	stat.ciritalChance = slimeStat.ciritalChance;
	stat.ciritalDamage = slimeStat.ciritalDamage;
	stat.maxHealth = slimeStat.maxHealth;
	stat.strength = slimeStat.strength;

	currentHp = stat.maxHealth;

	enemyType = EnemyType::SLIME;

	nameOfEnemy = L"ΩΩ∂Û¿”";
}
