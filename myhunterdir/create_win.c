/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** set_window
*/

#include "../include/my.h"

void setwind(set_wind_t *wind)
{
    wind->V_mode.width = 1920;
    wind->V_mode.height = 1080;
    wind->V_mode.bitsPerPixel = 32;
    wind->view = sfView_create();
    wind->window = sfRenderWindow_create(wind->V_mode, "My_Castle_Defender",\
    sfDefaultStyle, NULL);
}
