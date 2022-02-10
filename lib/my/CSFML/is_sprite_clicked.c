/*
** EPITECH PROJECT, 2020
** is_sprite_clicked.c
** File description:
** function to check if a sprite was clicked
*/

#include "my.h"

sfBool is_sprite_clicked(game_s *game, sfSprite *spr, sfImage *img, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(spr);
    sfIntRect img_rect = sfSprite_getTextureRect(spr);
    sfVector2f spr_pos = sfSprite_getPosition(spr);
    sfColor color = (sfColor){0, 0, 0, 0};

    if (game->event.type == sfEvtMouseButtonPressed && \
    sfFloatRect_contains(&rect, mpos.x, mpos.y)) {
        color = sfImage_getPixel(img, (mpos.x - spr_pos.x) + img_rect.left, \
        (mpos.y - spr_pos.y) + img_rect.top);
        if (color.a != 0)
            return (sfTrue);
    }
    return (sfFalse);
}