/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <inttypes.h>

#include "dice.h"

// Putrid Rat
// Winged Rat
// Floating Skull
// Skeleton Archer
// Skeleton Warrior
// Necromancer

// Available monster types
enum monsterType
{
    putridRat,
    wingedRat,
    floatingSkull,
    skeletonArcher,
    skeletonWarrior,
    necromancer
};

// struct to hold monster data
struct tMonster
{
    char *name;
    uint8_t maxCount;
    rollFuncPtr witsDamage;
    uint8_t witsamageModifier;
    rollFuncPtr healthDamage;
    uint8_t healthDamageModifier;
    uint8_t maxlife;
};

// Struct to hold data for the monster that is currently in the room
struct tBattleMonster
{
    enum monsterType type;
    uint8_t count;
    uint8_t life;
};

// Function prototypes
uint8_t getMonsterWitsDamage(struct tBattleMonster *battleMonster);
uint8_t getMonsterHealthDamage(struct tBattleMonster *battleMonster);
char * getMonsterName(struct tBattleMonster *battleMonster);
enum monsterType generateMonsterType();
void generateRoomMonsters(struct tBattleMonster *battleMonster);
uint8_t doDamageToMonster(struct tBattleMonster *battleMonster, uint8_t damage);

#endif /* __MONSTER_H__ */