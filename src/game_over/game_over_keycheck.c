/*
** EPITECH PROJECT, 2021
** game_over_keycheck.c
** File description:
** functions to check for key presses
*/

#include "my.h"

void game_over_back_check(game_s *game, game_over_s *game_over, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game_over->back_sprite);

    if (is_sprite_clicked_raw(game, game_over->back_sprite, mpos)) {
        sfSprite_setTextureRect(game_over->back_sprite, \
        (sfIntRect){1240, 0, 620, 149});
    } else if (is_sprite_hovered_raw(game, game_over->back_sprite, mpos)) {
        sfSprite_setTextureRect(game_over->back_sprite, \
        (sfIntRect){620, 0, 620, 149});
    } else {
        sfSprite_setTextureRect(game_over->back_sprite, \
        (sfIntRect){0, 0, 620, 149});
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        game->cur_scn = 0;
}

void game_over_keycheck(game_s *game, game_over_s *game_over)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        game_over_back_check(game, game_over, mpos);
    }
}