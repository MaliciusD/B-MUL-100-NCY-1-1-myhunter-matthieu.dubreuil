/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** main
*/

#include "include/my.h"

void display_end(struct_t *hunter)
{
    sfRenderWindow_display(hunter->window);
    sfRenderWindow_drawSprite(hunter->window, hunter->sprite_end, NULL);
}

void call_remove_sprite(struct_t *hunter)
{
    if (hunter->pos_enemy.x <= hunter->posx_mouse &&
        hunter->pos_enemy.y <= hunter->posy_mouse) {
        if (hunter->pos_enemy.x + 350 > hunter->posx_mouse &&
            hunter->pos_enemy.y + 260 > hunter->posy_mouse &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            hunter->pos_enemy.x = -990;
            hunter->pos_enemy.y = rand() %800;
            hunter->mario += 100;
            hunter->speed += 3.5;
            hunter->count += 100;
            sfMusic_play(hunter->music_ondeath);
        }
    }
}

void call_remove_sprite2(struct_t *hunter)
{
    if (hunter->pos_enemy2.x <= hunter->posx_mouse &&
        hunter->pos_enemy2.y <= hunter->posy_mouse) {
        if (hunter->pos_enemy2.x + 350 > hunter->posx_mouse &&
            hunter->pos_enemy2.y + 260 > hunter->posy_mouse &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            hunter->pos_enemy2.x = -790;
            hunter->pos_enemy2.y = rand() %800;
            hunter->mario += 100;
            hunter->count += 100;
            hunter->speed += 3.5;
            sfMusic_play(hunter->music_ondeath);
        }
        return (0);
    }
}

int remove_sprite(struct_t *hunter)
{
    call_remove_sprite(hunter);
    call_remove_sprite2(hunter);
    if (hunter->pos_enemy3.x <= hunter->posx_mouse &&
        hunter->pos_enemy3.y <= hunter->posy_mouse) {
        if (hunter->pos_enemy3.x + 350 > hunter->posx_mouse &&
            hunter->pos_enemy3.y + 260 > hunter->posy_mouse &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            hunter->pos_enemy3.x = -990;
            hunter->sound = 0;
            sfMusic_stop(hunter->music_nani);
            hunter->count = 0;
            sfMusic_play(hunter->music_ondeath);
        }
    }
    return (0);
}

void loop_content1(struct_t *hunter)
{
    hunter->pos_enemy.x += 50 + hunter->speed;
    hunter->pos_enemy2.x += 50 + hunter->speed;
    if (hunter->count >= 500 && hunter->sound == 0) {
        sfMusic_play(hunter->music_nani);
        hunter->sound = 1;
    }
    if (hunter->count >= 500)
        hunter->pos_enemy3.x += 150;
    hunter->enemy_animation.left += 350;
    hunter->enemy_animation2.left += 350;
    hunter->enemy_animation3.left += 350;
    if (hunter->pos_enemy.x > 1920) {
        hunter->pos_enemy.x = -185;
        hunter->vie -= 1;
        hunter->pos_enemy.y = rand() %800;
        hunter->speed += 0.5;
    }
}