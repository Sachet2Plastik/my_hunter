/*
** EPITECH PROJECT, 2022
** My_hunter
** File description:
** sprite creation
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef SPRITE_STRUCT_H
    #define SPRITE_STRUCT_H

    typedef struct setsprite{
        sfTexture *text;
        sfSprite *sprite;
    }setsprite_t;

#endif /*SPRITE_STRUCT_H*/
