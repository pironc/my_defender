/*
** EPITECH PROJECT, 2021
** play_keycheck.c
** File description:
** functions to check for key presses
*/

#include "my.h"

void play_keycheck_skip(game_s *game, play_s *play, sfVector2i mpos)
{
    set_rect(play->skip_sprite, (sfIntRect){264, 0, 132, 64});
    if (play->timer <= 0)
        return;
    if (is_sprite_hovered_raw(game, play->skip_sprite, mpos))
        set_rect(play->skip_sprite, (sfIntRect){132, 0, 132, 64});
    else
        set_rect(play->skip_sprite, (sfIntRect){0, 0, 132, 64});
    if (is_sprite_clicked_raw(game, play->skip_sprite, mpos)) {
        set_rect(play->skip_sprite, (sfIntRect){264, 0, 132, 64});
        play->timer = 0;
        sfText_setString(play->timer_text, "0");
    }
}

void play_timer_check(play_s *play, game_s *game)
{
    if ((play->timer - play->timer_elapsed_ms - play->paused_timer) > 0.99) {
        sfText_setString(play->timer_text, \
        my_int_to_str(play->timer - \
        play->timer_elapsed_ms - play->paused_timer));
    } else if (play->timer != -1)
        play->timer = 0;
    if (play->timer == 0) {
        play->timer = -1;
        play_start_new_wave(play);
    } else if (play->timer == -1) {
        play_move_enemy(play);
        for (int i = 0; play->towers[i] != NULL; i++)
            is_enemy_in_circle(play, i, game);
        play_is_wave_ended(play);
    }
}

void play_keycheck(game_s *game, play_s *play)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    play->timer_elapsed_ms = sfTime_asSeconds\
    (sfClock_getElapsedTime(play->timer_clock));
    play_keycheck_towers_hud(game, play, mpos);
    play_keycheck_tower_map(game, play, mpos);
    play_keycheck_skip(game, play, mpos);
    play_collision_check(game, play);
    play_timer_check(play, game);
    play_fade_start(game, play);

    animate_coin(play);
}