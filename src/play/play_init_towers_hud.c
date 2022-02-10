/*
** EPITECH PROJECT, 2021
** play_init_towers.c
** File description:
** function to initialize towers
*/

#include "my.h"

void play_init_tower1_hud(play_s *play)
{
    play->tower1_hud_sprite = sfSprite_create();
    sfSprite_setTexture(play->tower1_hud_sprite, \
    play->tower_hud_textures, sfTrue);
    sfSprite_setTextureRect(play->tower1_hud_sprite, \
    (sfIntRect){0, 0, 188, 188});
    sfSprite_setPosition(play->tower1_hud_sprite, (sfVector2f){0, 15});
}

void play_init_tower2_hud(play_s *play)
{
    play->tower2_hud_sprite = sfSprite_create();
    sfSprite_setTexture(play->tower2_hud_sprite, \
    play->tower_hud_textures, sfTrue);
    sfSprite_setTextureRect(play->tower2_hud_sprite, \
    (sfIntRect){564, 0, 188, 188});
    sfSprite_setPosition(play->tower2_hud_sprite, (sfVector2f){188, 15});
}

void play_init_tower3_hud(play_s *play)
{
    play->tower3_hud_sprite = sfSprite_create();
    sfSprite_setTexture(play->tower3_hud_sprite, \
    play->tower_hud_textures, sfTrue);
    sfSprite_setTextureRect(play->tower3_hud_sprite, \
    (sfIntRect){1128, 0, 188, 188});
    sfSprite_setPosition(play->tower3_hud_sprite, (sfVector2f){376, 15});
}

void play_init_tower4_hud(play_s *play)
{
    play->tower4_hud_sprite = sfSprite_create();
    sfSprite_setTexture(play->tower4_hud_sprite, \
    play->tower_hud_textures, sfTrue);
    sfSprite_setTextureRect(play->tower4_hud_sprite, \
    (sfIntRect){1692, 0, 188, 188});
    sfSprite_setPosition(play->tower4_hud_sprite, (sfVector2f){564, 15});
}

void play_init_towers_hud(play_s *play)
{
    play->tower_hud_textures = sfTexture_createFromFile(\
    "assets/img/towers_spritesheet.png", NULL);

    play_init_tower1_hud(play);
    play_init_tower2_hud(play);
    play_init_tower3_hud(play);
    play_init_tower4_hud(play);
}