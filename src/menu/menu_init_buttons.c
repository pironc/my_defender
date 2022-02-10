/*
** EPITECH PROJECT, 2021
** menu_init_buttons.c
** File description:
** function to initialize menu buttons
*/

#include "my.h"

void menu_init_button_play(menu_s *menu)
{
    menu->play_spr = sfSprite_create();
    sfSprite_setTexture(menu->play_spr, menu->buttons_texture, sfTrue);
    sfSprite_setTextureRect(menu->play_spr, (sfIntRect){0, 0, 460, 110});
    sfSprite_setPosition(menu->play_spr, (sfVector2f){730, 260});
    menu->play_img = sfTexture_copyToImage(menu->buttons_texture);
}

void menu_init_button_howtoplay(menu_s *menu)
{
    menu->howtoplay_spr = sfSprite_create();
    sfSprite_setTexture(menu->howtoplay_spr, menu->buttons_texture, sfTrue);
    sfSprite_setTextureRect(menu->howtoplay_spr, \
    (sfIntRect){1380, 0, 460, 110});
    sfSprite_setPosition(menu->howtoplay_spr, (sfVector2f){730, 420});
    menu->howtoplay_img = sfTexture_copyToImage(menu->buttons_texture);
}

void menu_init_button_settings(menu_s *menu)
{
    menu->settings_spr = sfSprite_create();
    sfSprite_setTexture(menu->settings_spr, menu->buttons_texture, sfTrue);
    sfSprite_setTextureRect(menu->settings_spr, (sfIntRect){2760, 0, 460, 110});
    sfSprite_setPosition(menu->settings_spr, (sfVector2f){730, 580});
    menu->settings_img = sfTexture_copyToImage(menu->buttons_texture);
}

void menu_init_button_quit(menu_s *menu)
{
    menu->quit_spr = sfSprite_create();
    sfSprite_setTexture(menu->quit_spr, menu->buttons_texture, sfTrue);
    sfSprite_setTextureRect(menu->quit_spr, (sfIntRect){5520, 0, 460, 110});
    sfSprite_setPosition(menu->quit_spr, (sfVector2f){730, 720});
    menu->quit_img = sfTexture_copyToImage(menu->buttons_texture);
}

void menu_init_buttons(menu_s *menu)
{
    menu->buttons_texture = sfTexture_createFromFile(\
    "assets/sprite/buttons_main_menu.png", NULL);

    menu_init_button_play(menu);
    menu_init_button_howtoplay(menu);
    menu_init_button_settings(menu);
    menu_init_button_quit(menu);
}