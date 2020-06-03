/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#ifndef __DOOR_H__
#define __DOOR_H__

#include <inttypes.h>

#include "common.h"
#include "dice.h"

enum doorType
{
    door_unlocked,
    door_stuck,
    door_locked,
    door_trapped
};

struct tDoor
{
    char *description;
    int8_t mustRoll;
    int8_t mayRepeat;
    enum checkType check;
    rollFuncPtr damageRoll;
};

enum doorType generateDoor(void);
char * getDoorDescription(enum doorType type);
enum checkType getDoorCheck(enum doorType type);
uint8_t mustRollForOpen(enum doorType type);
uint8_t mayRepeatOpenCheck(enum doorType type);
uint8_t getDoorDamage(enum doorType type);

#endif /* __DOOR_H__ */