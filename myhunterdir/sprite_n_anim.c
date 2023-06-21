/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** sprite creation file
*/

#include "../include/my.h"
#include <math.h>
#include <stdlib.h>

int knight_anime(set_wind_t *wind, setsprite_t *knight,\
setsprite_t *game_bg, int i)
{
    if (i == 360)
        i = 0;
    sfIntRect rect = {0 + i, 0, 95, 100};
    i += 90;
    sfSprite_setTextureRect(knight->sprite, rect);
    sfRenderWindow_drawSprite(wind->window, game_bg->sprite, NULL);
    sfRenderWindow_drawSprite(wind->window, knight->sprite, NULL);
    return (i);
}

int drake_anime(set_wind_t *wind, setsprite_t *drak,\
setsprite_t *game_bg, int j)
{
    if (j == 450)
        j = 0;
    sfIntRect rect = {0 + j, 0, 150, 95};
    j += 150;
    sfSprite_setTextureRect(drak->sprite, rect);
    sfRenderWindow_drawSprite(wind->window, drak->sprite, NULL);
    return (j);
}

void sprite_move(set_wind_t *wind, setsprite_t drak, setsprite_t knight)
{
    wind->drak_speed.x = (sin(wind->frames) * 15) + wind->drak_velocity.x;
    wind->drak_speed.y = ((sin(wind->frames) * 15) * -0.55)\
    + wind->drak_velocity.y;
    sfSprite_move(knight.sprite, wind->knight_speed);
    sfSprite_move(drak.sprite, wind->drak_speed);
}

void set_sprite(setsprite_t *setsprite, char *filepath)
{
    setsprite->text = sfTexture_createFromFile(filepath, NULL);
    setsprite->sprite = sfSprite_create();
    sfSprite_setTexture(setsprite->sprite, setsprite->text, sfTrue);
}
