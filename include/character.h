/* 
 * Copyright 2020 Xander Soldaat <xander@botbench.com>
 */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <inttypes.h>

#include "dice.h"

enum character_race
{
    race_human,
    race_halfling,
    race_dwarf,
    race_elf
};

enum character_class
{
    class_fighter,
    class_ranger,
    classs_wizard,
    class_bard
};

enum item_type
{
    item_none,
    item_melee_weapon,
    item_ranged_weapon,
    item_armour,
    item_consumable,
};

enum melee_weapon_sub_type
{
    item_melee_dagger,
    item_melee_shortSword,
    item_melee_handAxe,
    item_melee_greatSword,
    item_melee_greatAxe,
};

enum ranged_weapon_sub_type
{
    item_ranged_throwingStar,
    item_ranged_rockSling,
    item_ranged_shortbow,
    item_ranged_longbow,
    item_ranged_crossbow,
};

enum amour_sub_type
{
    item_armour_shield,
    item_armour_magicCap,
    item_armour_cloak,
    item_armour_chainmail,
    item_armour_blessedArmour,
};

enum consumable_sub_type
{
    item_consumable_breadCrust,
    item_consumable_ale,
    iten_consumable_potion,
    item_consumable_holywater,
    item_consumable_miracle
};

struct equipment_item_data
{
    char *description;
    enum item_type type;
    uint8_t cost;
};

struct equipment_item_melee_eapon_data
{
    char *description;
    enum item_type type;
    uint8_t cost;
    enum melee_weapon_sub_type weapon;
    rollFuncPtr weaponDamageroll;
};



struct tCharacter
{
    char * description;
    
};

struct tBattleCharacter
{
    char name[32];
    
    enum character_race race;
    enum character_class class;



};

#endif /* __CHARACTER_H__ */