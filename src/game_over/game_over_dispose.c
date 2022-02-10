/*
** EPITECH PROJECT, 2021
** game_over_dispose.c
** File description:
** function to destroy game_over elements
*/

#include "my.h"

void game_over_dispose(game_over_s *game_over)
{
    sfSprite_destroy(game_over->back_sprite);
    sfTexture_destroy(game_over->back_texture);
    sfText_destroy(game_over->score_text);
    sfSprite_destroy(game_over->score_title_spr);
    sfTexture_destroy(game_over->score_title_texture);
    free(game_over);
}