/*
** EPITECH PROJECT, 2021
** settings_dispose.c
** File description:
** function to destroy settings elements
*/

#include "my.h"

void settings_dispose(settings_s *settings)
{
    sfTexture_destroy(settings->bg_texture);
    sfSprite_destroy(settings->bg_sprite);
    free(settings);
}