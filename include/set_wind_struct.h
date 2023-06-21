/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** set_wind_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef SET_WIND_STRUCT_H
    #define SET_WIND_STRUCT_H

        typedef struct drak_velocity{
            int x;
            int y;
        }drak_velocity_t;

        typedef struct set_wind{
            sfRenderWindow *window;
            sfVideoMode V_mode;
            sfEvent event;
            sfView *view;
            sfClock *clock;
            double frames;
            sfFloatRect Jerry_Hitbox;
            sfVector2f Jerry_Coords;
            sfVector2f knight_pos;
            sfVector2f knight_speed;
            sfVector2f drak_pos;
            sfVector2f drak_speed;
            drak_velocity_t drak_velocity;
            sfBool klik;
            sfMusic *music;
        }set_wind_t;


#endif /*SET_WIND_STRUCT_H*/
