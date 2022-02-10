/*
** EPITECH PROJECT, 2021
** menu_dispose.c
** File description:
** function to destroy menu elements
*/

#include "my.h"

void menu_dispose(menu_s *menu)
{
    sfImage_destroy(menu->quit_img);
    sfSprite_destroy(menu->quit_spr);
    sfImage_destroy(menu->settings_img);
    sfSprite_destroy(menu->settings_spr);
    sfImage_destroy(menu->howtoplay_img);
    sfSprite_destroy(menu->howtoplay_spr);
    sfImage_destroy(menu->play_img);
    sfSprite_destroy(menu->play_spr);
    sfTexture_destroy(menu->buttons_texture);
    sfTexture_destroy(menu->logo_texture);
    sfSprite_destroy(menu->logo_sprite);
    sfTexture_destroy(menu->bg_texture);
    sfSprite_destroy(menu->bg_sprite);
    free(menu);
}