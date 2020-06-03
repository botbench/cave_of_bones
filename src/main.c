/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include <stdio.h>
#include <stdlib.h>

#include "cave.h"
#include "dice.h"
#include "room.h"
#include "monster.h"

#define CLEAR_SCREEN "2J"
#define HOME    "H"

int main(int argc, char ** argv)
{
    printf ("\033[%s", HOME);
    printf ("\033[%s", CLEAR_SCREEN);

    enterCave();

    return 0;
}
