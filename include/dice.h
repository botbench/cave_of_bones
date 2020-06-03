/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#ifndef __DICE_H__
#define __DICE_H__

typedef int (*rollFuncPtr)(int);

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

uint16_t randrange(int16_t min, int16_t max);
void init_dice(void);
uint8_t roll_d6(int8_t modifier);
uint8_t roll_2d6(int8_t modifier);
uint8_t roll_d3(int8_t modifier);
uint8_t roll_none(int8_t modifier);

#endif /* __DICE_H__ */