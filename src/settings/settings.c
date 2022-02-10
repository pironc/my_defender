/*
** EPITECH PROJECT, 2021
** settings.c
** File description:
** main settings function
*/

#include "my.h"

void update_music_sound_status(game_s *game)
{
    if (game->music_status == sfFalse)
        sfMusic_setVolume(game->music, 1);
    if (game->music_status == sfTrue)
        sfMusic_setVolume(game->music, 0);

    if (game->sound_status == sfFalse) {
        sfSound_setVolume(game->click_sound, 1);
        sfSound_setVolume(game->hitmarker_sound, 1);
    }
    if (game->sound_status == sfTrue) {
        sfSound_setVolume(game->click_sound, 0);
        sfSound_setVolume(game->hitmarker_sound, 0);
    }
}

int settings(game_s *game)
{
    settings_s *settings = NULL;
    settings = settings_init(settings);

    while (sfRenderWindow_isOpen(game->window) && game->cur_scn == 3) {
        sfRenderWindow_clear(game->window, sfBlack);
        update_music_sound_status(game);
        settings_keycheck(game, settings);
        settings_draw(game, settings);
        sfRenderWindow_display(game->window);
    }
    settings_dispose(settings);
    return (0);
}