/*
** EPITECH PROJECT, 2021
** play_collision_check.c
** File description:
** functions to move enemies through the map
*/

#include "my.h"

void update_highest_score(game_s *game)
{
    int fd = 0;

    if (game->highest_score < game->current_score) {
        game->highest_score = game->current_score;
        fd = open("score", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
        write(fd, my_int_to_str(game->highest_score), \
        my_strlen(my_int_to_str(game->highest_score)));
        close(fd);
    }
}

void play_heart_check(game_s *game, play_s *play, enemy_s *tmp)
{
    if (tmp->pos.x > 1930 && tmp->alive == true) {
        tmp->alive = false;
        play->heart_counter--;
        if (play->heart_counter == 0 && play->fade_status == 0) {
            play->fade_status = 1;
            game->current_score = play->score;
            update_highest_score(game);
        }
        if (play->heart_counter < 0)
            return;
        sfText_setString(play->heart_text, \
        my_int_to_str(play->heart_counter));
    }
}

void play_collision_check(game_s *game, play_s *play)
{
    enemy_s *tmp = play->enemy;

    if (play->timer != -1)
        return;

    while (tmp) {
        if (sfFloatRect_contains(&play->collision_bounds[0], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 2;
        if (sfFloatRect_contains(&play->collision_bounds[1], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 4;
        if (sfFloatRect_contains(&play->collision_bounds[2], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 1;
        if (sfFloatRect_contains(&play->collision_bounds[3], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 4;
        if (sfFloatRect_contains(&play->collision_bounds[4], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 1;
        if (sfFloatRect_contains(&play->collision_bounds[5], \
            tmp->pos.x, tmp->pos.y))tmp->direction = 4;
        play_heart_check(game, play, tmp);
        tmp = tmp->next;
    }
}