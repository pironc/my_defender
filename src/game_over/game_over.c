/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** main game_over function
*/

#include "my.h"

int game_over(game_s *game)
{
    game_over_s *game_over = NULL;
    game_over = game_over_init(game, game_over);

    while (sfRenderWindow_isOpen(game->window) && game->cur_scn == 4) {
        sfRenderWindow_clear(game->window, sfBlack);
        game_over_keycheck(game, game_over);
        game_over_draw(game, game_over);
        sfRenderWindow_display(game->window);
    }
    game_over_dispose(game_over);
    return (0);
}