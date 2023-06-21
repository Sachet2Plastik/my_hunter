/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** game_condition
*/

#include "../include/my.h"
#include <stdio.h>

void start_clicked(set_wind_t *wind, setsprite_t *menu)
{
    if (wind->event.type == sfEvtMouseButtonPressed) {
        setsprite_t game_bg, knight, drak;
        wind->music = sfMusic_createFromFile("asset/Doom_8bitmusic.ogg");
        sfTexture_destroy(menu->text);
        sfSprite_destroy(menu->sprite);
        set_sprite(&game_bg,"asset/castle_background.png");
        set_sprite(&knight,"asset/sprite knight.png");
        set_sprite(&drak,"asset/Dragon_Sprite.png");
        sfMusic_play(wind->music);
        game_loop(wind, game_bg, knight, drak);
    }
}

void if_click(set_wind_t *wind, setsprite_t *menu)
{
    if (wind->Jerry_Coords.x >= 355 && wind->Jerry_Coords.x <= 521)
        if (wind->Jerry_Coords.y >= 244 && wind->Jerry_Coords.y <= 305)
            start_clicked(wind, menu);
}

void game_over(setsprite_t knight, set_wind_t *wind,\
setsprite_t drak, setsprite_t game_bg)
{
    sfFloatRect const knight_box = sfSprite_getGlobalBounds(knight.sprite);
    sfFloatRect const drak_box = sfSprite_getGlobalBounds(drak.sprite);
    if (knight_box.left >= 1480 || drak_box.left >= 1480){
        sfMusic_destroy(wind->music);
        sfTexture_destroy(knight.text);
        sfTexture_destroy(drak.text);
        sfTexture_destroy(game_bg.text);
        sfRenderWindow_close(wind->window);
    }
}

void hit(setsprite_t knight, set_wind_t *wind, setsprite_t drak)
{
    sfFloatRect const knight_box = sfSprite_getGlobalBounds(knight.sprite);
    sfFloatRect const drak_box = sfSprite_getGlobalBounds(drak.sprite);
    if (sfFloatRect_intersects(&knight_box, &wind->Jerry_Hitbox, NULL) == sfTrue
    && wind->klik == sfTrue) {
        wind->knight_pos.x = 0;
        wind->knight_pos.y = 740;
        wind->knight_speed.x += 2;
        sfSprite_setPosition(knight.sprite, wind->knight_pos);
        wind->klik = sfFalse;
    }
    if (sfFloatRect_intersects(&drak_box, &wind->Jerry_Hitbox, NULL) == sfTrue
    && wind->klik == sfTrue) {
        wind->drak_pos.x = 0;
        wind->drak_pos.y = 10;
        wind->drak_velocity.x += 3;
        wind->drak_velocity.y += 1.5;
        sfSprite_setPosition(drak.sprite, wind->drak_pos);
        wind->klik = sfFalse;
    }
}
