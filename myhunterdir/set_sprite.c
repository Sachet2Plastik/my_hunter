/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** set_knight
*/

#include "../include/my.h"

void set_knight(set_wind_t *wind, setsprite_t knight)
{
    wind->knight_pos.x = 0, wind->knight_pos.y = 740;
    wind->knight_speed.x = 5, wind->knight_speed.y = 0;
    sfSprite_setPosition(knight.sprite, wind->knight_pos);
}

void set_drak(set_wind_t *wind, setsprite_t drak)
{
    wind->drak_pos.x = 0, wind->drak_pos.y = 10;
    wind->drak_speed.x = 6, wind->drak_speed.y = 3;
    sfSprite_setPosition(drak.sprite, wind->drak_pos);
}
