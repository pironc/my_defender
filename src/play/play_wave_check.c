/*
** EPITECH PROJECT, 2021
** play_wave_check.c
** File description:
** functions to check for waves
*/

#include "my.h"

void play_end_wave(play_s *play)
{
    enemy_s *tmp = play->enemy;

    while (tmp) {
        sfSprite_destroy(tmp->sprite);
        tmp = tmp->next;
    }
    free(play->enemy);
    play->max_enemy += 2;
    play->timer = 21;
    sfClock_restart(play->timer_clock);
    play_start_new_wave(play);
    play->paused_timer = 0;
}

void play_is_wave_ended(play_s *play)
{
    enemy_s *tmp = play->enemy;
    int alive = false;

    while (tmp) {
        if (tmp->alive)
            alive = true;
        tmp = tmp->next;
    }
    if (!alive)
        play_end_wave(play);
}