/*
** EPITECH PROJECT, 2021
** howtoplay_keycheck.c
** File description:
** functions to check for key presses
*/

#include "my.h"

void howtoplay_back_arrow_check(game_s *game, sfSprite *spr, sfVector2i mpos)
{
    if (is_sprite_clicked_raw(game, spr, mpos)) {
        sfSound_play(game->click_sound);
        game->cur_scn = 0;
    }
}

void howtoplay_keycheck(game_s *game, howtoplay_s *howtoplay)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        howtoplay_back_arrow_check(game, howtoplay->back_arrow_sprite, mpos);
    }
}