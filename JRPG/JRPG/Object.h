#pragma once

#pragma region Enum
enum class DamageType
{
    Melee,
    Range,
    Magic
};
#pragma endregion

#pragma region Struct
struct Stat
{
    int strength; // ��
    int    maxHealth; // ü��
    int agility; // ��ø��
    float ciritalChance; // ũ��Ƽ�� Ȯ��
    float ciritalDamage; // ũ��Ƽ�� ������
    int armor; // ���
};
#pragma endregion

class Object
{
public:
    virtual void Update() abstract;
    virtual void Render() abstract;
    virtual void Attack(IDamageable target) abstract;
    virtual void Defence(int damage) abstract;
    virtual void RunAway() abstract;
    virtual void UseItem() abstract;
    virtual void UseSkill() abstract;
public:

public:
    bool isPlayer = false;
};

class IDamageable {
public:
    void ApplyDamage(int damage, DamageType damageType);
public:
    bool _canAttack;
    IDamageable();
};

