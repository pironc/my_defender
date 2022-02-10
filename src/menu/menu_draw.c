/*
** EPITECH PROJECT, 2021
** menu_draw.c
** File description:
** function to draw sprites in menu
*/

#include "my.h"

void menu_draw(game_s *game, menu_s *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->logo_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->logo_star_spr, NULL);
    sfRenderWindow_drawSprite(game->window, menu->play_spr, NULL);
    sfRenderWindow_drawSprite(game->window, menu->howtoplay_spr, NULL);
    sfRenderWindow_drawSprite(game->window, menu->settings_spr, NULL);
    sfRenderWindow_drawSprite(game->window, menu->quit_spr, NULL);
    sfRenderWindow_drawText(game->window, menu->high_score_txt, NULL);
    sfRenderWindow_drawText(game->window, menu->highest_score_title_txt, NULL);
}