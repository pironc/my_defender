/*
** EPITECH PROJECT, 2021
** settings_keycheck.c
** File description:
** functions to check for key presses
*/

#include "my.h"

void update_music_sounds_buttons(game_s *game, settings_s *settings)
{
    if (game->sound_status == sfTrue)
        settings->sound_button_texture_rect.left = 331;
    if (game->sound_status == sfFalse)
        settings->sound_button_texture_rect.left = 0;

    if (game->music_status == sfTrue)
        settings->music_button_texture_rect.left = 331;
    if (game->music_status == sfFalse)
        settings->music_button_texture_rect.left = 0;
}

void sound_button_keycheck(game_s *game, settings_s *settings, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->sound_button_sprite);

    if (game->event.type == sfEvtMouseButtonReleased && \
    sfFloatRect_contains(&rect, mpos.x, mpos.y)) {
        change_sound_status(game);
        sfSound_play(game->click_sound);
    }
}

void music_button_keycheck(game_s *game, settings_s *settings, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(settings->music_button_sprite);

    if (game->event.type == sfEvtMouseButtonReleased && \
    sfFloatRect_contains(&rect, mpos.x, mpos.y)) {
        change_music_status(game);
        sfSound_play(game->click_sound);
    }
}

void settings_keycheck(game_s *game, settings_s *settings)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (is_sprite_clicked_raw(game, settings->back_arrow_sprite, mpos)) {
            game->cur_scn = 0;
            sfSound_play(game->click_sound);
        }
        music_button_keycheck(game, settings, mpos);
        sound_button_keycheck(game, settings, mpos);
    }
}