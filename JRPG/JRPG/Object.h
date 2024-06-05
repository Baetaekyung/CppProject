#pragma once
struct Stat
{
    int strength; // ��
    int maxHealth; // ü��
    int agility; // ��ø��
    float ciritalChance; // ũ��Ƽ�� Ȯ��
    float ciritalDamage; // ũ��Ƽ�� ������
    int armor; // ���
};

class Object
{
public:
    virtual void Update() abstract;
    virtual void Render() abstract;
    virtual void Attack(Object target) abstract;
    virtual void Defence(int damage) abstract;
    virtual void RunAway() abstract;
    virtual void UseItem() abstract;
    virtual void UseSkill() abstract;
public:
    Stat stat;
    bool isPlayer = false;
};

