/*
** EPITECH PROJECT, 2021
** menu_init.c
** File description:
** function to initialize the main menu
*/

#include "my.h"

void menu_init_highest_score_text(menu_s *menu)
{
    menu->highest_score_title_txt = sfText_create();

    menu->font = sfFont_createFromFile("assets/font/comic.ttf");
    menu->highest_score_title_txt = sfText_create();
    sfText_setFont(menu->highest_score_title_txt, menu->font);
    sfText_setString(menu->highest_score_title_txt, "Highest score");
    sfText_setColor(menu->highest_score_title_txt, sfBlack);
    sfText_setCharacterSize(menu->highest_score_title_txt, 40);
    sfText_setPosition(menu->highest_score_title_txt, (sfVector2f){830, 880});
}

void menu_init_highest_score(game_s *game, menu_s *menu)
{
    int offset = 1920/2 - (my_strlen(my_int_to_str(game->highest_score)) * 13);
    sfVector2f pos = {offset, 950};

    menu->font = sfFont_createFromFile("assets/font/comic.ttf");
    menu->high_score_txt = sfText_create();
    sfText_setFont(menu->high_score_txt, menu->font);
    sfText_setString(menu->high_score_txt, my_int_to_str(game->highest_score));
    sfText_setColor(menu->high_score_txt, sfBlack);
    sfText_setCharacterSize(menu->high_score_txt, 40);
    sfText_setPosition(menu->high_score_txt, pos);
}

void menu_init_background(menu_s *menu)
{
    menu->bg_sprite = sfSprite_create();
    menu->bg_texture = sfTexture_createFromFile("assets/img/menu_bg.png", NULL);
    sfSprite_setTexture(menu->bg_sprite, menu->bg_texture, sfFalse);
    sfSprite_setScale(menu->bg_sprite, (sfVector2f){1.563, 1.41});
}

void menu_init_logo(menu_s *menu)
{
    menu->logo_sprite = sfSprite_create();
    menu->logo_texture = sfTexture_createFromFile(\
    "assets/sprite/logo.png", NULL);
    sfSprite_setTexture(menu->logo_sprite, menu->logo_texture, sfFalse);
    sfSprite_setPosition(menu->logo_sprite, (sfVector2f){706, 120});

    menu->logo_star_spr = sfSprite_create();
    menu->logo_star_texture = sfTexture_createFromFile(\
    "assets/sprite/pd2.png", NULL);
    sfSprite_setTexture(menu->logo_star_spr, menu->logo_star_texture, sfFalse);
    sfSprite_setPosition(menu->logo_star_spr, (sfVector2f){1200, 90});
}

menu_s *menu_init(game_s *game, menu_s *menu)
{
    menu = malloc(sizeof(*menu));
    if (menu == NULL)
        return (NULL);

    menu_init_background(menu);
    menu_init_logo(menu);
    menu_init_buttons(menu);
    menu_init_highest_score(game, menu);
    menu_init_highest_score_text(menu);

    return (menu);
}