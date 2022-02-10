/*
** EPITECH PROJECT, 2021
** howtoplay_init.c
** File description:
** function to initialize the main howtoplay
*/

#include "my.h"

void howtoplay_init_back_arrow(howtoplay_s *howtoplay)
{
    howtoplay->back_arrow_sprite = sfSprite_create();
    howtoplay->back_arrow_texture = sfTexture_createFromFile(\
    "assets/sprite/arrow.png", NULL);
    sfSprite_setTexture(howtoplay->back_arrow_sprite, \
    howtoplay->back_arrow_texture, sfFalse);
    sfSprite_setPosition(howtoplay->back_arrow_sprite, (sfVector2f){420, 130});
}

void howtoplay_init_background(howtoplay_s *howtoplay)
{
    howtoplay->bg_sprite = sfSprite_create();
    howtoplay->bg_texture = sfTexture_createFromFile(\
    "assets/img/howtoplay.jpg", NULL);
    sfSprite_setTexture(howtoplay->bg_sprite, howtoplay->bg_texture, sfFalse);
}

howtoplay_s *howtoplay_init(howtoplay_s *howtoplay)
{
    howtoplay = malloc(sizeof(*howtoplay));
    if (howtoplay == NULL)
        return (NULL);

    howtoplay_init_background(howtoplay);
    howtoplay_init_back_arrow(howtoplay);

    return (howtoplay);
}