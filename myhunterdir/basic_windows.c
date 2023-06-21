/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main_game_loop
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <math.h>
#include "../include/my.h"

int event_handeling(set_wind_t *wind)
{
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (wind->event.type == sfEvtMouseButtonPressed) {
        wind->klik = sfTrue;
        wind->Jerry_Coords = sfRenderWindow_mapPixelToCoords(wind->window,\
        sfMouse_getPosition(wind->window),NULL);
        wind->Jerry_Hitbox.top = wind->Jerry_Coords.y;
        wind->Jerry_Hitbox.left = wind->Jerry_Coords.x;
    }
}

int game_loop(set_wind_t *wind, setsprite_t game_bg,\
setsprite_t knight, setsprite_t drak)
{
    wind->clock = sfClock_create();
    int i = 0, j = 0;
    set_knight(wind, knight);
    set_drak(wind, drak);
    sfClock_restart(wind->clock);
    while (sfRenderWindow_isOpen(wind->window)) {
        while (sfRenderWindow_pollEvent(wind->window, &wind->event))
            event_handeling(wind);
        game_over(knight, wind, drak, game_bg);
        if (sfClock_getElapsedTime(wind->clock).microseconds >= 40000) {
            i = knight_anime(wind, &knight, &game_bg, i);
            j = drake_anime(wind, &drak, &game_bg, j);
            hit(knight, wind, drak);
            sfClock_restart(wind->clock);
            sprite_move(wind, drak, knight);
            wind->frames += 0.20;
        }
        sfRenderWindow_display(wind->window);
        wind->klik = sfFalse;
    }
}

int game_menu_loop(void)
{
    setsprite_t menu;
    set_wind_t wind;

    set_sprite(&menu, "asset/menu_background.png");
    wind.Jerry_Hitbox.width = wind.Jerry_Hitbox.height = 1;
    setwind(&wind);
    wind.frames = 0;
    wind.drak_velocity.x = 6;
    wind.drak_velocity.y = 3;
    sfRenderWindow_setFramerateLimit(wind.window, 24);
    while (sfRenderWindow_isOpen(wind.window)) {
        sfRenderWindow_drawSprite(wind.window, menu.sprite, NULL);
        while (sfRenderWindow_pollEvent(wind.window, &wind.event))
            event_handeling(&wind);
        if_click(&wind, &menu);
        sfRenderWindow_display(wind.window);
    }
    return (0);
}

int main(int ac, char** av)
{
    if (ac > 1)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            mini_printf("            <!> Castle_Defender <!>\n\n");
            mini_printf("The Game Is Very Simple:\n");
            mini_printf("     Aim Enemies With The Mouse,\n");
            mini_printf("     And Use The Left Click To Kill The Attackers\n");
            return (0);
        }else {
            return (1);
        }
    return (game_menu_loop());
}
