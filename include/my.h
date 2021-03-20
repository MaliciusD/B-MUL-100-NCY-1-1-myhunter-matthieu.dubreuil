/*
** EPITECH PROJECT, 2020
** headers
** File description:
** headers
*/

#ifndef my_h
#define my_h
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/Window.h>

typedef struct struct_s
{
    sfRenderWindow *window;
    sfEvent event;
    int posx_mouse;
    int posy_mouse;
    sfTime time;
    float seconds;
    sfClock *clock;
    sfSprite *sprite_background;
    sfSprite *sprite_backgroundig;
    sfSprite *sprite_enemy;
    sfSprite *sprite_enemy2;
    sfSprite *sprite_enemy3;
    sfSprite *sprite_healthbar;
    sfSprite *sprite_healthbar2;
    sfSprite *sprite_healthbar3;
    sfSprite *sprite_end;
    sfTexture *texture_background;
    sfTexture *texture_backgroundig;
    sfTexture *texture_enemy;
    sfTexture *texture_enemy2;
    sfTexture *texture_enemy3;
    sfTexture *texture_healthbar;
    sfTexture *texture_healthbar2;
    sfTexture *texture_healthbar3;
    sfTexture *texture_end;
    sfIntRect enemy_animation;
    sfIntRect enemy_animation2;
    sfIntRect enemy_animation3;
    sfVector2f pos_enemy;
    sfVector2f pos_enemy2;
    sfVector2f pos_enemy3;
    sfVector2f pos_healthbar;
    sfVector2f pos_healthbar2;
    sfVector2f pos_healthbar3;
    sfMusic *music_background;
    sfMusic *music_menu;
    sfMusic *music_ondeath;
    sfMusic *music_start;
    sfMusic *music_nani;
    sfMusic *music_end;
    sfMusic *music_hit;
    sfMusic *music_hit2;
    sfMusic *music_hit3;
    int menu;
    int mario;
    int sound;
    int count;
    int speed;
    int vie;
}struct_t;

void my_put_bin(unsigned int nb);
void my_put_hexa(unsigned int nb);
void my_put_hexauppercase(unsigned int nb);
void my_put_octal(unsigned int nb);
void my_percentS(char *str);
void my_put_pointer(unsigned int nb);
void func_char(va_list ap);
void func_string(va_list ap);
void func_nbr(va_list ap);
void func_percent(va_list ap);
void func_unsignedint(va_list ap);
void func_binary(va_list ap);
void func_hexa(va_list ap);
void func_hexaupper(va_list ap);
void func_octal(va_list ap);
void func_percentS(va_list ap);
void func_pointer(va_list ap);
void func_lsa(va_list ap);
void my_put_unsint(unsigned int nb);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif