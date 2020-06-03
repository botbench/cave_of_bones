/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#ifndef __ROOM_H__
#define __ROOM_H__

#include <inttypes.h>

#include "monster.h"
#include "door.h"

enum roomType
{
    room_dirt,
    room_muddy,
    room_watery,
    room_stone,
    room_crypt,
    room_altar,
};

struct tRoom
{
    char *description;
    int8_t dexterityModifier;
    int8_t witsModifier;
    int8_t charismaModifier;
    int8_t strengthMofifier;
};

struct tBattleRoom
{
    enum roomType type;
    struct tBattleMonster monster;
    int8_t size;
    int8_t doorCount;
    enum doorType doorTypes[3];
};

void generateRoom(struct tBattleRoom *room);
char * getRoomDescription(struct tBattleRoom *room);

#endif /* __ROOM_H__ */
