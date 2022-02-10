/*
** EPITECH PROJECT, 2021
** howtoplay_draw.c
** File description:
** function to draw sprites in howtoplay scene
*/

#include "my.h"

void howtoplay_draw(game_s *game, howtoplay_s *howtoplay)
{
    sfRenderWindow_drawSprite(game->window, howtoplay->bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, howtoplay->back_arrow_sprite, NULL);
}