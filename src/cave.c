/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include <stdio.h>

#include "room.h"

struct roomEntry *currentRoomEntry;
struct tBattleRoom *currentRoom;

struct roomEntry
{
    struct tBattleRoom room;
};

struct roomEntry roomEntryList[127];

void enterCave(void)
{
    currentRoomEntry = &roomEntryList[0];
    currentRoom = &currentRoomEntry->room;

    printf ("You have entered the cave. You blink as your eyes adjust to the darkness.\n");
    generateRoom(currentRoom);
    printf ("%s, it has %d doors and is %d squares big. The monster is %d %s, with %d HP each\n", 
        getRoomDescription(currentRoom), 
        currentRoom->doorCount, 
        currentRoom->size, 
        currentRoom->monster.count, 
        getMonsterName(&currentRoom->monster), 
        currentRoom->monster.life);

    printf ("The following doors can be seen:\n");
        for (int i = 0; i < currentRoom->doorCount; i++)
            printf ("\t%s\n", getDoorDescription(currentRoom->doorTypes[i]));
}

void enterNextCaveRoom()
{

}

void doBattle()
{

}

void attemptDoor()
{

}

