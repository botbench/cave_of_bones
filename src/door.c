/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include <stdio.h>

#include "door.h"

struct tDoor doors[] =
{   // Description  roll    repeat  check           dmg_roll
    {"unlocked",    0,      0,      noCheck,        roll_none},
    {"stuck",       1,      1,      strengthCheck,  roll_none},
    {"locked",      1,      1,      witsCheck,      roll_none},
    {"trapped",     1,      0,      witsCheck,      roll_d3},
};

enum doorType generateDoor(void)
{
    switch (roll_d6(0))
    {
        case 6:
        case 5:     return door_unlocked;
        case 4:     return door_stuck;
        case 3:     return door_locked;
        default:    return door_trapped;
    }
}

char * getDoorDescription(enum doorType type)
{
    return doors[type].description;
}

enum checkType getDoorCheck(enum doorType type)
{
    return doors[type].check;
}

uint8_t mustRollForOpen(enum doorType type)
{
    return doors[type].mustRoll;
}

uint8_t mayRepeatOpenCheck(enum doorType type)
{
    return doors[type].mayRepeat;
}

uint8_t getDoorDamage(enum doorType type)
{
    doors[type].damageRoll(0);
}
