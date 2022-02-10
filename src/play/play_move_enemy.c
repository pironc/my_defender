/*
** EPITECH PROJECT, 2021
** play_move_enemy.c
** File description:
** functions to move enemy
*/

#include "my.h"

void move_enemy_up_down(enemy_s *tmp, float speed)
{
    if (tmp->alive && tmp->direction == 1) {
        sfSprite_move(tmp->sprite, (sfVector2f){0, -speed});
        sfRectangleShape_move(tmp->green_rect, (sfVector2f){0, -speed});
        sfRectangleShape_move(tmp->red_rect, (sfVector2f){0, -speed});
        tmp->pos = sfSprite_getPosition(tmp->sprite);
    }
    if (tmp->alive && tmp->direction == 2) {
        sfSprite_move(tmp->sprite, (sfVector2f){0, speed});
        sfRectangleShape_move(tmp->green_rect, (sfVector2f){0, speed});
        sfRectangleShape_move(tmp->red_rect, (sfVector2f){0, speed});
        tmp->pos = sfSprite_getPosition(tmp->sprite);
    }
}

void move_enemy_left_right(enemy_s *tmp, float speed)
{
    if (tmp->alive && tmp->direction == 3) {
        sfSprite_move(tmp->sprite, (sfVector2f){-speed, 0});
        sfRectangleShape_move(tmp->green_rect, (sfVector2f){-speed, 0});
        sfRectangleShape_move(tmp->red_rect, (sfVector2f){-speed, 0});
        tmp->pos = sfSprite_getPosition(tmp->sprite);
    }
    if (tmp->alive && tmp->direction == 4) {
        sfSprite_move(tmp->sprite, (sfVector2f){speed, 0});
        sfRectangleShape_move(tmp->green_rect, (sfVector2f){speed, 0});
        sfRectangleShape_move(tmp->red_rect, (sfVector2f){speed, 0});
        tmp->pos = sfSprite_getPosition(tmp->sprite);
    }
}

void play_move_enemy(play_s *play)
{
    enemy_s *tmp = play->enemy;
    float speed = 1.8;
    float time_ms = sfTime_asMilliseconds(\
    sfClock_getElapsedTime(play->enemy_clock));

    while (tmp && time_ms > 10) {
        move_enemy_up_down(tmp, speed);
        move_enemy_left_right(tmp, speed);
        tmp = tmp->next;
        sfClock_restart(play->enemy_clock);
    }
}