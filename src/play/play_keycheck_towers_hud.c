/*
** EPITECH PROJECT, 2021
** play_keycheck_towers_hud.c
** File description:
** functions to check for clicks on the towers in the hud
*/

#include "my.h"

void play_check_tower1_hud(game_s *game, play_s *play, sfVector2i mpos)
{
    if (play->selected == 1)
        return;
    if (is_sprite_hovered_raw(game, play->tower1_hud_sprite, mpos))
        set_rect(play->tower1_hud_sprite, (sfIntRect){188, 0, 188, 188});
    else if (is_sprite_clicked_raw(game, play->tower1_hud_sprite, mpos)) {
        set_rect(play->tower1_hud_sprite, (sfIntRect){376, 0, 188, 188});
        play->selected = 1;
    } else
        set_rect(play->tower1_hud_sprite, (sfIntRect){0, 0, 188, 188});
}

void play_check_tower2_hud(game_s *game, play_s *play, sfVector2i mpos)
{
    if (play->selected == 2)
        return;
    if (is_sprite_hovered_raw(game, play->tower2_hud_sprite, mpos))
        set_rect(play->tower2_hud_sprite, (sfIntRect){752, 0, 188, 188});
    else if (is_sprite_clicked_raw(game, play->tower2_hud_sprite, mpos)) {
        set_rect(play->tower2_hud_sprite, (sfIntRect){940, 0, 188, 188});
        play->selected = 2;
    } else
        set_rect(play->tower2_hud_sprite, (sfIntRect){564, 0, 188, 188});
}

void play_check_tower3_hud(game_s *game, play_s *play, sfVector2i mpos)
{
    if (play->selected == 3)
        return;
    if (is_sprite_hovered_raw(game, play->tower3_hud_sprite, mpos))
        set_rect(play->tower3_hud_sprite, (sfIntRect){1316, 0, 188, 188});
    else if (is_sprite_clicked_raw(game, play->tower3_hud_sprite, mpos)) {
        set_rect(play->tower3_hud_sprite, (sfIntRect){1504, 0, 188, 188});
        play->selected = 3;
    } else
        set_rect(play->tower3_hud_sprite, (sfIntRect){1128, 0, 188, 188});
}

void play_check_tower4_hud(game_s *game, play_s *play, sfVector2i mpos)
{
    if (play->selected == 4)
        return;
    if (is_sprite_hovered_raw(game, play->tower4_hud_sprite, mpos))
        set_rect(play->tower4_hud_sprite, (sfIntRect){1880, 0, 188, 188});
    else if (is_sprite_clicked_raw(game, play->tower4_hud_sprite, mpos)) {
        set_rect(play->tower4_hud_sprite, (sfIntRect){2068, 0, 188, 188});
        play->selected = 4;
    } else
        set_rect(play->tower4_hud_sprite, (sfIntRect){1692, 0, 188, 188});
}

void play_keycheck_towers_hud(game_s *game, play_s *play, sfVector2i mpos)
{
    play_check_tower1_hud(game, play, mpos);
    play_check_tower2_hud(game, play, mpos);
    play_check_tower3_hud(game, play, mpos);
    play_check_tower4_hud(game, play, mpos);
}