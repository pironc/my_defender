/*
** EPITECH PROJECT, 2021
** play_check_fade.c
** File description:
** functions to check for fade
*/

#include "my.h"

void draw_fade_out(game_s *game, play_s *play)
{
    play->fade_timer = sfClock_getElapsedTime(play->fade_clock);
    if ((int)sfTime_asMicroseconds(play->fade_timer) >= 2500) {
        sfClock_restart(play->fade_clock);
        play->fade_black.a += 1;
        sfSprite_setColor(play->fade_sprite, play->fade_black);
    }
    sfRenderWindow_drawSprite(game->window, play->fade_sprite, NULL);
}

void play_fade_start(game_s *game, play_s *play)
{
    if (play->fade_status == 1)
        draw_fade_out(game, play);

    if (play->fade_status == 1 && play->fade_black.a >= 255) {
        game->cur_scn = 4;
    }
}