/*
** EPITECH PROJECT, 2020
** is_sprite_clicked.c
** File description:
** function to check if a sprite was clicked (whole sprite - no pixel perfect)
*/

#include "my.h"

sfBool is_sprite_clicked_raw(game_s *game, sfSprite *spr, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(spr);

    if (game->event.type == sfEvtMouseButtonPressed)
    if (game->event.type == sfEvtMouseButtonPressed && \
    sfFloatRect_contains(&rect, mpos.x, mpos.y)) {
        return (sfTrue);
    }
    return (sfFalse);
}