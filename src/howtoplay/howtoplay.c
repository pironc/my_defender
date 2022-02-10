/*
** EPITECH PROJECT, 2021
** howtoplay.c
** File description:
** main howtoplay function
*/

#include "my.h"

int howtoplay(game_s *game)
{
    howtoplay_s *howtoplay = NULL;
    howtoplay = howtoplay_init(howtoplay);

    while (sfRenderWindow_isOpen(game->window) && game->cur_scn == 2) {
        sfRenderWindow_clear(game->window, sfBlack);
        howtoplay_keycheck(game, howtoplay);
        howtoplay_draw(game, howtoplay);
        sfRenderWindow_display(game->window);
    }
    howtoplay_dispose(howtoplay);
    return (0);
}