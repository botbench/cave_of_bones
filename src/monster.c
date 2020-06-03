/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include <stdlib.h>
#include <stdio.h>

#include "monster.h"

// Array of structs of all the available monsters and their default values
struct tMonster monsters[] = {
    {"Putrid Rat",      6, roll_none,  1,  roll_none,  1,  1},     // putridRat
    {"Winged Rat",      6, roll_none,  1,  roll_d3,    0,  2},     // wingedRat
    {"Floating Skull",  5, roll_d3,    0,  roll_d3,    1,  5},     // floatingSkull
    {"Skeleton Archer", 4, roll_d3,    1,  roll_d3,    1,  7},     // skeletonArcher
    {"Skeleton Warrior",3, roll_d6,    0,  roll_d6,    0,  1},     // skeletonWarrior
    {"Necromancer",     1, roll_d6,    1,  roll_d6,    1,  2}      // necromancer
};

// Keep track of all of the monster fights we've had.
uint8_t monsterFights[6] = {0};

/**
 * @brief  Get the amount of Wits damage this monster can do
 * @param  struct tBattleMonster*: pointer to monster
 * @retval uint8_t
 */
uint8_t getMonsterWitsDamage(struct tBattleMonster *battleMonster)
{
    enum monsterType monster = battleMonster->type;
    return (*monsters[monster].witsDamage)(monsters[monster].witsamageModifier);
}

/**
 * @brief  Get the amount of Health damage this monster can do
 * @param  struct tBattleMonster*: pointer to monster
 * @retval uint8_t
 */
uint8_t getMonsterHealthDamage(struct tBattleMonster *battleMonster)
{
    enum monsterType monster = battleMonster->type;
    return (*monsters[monster].healthDamage)(monsters[monster].healthDamageModifier);
}

/**
 * @brief  Get the English name of the monster
 * @param  struct tBattleMonster*: pointer to monster
 * @retval char *
 */
char * getMonsterName(struct tBattleMonster *battleMonster)
{
    enum monsterType monster = battleMonster->type;
    return monsters[monster].name;
}

/**
 * @brief  Generate a random monster type
 * @note   This won't generate a necromancer until all other monster types have been defeated at least once
 * @retval enum monsterType
 */
enum monsterType generateMonsterType()
{
    // Loop until we find a suitable monster to fight
    while(1==1)
    {
        // Roll for a ranom monster
        enum monsterType tmpMonster = roll_d6(-1);

        // Special check for the necromancer. We can't fight him
        // until we've fought at least one of each other type of enemy
        if (tmpMonster == necromancer)
        {
            int bossfightTime = 0;
            for (int i = 0; i < 5; i++)
            {
                if (monsterFights[i] > 0)
                    bossfightTime++;
                else
                    break;
            }
            // If we've fought 5 different enemies, we can fight the big bad necromancer
            if (bossfightTime == 5)
            {
                monsterFights[tmpMonster]++;
                return tmpMonster;
            }
        }
        else 
        {
            monsterFights[tmpMonster]++;
            return tmpMonster;
        }
    }
}

/**
 * @brief  Generate a monser or group of them, for a room
 * @param  struct tBattleMonster*: pointer to monster
 */
void generateRoomMonsters(struct tBattleMonster *battleMonster)
{
    enum monsterType roomMonster = generateMonsterType();
    uint8_t count = roll_d6(0);

    // Don't put more monsters in the room than necessary
    if (count > monsters[roomMonster].maxCount)
        count = monsters[roomMonster].maxCount;

    battleMonster->type = roomMonster;
    battleMonster->count = count;
    battleMonster->life = monsters[roomMonster].maxlife;

    // printf("generateRoomMonsters: type %d, count: %d, life: %d\n", battleMonster->type, battleMonster->count, battleMonster->life);
}

/**
 * @brief  Do some damage to a (group of) monster(s)
 * @param  struct tBattleMonster*: pointer to monster
 * @param  uint8_t damage: amount of damage to inflict
 * @retval uint8_t number of monsters left.
 */
uint8_t doDamageToMonster(struct tBattleMonster *battleMonster, uint8_t damage)
{
    // Do nothing if the monster is already dead
    if (battleMonster->count == 0)
        return 0;
    // Killed the monster, reduce the total by one
    else if (battleMonster->life < damage)
        battleMonster->count--;
    // Didn't kill it, so reduce HP
    else 
        battleMonster->life -= damage;
    
    // Return possibly updated count of monsters
    return battleMonster->count;
}