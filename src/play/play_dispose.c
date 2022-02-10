/*
** EPITECH PROJECT, 2021
** play_dispose.c
** File description:
** function to destroy play elements
*/

#include "my.h"

void play_dispose(play_s *play)
{
    sfClock_destroy(play->coin_clock);
    sfClock_destroy(play->enemy_clock);
    sfTexture_destroy(play->enemy_texture);
    sfClock_destroy(play->fade_clock);
    sfTexture_destroy(play->fade_texture);
    sfSprite_destroy(play->fade_sprite);
    sfImage_destroy(play->fade_image);
    sfSprite_destroy(play->pause_exit_spr);
    sfSprite_destroy(play->pause_menu_spr);
    sfSprite_destroy(play->pause_resume_spr);
    sfSprite_destroy(play->pause_header_spr);
    sfTexture_destroy(play->pause_header_texture);
    free(play->collision_bounds);
    for (int i = 0; i < 6; i++)
        sfRectangleShape_destroy(play->collision_rects[i]);
    free(play->collision_rects);
    free(play);
}