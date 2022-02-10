/*
** EPITECH PROJECT, 2021
** howtoplay_dispose.c
** File description:
** function to destroy howtoplay elements
*/

#include "my.h"

void howtoplay_dispose(howtoplay_s *howtoplay)
{
    sfTexture_destroy(howtoplay->back_arrow_texture);
    sfSprite_destroy(howtoplay->back_arrow_sprite);
    sfTexture_destroy(howtoplay->bg_texture);
    sfSprite_destroy(howtoplay->bg_sprite);
    free(howtoplay);
}