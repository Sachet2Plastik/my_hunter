/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include "sprite_struct.h"
#include "set_wind_struct.h"

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strdup(char const *src);
    char **my_str_to_word_array(char const *str);
    int my_show_word_array(char * const *tab);
    int my_intlen(int n);
    int mini_printf(const char *format, ...);
    void set_sprite(setsprite_t *setsprite, char *filepath);
    void setwind(set_wind_t *wind);
    int knight_anime(set_wind_t *wind, setsprite_t *knight,\
    setsprite_t *game_bg, int i);
    int drake_anime(set_wind_t *wind, setsprite_t *drak,\
    setsprite_t *game_bg, int j);
    void game_over(setsprite_t knight, set_wind_t *wind,\
    setsprite_t drak, setsprite_t game_bg);
    void hit(setsprite_t knight, set_wind_t *wind, setsprite_t drak);
    void start_clicked(set_wind_t *wind, setsprite_t *menu);
    void if_click(set_wind_t *wind, setsprite_t *menu);
    void set_knight(set_wind_t *wind, setsprite_t knight);
    void set_drak(set_wind_t *wind, setsprite_t drak);
    int game_loop(set_wind_t *wind, setsprite_t game_bg,\
    setsprite_t knight, setsprite_t drak);
    void sprite_move(set_wind_t *wind, setsprite_t drak, setsprite_t knight);

#endif /* MY_H_ */
