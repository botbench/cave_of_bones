/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#include <inttypes.h>
#include <limits.h>
#include <stdio.h>

#include "dice.h"

// Store the seed
static uint16_t seed = 0;

static uint8_t seeded = 0;
/**
 * @brief  Get the value of the R register, to seed the PRNG
 * @retval uint8_t - the value of the R register
 */
static uint8_t get_r(void)
{
    // printf("get_r\n");
    __asm
      ld a,r
      ld l,a
    __endasm;
}

/**
 * @brief  xorshift PRNG algorithm
 * @retval uint16_t - the random number, which is also the seed for the next round
 */
static uint16_t xorshift()
{
    // printf("xorshift\n");
    if (seed == 0)
        seed = UINT_MAX;

    seed ^= seed << 7;
    seed ^= seed >> 9;
    seed ^= seed << 8;
    return seed;
}

/**
 * @brief  Initialise the seed, uses the R register
 */
void init_dice(void)
{
    // printf("init_dice\n");
    seed  = get_r();
    seeded = 1;
}

/**
 * @brief  Generate a random number, using xorshift PRNG
 * @param  int16_t min: minimum number of the range
 * @param  int16_t max: maximum number of the range
 * @retval uint16_t - the rnadom number
 */
uint16_t randrange(int16_t min, int16_t max)
{
    // printf("randrange: min: %d, max: %d\n", min, max);
    if (!seeded)
        init_dice();
    return min + xorshift() / (UINT_MAX / (max - min + 1) + 1);
}

/**
 * @brief  Roll a D6
 * @param  int8_t modifier:  number to add or subtract to dice roll
 * @retval uint8_t the dice roll + modifier
 */
uint8_t roll_d6(int8_t modifier)
{
    // printf("roll_d6: modif: %d\n", modifier);
    return randrange(1, 6) + modifier;
}

/**
 * @brief  Roll two D6s
 * @param  int8_t modifier:  number to add or subtract to dice rolls
 * @retval uint8_t the dice rolls + modifier
 */
uint8_t roll_2d6(int8_t modifier)
{
    // printf("roll_2d6: modif: %d\n", modifier);
    return roll_d6(0) + roll_d6(modifier);
}

/**
 * @brief  Roll a D3
 * @param  int8_t modifier:  number to add or subtract to dice roll
 * @retval uint8_t the dice roll + modifier
 */
uint8_t roll_d3(int8_t modifier)
{
    // printf("roll_d3: modif: %d\n", modifier);
    return randrange(1, 3) + modifier;
}

/**
 * @brief  Roll nothing, this is for convenience.
 * @param  int8_t modifier:  number to return
 * @retval uint8_t the modifier
 */
uint8_t roll_none(int8_t modifier)
{
    // printf("roll_none: modif: %d\n", modifier);
    return modifier;
}

/**
 * @brief  Roll two D6s and pick the best
 * @param  int8_t modifier:  number to return
 * @retval uint8_t the modifier
 */
uint8_t roll_prof(int8_t modifier)
{
    // printf("roll_none: modif: %d\n", modifier);
    uint8_t dice1 = roll_d6(modifier);
    uint8_t dice2 = roll_d6(modifier);

    return MAX(dice1, dice2);
}