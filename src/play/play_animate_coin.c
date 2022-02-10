/*
** EPITECH PROJECT, 2021
** play_animate_coin.c
** File description:
** function to animate coin in HUD
*/

#include "my.h"

void animate_coin(play_s *play)
{
    play->coin_time = sfClock_getElapsedTime(play->coin_clock);
    play->coin_chrono = sfTime_asSeconds(play->coin_time);

    if (play->coin_chrono > 0.1) {
        play->coin_texture_rect.left += 16;
        sfClock_restart(play->coin_clock);
    }
    if (play->coin_texture_rect.left > 120)
        play->coin_texture_rect.left = 0;
    sfSprite_setTextureRect(play->coin_sprite, play->coin_texture_rect);
}