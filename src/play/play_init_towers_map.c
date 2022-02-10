/*
** EPITECH PROJECT, 2021
** play_init_towers_map.c
** File description:
** functions to initialize towers on the map
*/

#include "my.h"

void play_set_tower_positions(play_s *play)
{
    sfSprite_setPosition(play->towers[0]->spr, (sfVector2f){490, 300});
    sfSprite_setPosition(play->towers[1]->spr, (sfVector2f){280, 450});
    sfSprite_setPosition(play->towers[2]->spr, (sfVector2f){490, 770});
    sfSprite_setPosition(play->towers[3]->spr, (sfVector2f){790, 590});
    sfSprite_setPosition(play->towers[4]->spr, (sfVector2f){1150, 390});
    sfSprite_setPosition(play->towers[5]->spr, (sfVector2f){1640, 280});

    sfSprite_setPosition(play->towers[0]->arrow_spr, (sfVector2f){610, 290});
    sfSprite_setPosition(play->towers[1]->arrow_spr, (sfVector2f){400, 440});
    sfSprite_setPosition(play->towers[2]->arrow_spr, (sfVector2f){610, 760});
    sfSprite_setPosition(play->towers[3]->arrow_spr, (sfVector2f){910, 580});
    sfSprite_setPosition(play->towers[4]->arrow_spr, (sfVector2f){1270, 380});
    sfSprite_setPosition(play->towers[5]->arrow_spr, (sfVector2f){1760, 270});
}

void play_init_towers_map_set_infos(play_s *play, int i)
{
    play->towers[i] = malloc(sizeof(*play->towers[i]));
    play->towers[i]->clock = sfClock_create();
    play->towers[i]->upgrade_clock = sfClock_create();
    play->towers[i]->spr = sfSprite_create();

    play->towers[i]->arrow_spr = sfSprite_create();
    sfSprite_setTexture(play->towers[i]->arrow_spr, \
    play->arrow_texture, sfTrue);
    sfSprite_setTextureRect(play->towers[i]->arrow_spr, \
    (sfIntRect){13, 0, 13, 24});

    play->towers[i]->circle = NULL;
    sfSprite_setTexture(play->towers[i]->spr, \
    play->tower_map_textures, sfTrue);
    sfSprite_setTextureRect(play->towers[i]->spr, \
    (sfIntRect){512, 0, 128, 145});
}

void play_init_towers_map(play_s *play)
{
    int i = 0;

    play->tower_map_textures = sfTexture_createFromFile(\
    "assets/img/towers_spritesheet_map.png", NULL);
    play->towers = malloc(sizeof(*play->towers) * 7);

    for (i = 0; i < 6; i++)
        play_init_towers_map_set_infos(play, i);
    play->towers[i] = NULL;
    play->towers_img = sfTexture_copyToImage(play->tower_map_textures);
    play_set_tower_positions(play);
}