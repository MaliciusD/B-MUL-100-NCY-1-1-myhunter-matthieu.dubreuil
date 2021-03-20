/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** main
*/

#include "include/my.h"

void loop_content2(struct_t *hunter)
{
    if (hunter->pos_enemy2.x > 1920) {
        hunter->pos_enemy2.x = -185;
        hunter->pos_enemy2.y = rand() %800;
        hunter->speed += 0.5;
        hunter->vie -= 1;
    }
    if (hunter->pos_enemy3.x > 1920) {
        hunter->pos_enemy3.x = -385;
        hunter->sound = 0;
        hunter->count = 0;
        hunter->vie -= 1;
    }
    if (hunter->enemy_animation.left >= 1050)
        hunter->enemy_animation.left = 0;
    if (hunter->enemy_animation2.left >= 1050)
        hunter->enemy_animation2.left = 0;
    if (hunter->enemy_animation3.left >= 1050)
        hunter->enemy_animation3.left = 0;
}

void call_clock(struct_t *hunter)
{
    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->seconds = hunter->time.microseconds / 800000.0;
    if (hunter->seconds > 0.1) {
        if (hunter->menu == 1) {
            loop_content1(hunter);
            loop_content2(hunter);
        }
        sfSprite_setTextureRect(hunter->sprite_enemy,
        hunter->enemy_animation);
        sfSprite_setTextureRect(hunter->sprite_enemy2,
        hunter->enemy_animation2);
        sfSprite_setTextureRect(hunter->sprite_enemy3,
        hunter->enemy_animation3);
        sfClock_restart(hunter->clock);
    }
}

void display_game_and_menu(struct_t *hunter)
{
    if (hunter->menu == 0)
        display_menu(hunter);
    if (hunter->menu == 1) {
        display_game(hunter);
        if (hunter->vie == 3)
            sfMusic_play(hunter->music_hit);
        if (hunter->vie == 2)
            sfMusic_play(hunter->music_hit2);
        if (hunter->vie == 1)
            sfMusic_play(hunter->music_hit3);
            remove_sprite(hunter);
    }
}

void game_loop(struct_t *hunter)
{
    int zik = 0;
    int hit = 0;
    int change_zik = 0;
    float speed;
    if (hunter->menu == 0)
        sfMusic_play(hunter->music_menu);
    while (sfRenderWindow_isOpen(hunter->window)) { event(hunter);
        call_clock(hunter);
        display_game_and_menu(hunter);
        if (change_zik == 0 && hunter->menu == 1) {
            sfMusic_stop(hunter->music_menu);
            change_zik = 1;
        } if (change_zik == 1) { sfMusic_play(hunter->music_start);
            sfMusic_play(hunter->music_background);
            change_zik = 2;
        } if (hunter->menu == 2) {
            display_end(hunter);
            if (zik == 0) {
                sfMusic_play(hunter->music_end);
                zik = 1; } } }
}

int main(void)
{
    struct_t *hunter = malloc(sizeof(struct_t));
    hunter->vie = 3;
    sfVideoMode video_mode = {1920, 1080, 32};
    hunter->window = sfRenderWindow_create
        (video_mode, "my_hunter", sfFullscreen | sfClose | sfResize, NULL);
    create_sprite(hunter);
    create_fromfile(hunter);
    set_texture(hunter);
    position(hunter);
    game_loop(hunter);
    destroy(hunter);
    my_printf("Votre score = %d\n", hunter->mario);
}