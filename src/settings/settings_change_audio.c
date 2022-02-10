/*
** EPITECH PROJECT, 2021
** settings_change_audio.c
** File description:
** functions to change the music or sound volume
*/

#include "my.h"

void change_sound_status(game_s *game)
{
    if (game->sound_status == sfTrue) {
        game->sound_status = sfFalse;
    } else {
        game->sound_status = sfTrue;
    }
}

void change_music_status(game_s *game)
{
    if (game->music_status == sfTrue) {
        game->music_status = sfFalse;
    } else {
        game->music_status = sfTrue;
    }
}