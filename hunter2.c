/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** main
*/

#include "include/my.h"

void destroy(struct_t *hunter)
{
    sfRenderWindow_destroy(hunter->window);
    sfMusic_destroy(hunter->music_menu);
    sfMusic_destroy(hunter->music_background);
    sfMusic_destroy(hunter->music_ondeath);
    sfMusic_destroy(hunter->music_start);
    sfMusic_destroy(hunter->music_nani);
    sfMusic_destroy(hunter->music_end);
    sfMusic_destroy(hunter->music_hit);
    sfMusic_destroy(hunter->music_hit2);
    sfMusic_destroy(hunter->music_hit3);
}

void create_sprite(struct_t *hunter)
{
    hunter->sprite_background = sfSprite_create();
    hunter->sprite_backgroundig = sfSprite_create();
    hunter->sprite_enemy = sfSprite_create();
    hunter->sprite_enemy2 = sfSprite_create();
    hunter->sprite_enemy3 = sfSprite_create();
    hunter->sprite_healthbar = sfSprite_create();
    hunter->sprite_healthbar2 = sfSprite_create();
    hunter->sprite_healthbar3 = sfSprite_create();
    hunter->sprite_end = sfSprite_create();
}

void position(struct_t *hunter)
{
    hunter->pos_enemy2.x = -1000;
    hunter->pos_enemy2.y = 600;
    hunter->pos_enemy3.x = -800;
    hunter->pos_enemy3.y = 440;
    hunter->pos_healthbar.x = 1750;
    hunter->pos_healthbar2.x = 1620;
    hunter->pos_healthbar3.x = 1490;
}

void create_fromfile0(struct_t *hunter)
{
    hunter->clock = sfClock_create();
    hunter->texture_background =
    sfTexture_createFromFile("ressources/background.jpg", NULL);
    hunter->texture_backgroundig =
    sfTexture_createFromFile("ressources/backgroundig.jpg", NULL);
    hunter->texture_enemy =
    sfTexture_createFromFile("ressources/test2.png", NULL);
    hunter->texture_enemy2 =
    sfTexture_createFromFile("ressources/test2.png", NULL);
    hunter->texture_enemy3 =
    sfTexture_createFromFile("ressources/test2.png", NULL);
    hunter->music_background =
    sfMusic_createFromFile("ressources/music_background.ogg");
    hunter->music_menu =
    sfMusic_createFromFile("ressources/menu_music.ogg");
    hunter->music_ondeath =
    sfMusic_createFromFile("ressources/bruh-sound-effect.ogg");
    hunter->music_start =
    sfMusic_createFromFile("ressources/music_start.ogg");
}

void create_fromfile(struct_t *hunter)
{
    create_fromfile0(hunter);
    hunter->music_nani =
    sfMusic_createFromFile("ressources/nani-sound-effect.ogg");
    hunter->texture_healthbar =
    sfTexture_createFromFile("ressources/healthbar.png", NULL);
    hunter->texture_healthbar2 =
    sfTexture_createFromFile("ressources/healthbar.png", NULL);
    hunter->texture_healthbar3 =
    sfTexture_createFromFile("ressources/healthbar.png", NULL);
    hunter->texture_end =
    sfTexture_createFromFile("ressources/end_image.jpg", NULL);
    hunter->music_end =
    sfMusic_createFromFile("ressources/music_end.ogg");
    hunter->music_hit =
    sfMusic_createFromFile("ressources/lose_life_sound.ogg");
    hunter->music_hit2 =
    sfMusic_createFromFile("ressources/lose_life_sound.ogg");
    hunter->music_hit3 =
    sfMusic_createFromFile("ressources/lose_life_sound.ogg");
}