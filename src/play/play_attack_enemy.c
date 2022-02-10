/*
** EPITECH PROJECT, 2021
** play_attack_enemy.c
** File description:
** functions to attack ennemies
*/

#include "my.h"

void attack_tower_1(towers_s *tower, enemy_s *enemy, play_s *play, game_s *game)
{
    tower->elapsed = sfTime_asSeconds(sfClock_getElapsedTime(tower->clock));

    if (tower->elapsed > 0.6 && enemy->alive) {
        enemy->health -= 20;
        sfSound_play(game->hitmarker_sound);
        if (enemy->health <= 0) {
            enemy->alive = false;
            play->coin_counter += 2;
            sfSound_play(game->hitmarker_sound);
            play->score += 10;
            sfText_setString(play->score_count_text, \
            my_int_to_str(play->score));
            return;
        }
        sfRectangleShape_setSize(enemy->green_rect, \
        (sfVector2f){40 * (float)enemy->health / 100, 6});
        sfClock_restart(tower->clock);
    }
}

void attack_tower_2(enemy_s *enemy)
{
    if (enemy->direction == 1) {
        sfSprite_move(enemy->sprite, (sfVector2f){0, 0.2});
        sfRectangleShape_move(enemy->green_rect, (sfVector2f){0, 0.2});
        sfRectangleShape_move(enemy->red_rect, (sfVector2f){0, 0.2});
    }
    if (enemy->direction == 2) {
        sfSprite_move(enemy->sprite, (sfVector2f){0, -0.2});
        sfRectangleShape_move(enemy->green_rect, (sfVector2f){0, -0.2});
        sfRectangleShape_move(enemy->red_rect, (sfVector2f){0, -0.2});
    }
    if (enemy->direction == 3) {
        sfSprite_move(enemy->sprite, (sfVector2f){0.2, 0});
        sfRectangleShape_move(enemy->green_rect, (sfVector2f){0.2, 0});
        sfRectangleShape_move(enemy->red_rect, (sfVector2f){0.2, 0});
    }
    if (enemy->direction == 4) {
        sfSprite_move(enemy->sprite, (sfVector2f){-0.2, 0});
        sfRectangleShape_move(enemy->green_rect, (sfVector2f){-0.2, 0});
        sfRectangleShape_move(enemy->red_rect, (sfVector2f){-0.2, 0});
    }
}

void attack_tower_3(towers_s *tower, enemy_s *enemy, play_s *play, game_s *game)
{
    tower->elapsed = sfTime_asSeconds(sfClock_getElapsedTime(tower->clock));

    if (tower->elapsed > 1 && enemy->alive) {
        enemy->health -= 35;
        sfSound_play(game->hitmarker_sound);
        if (enemy->health <= 0) {
            enemy->alive = false;
            play->coin_counter += 2;
            sfSound_play(game->hitmarker_sound);
            play->score += 10;
            sfText_setString(play->score_count_text, \
            my_int_to_str(play->score));
            return;
        }
        sfRectangleShape_setSize(enemy->green_rect, \
        (sfVector2f){40 * (float)enemy->health / 100, 6});
        sfClock_restart(tower->clock);
    }
    attack_tower_2(enemy);
}

void attack_tower_4(towers_s *tower, enemy_s *enemy, play_s *play, game_s *game)
{
    tower->elapsed = sfTime_asSeconds(sfClock_getElapsedTime(tower->clock));

    if (tower->elapsed > 2 && enemy->alive) {
        enemy->alive = false;
        play->coin_counter += 2;
        play->score += 10;
        sfSound_play(game->hitmarker_sound);
        sfText_setString(play->score_count_text, \
        my_int_to_str(play->score));
        sfClock_restart(tower->clock);
    }
}

void attack_enemy(towers_s *tower, enemy_s *enemy, play_s *play, game_s *game)
{
    if (tower->type == 0)
        attack_tower_1(tower, enemy, play, game);
    if (tower->type == 1)
        attack_tower_2(enemy);
    if (tower->type == 2)
        attack_tower_3(tower, enemy, play, game);
    if (tower->type == 3)
        attack_tower_4(tower, enemy, play, game);
}