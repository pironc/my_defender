/*
** EPITECH PROJECT, 2021
** play.c
** File description:
** main play function
*/

#include "my.h"

void play_pause_event_check_music_off(game_s *game)
{
    if (game->music_status == false)
        sfMusic_setVolume(game->music, 0.2);
}

void play_pause_event_check(game_s *game, play_s *play)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed && \
        game->event.key.code == sfKeyEscape && play->pause == true) {
            play->pause = false;
            sfClock_restart(play->timer_clock);
            update_music_sound_status(game);
        } else if (game->event.type == sfEvtKeyPressed && \
        game->event.key.code == sfKeyEscape && play->pause == false) {
            play->pause = true;
            play_pause_event_check_music_off(game);
            play->paused_timer += play->timer_elapsed_ms;
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void play_pause_check(game_s *game, play_s *play)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    play_pause_event_check(game, play);
    if (play->pause)
        play_pause_buttons_check(play, mpos, game);
}

int play(game_s *game)
{
    play_s *play = NULL;
    play = play_init(play);

    while (sfRenderWindow_isOpen(game->window) && game->cur_scn == 1) {
        sfRenderWindow_clear(game->window, sfBlack);
        if (!play->pause)
            play_keycheck(game, play);
        play_pause_check(game, play);
        play_draw(game, play);
        sfRenderWindow_display(game->window);
    }
    play_dispose(play);
    return (0);
}