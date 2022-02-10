/*
** EPITECH PROJECT, 2021
** game_over_draw.c
** File description:
** function to draw sprites in game_over scene
*/

#include "my.h"

void game_over_draw(game_s *game, game_over_s *game_over)
{
    sfRenderWindow_drawSprite(game->window, game_over->score_title_spr, NULL);
    sfRenderWindow_drawText(game->window, game_over->score_text, NULL);
    sfRenderWindow_drawSprite(game->window, game_over->back_sprite, NULL);
}