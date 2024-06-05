#pragma once
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
    struct Stat
    {
        int strength; // 힘
        int    maxHealth; // 체력
        int agility; // 민첩성
        float ciritalChance; // 크리티컬 확률
        float ciritalDamage; // 크리티컬 데미지
        int armor; // 방어
    };
public:
    bool isPlayer = false;
};

