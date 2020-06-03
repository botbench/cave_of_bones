/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include "room.h"

// Room types with modifiers
struct tRoom rooms[] = {          // Modifier for the rolls
    // description                   Dext   Wits    Char    Stren
    {"This room has a dirt floor",   0,     0,      0,      0},
    {"This room is muddy",           1,     0,      0,      0},
    {"This room has water in it",    0,     0,      0,      1},
    {"This room has a stone floor",  0,     0,      0,      0},
    {"This room is a crypt",         0,     1,      0,      0},
    {"This room has an altar",       0,     0,      1,      0},
};

/**
 * @brief  Generate a room with all the wall, doors, monsters, etc.
 * @note   
 * @retval None
 */
void generateRoom(struct tBattleRoom *room)
{
    room->type = roll_d6(-1);
    room->doorCount = roll_d3(0);
    for (int i = 0; i < room->doorCount; i++)
        room->doorTypes[i] = generateDoor();
    generateRoomMonsters(&room->monster);
    room->size = roll_d6(0);
    return;
}

char * getRoomDescription(struct tBattleRoom *room)
{
    return rooms[room->type].description;
}