/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** main
*/

#include "include/my.h"

void set_texture(struct_t *hunter)
{
    sfSprite_setTexture(hunter->sprite_background,
    hunter->texture_background, sfTrue);
    sfSprite_setTexture(hunter->sprite_backgroundig,
    hunter->texture_backgroundig, sfTrue);
    sfSprite_setTexture(hunter->sprite_enemy, hunter->texture_enemy, sfTrue);
    sfSprite_setTexture(hunter->sprite_enemy2, hunter->texture_enemy2, sfTrue);
    sfSprite_setTexture(hunter->sprite_enemy3, hunter->texture_enemy3, sfTrue);
    sfSprite_setTexture(hunter->sprite_healthbar,
    hunter->texture_healthbar, sfTrue);
    sfSprite_setTexture(hunter->sprite_healthbar2,
    hunter->texture_healthbar2, sfTrue);
    sfSprite_setTexture(hunter->sprite_healthbar3,
    hunter->texture_healthbar3, sfTrue);
    sfSprite_setTexture(hunter->sprite_end, hunter->texture_end, sfTrue);
    hunter->enemy_animation = (sfIntRect) {0, 0, 350, 260};
    hunter->enemy_animation2 = (sfIntRect) {0, 0, 350, 260};
    hunter->enemy_animation3 = (sfIntRect) {0, 0, 350, 260};
    sfSprite_setTextureRect(hunter->sprite_enemy, hunter->enemy_animation);
    sfSprite_setTextureRect(hunter->sprite_enemy2, hunter->enemy_animation2);
    sfSprite_setTextureRect(hunter->sprite_enemy3, hunter->enemy_animation3);
}

void event(struct_t *hunter)
{
    while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
        if (hunter->event.type == sfEvtClosed)
            sfRenderWindow_close(hunter->window);
        hunter->posx_mouse = hunter->event.mouseButton.x;
        hunter->posy_mouse = hunter->event.mouseButton.y;
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(hunter->window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (hunter->posx_mouse >= 789 && hunter->posx_mouse <= 1206 &&
            hunter->posy_mouse >= 369 && hunter->posy_mouse <= 469)
                hunter->menu = 1;
            if (hunter->menu == 0)
                if (hunter->posx_mouse >= 691 && hunter->posx_mouse <= 1323 &&
                hunter->posy_mouse >= 580 && hunter->posy_mouse <= 946)
                    sfRenderWindow_close(hunter->window);
        }
    }
}

void display_menu(struct_t *hunter)
{
    sfRenderWindow_display(hunter->window);
    sfRenderWindow_drawSprite(hunter->window, hunter->sprite_background, NULL);
}

void call_display_game(struct_t *hunter)
{
    sfRenderWindow_display(hunter->window);
    sfRenderWindow_drawSprite(hunter->window,
    hunter->sprite_backgroundig, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->sprite_enemy, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->sprite_enemy2, NULL);
    sfRenderWindow_drawSprite(hunter->window, hunter->sprite_enemy3, NULL);
    sfSprite_setPosition(hunter->sprite_enemy, hunter->pos_enemy);
    sfSprite_setPosition(hunter->sprite_enemy2, hunter->pos_enemy2);
    sfSprite_setPosition(hunter->sprite_enemy3, hunter->pos_enemy3);
    sfSprite_setPosition(hunter->sprite_healthbar, hunter->pos_healthbar);
    sfSprite_setPosition(hunter->sprite_healthbar2, hunter->pos_healthbar2);
    sfSprite_setPosition(hunter->sprite_healthbar3, hunter->pos_healthbar3);
    if (hunter->vie == 3) {
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar, NULL);
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar2, NULL);
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar3, NULL);
    }
}

void display_game(struct_t *hunter)
{
    call_display_game(hunter);
    if (hunter->vie == 2) {
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar, NULL);
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar2, NULL);
    }
    if (hunter->vie == 1) {
        sfRenderWindow_drawSprite(hunter->window,
        hunter->sprite_healthbar, NULL);
    }
    if (hunter->vie <= 0) {
        sfMusic_stop(hunter->music_background);
        hunter->menu = 2;
    }
}