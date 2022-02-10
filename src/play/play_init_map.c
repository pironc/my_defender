/*
** EPITECH PROJECT, 2021
** play_init_map.c
** File description:
** functions to create a map
*/

#include "my.h"

void play_init_map(play_s *play)
{
    play->map_sprite = sfSprite_create();
    play->map_texture = sfTexture_createFromFile("assets/img/level1.png", NULL);
    sfSprite_setTexture(play->map_sprite, play->map_texture, sfTrue);
}