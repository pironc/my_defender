/*
** EPITECH PROJECT, 2021
** settings_draw.c
** File description:
** function to draw sprites in settings scene
*/

#include "my.h"

void settings_draw(game_s *game, settings_s *settings)
{
    sfRenderWindow_drawSprite(game->window, settings->bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, settings->title_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, settings->back_arrow_sprite, NULL);
    update_music_sounds_buttons(game, settings);
    sfSprite_setTextureRect(settings->music_button_sprite, \
    settings->music_button_texture_rect);
    sfRenderWindow_drawSprite(game->window, \
    settings->music_button_sprite, NULL);
    sfSprite_setTextureRect(settings->sound_button_sprite, \
    settings->sound_button_texture_rect);
    sfRenderWindow_drawSprite(game->window, \
    settings->sound_button_sprite, NULL);
}