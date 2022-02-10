/*
** EPITECH PROJECT, 2021
** play_pause_check.c
** File description:
** functions to handle checks in pause menu
*/

#include "my.h"

void play_pause_resume_check(play_s *play, sfVector2i mpos, game_s *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(play->pause_resume_spr);

    if (is_sprite_hovered(game, play->pause_resume_spr, \
    play->pause_resume_img, mpos)) {
        sfSprite_setTextureRect(play->pause_resume_spr, \
        (sfIntRect){347, 0, 347, 110});
    } else {
        sfSprite_setTextureRect(play->pause_resume_spr, \
        (sfIntRect){0, 0, 347, 110});
    }
    if (is_sprite_clicked(game, play->pause_resume_spr, \
    play->pause_resume_img, mpos)) {
        sfSprite_setTextureRect(play->pause_resume_spr, \
        (sfIntRect){694, 0, 347, 110});
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
    sfFloatRect_contains(&rect, mpos.x, mpos.y)) {
        play->pause = false;
        sfClock_restart(play->timer_clock);
        update_music_sound_status(game);
    }
}

void play_pause_menu_check(play_s *play, sfVector2i mpos, game_s *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(play->pause_menu_spr);

    if (is_sprite_hovered(game, play->pause_menu_spr, play->pause_menu_img, mpos)) {
        sfSprite_setTextureRect(play->pause_menu_spr, \
        (sfIntRect){1388, 0, 347, 110});
    } else {
        sfSprite_setTextureRect(play->pause_menu_spr, \
        (sfIntRect){1041, 0, 347, 110});
    }
    if (is_sprite_clicked(game, play->pause_menu_spr, play->pause_menu_img, mpos))
        sfSprite_setTextureRect(play->pause_menu_spr, \
        (sfIntRect){1735, 0, 347, 110});
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        game->cur_scn = 0;
}

void play_pause_exit_check(play_s *play, sfVector2i mpos, game_s *game)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(play->pause_exit_spr);

    if (is_sprite_hovered(game, play->pause_exit_spr, play->pause_exit_img, mpos)) {
        sfSprite_setTextureRect(play->pause_exit_spr, \
        (sfIntRect){2429, 0, 347, 110});
    } else {
        sfSprite_setTextureRect(play->pause_exit_spr, \
        (sfIntRect){2082, 0, 347, 110});
    }
    if (is_sprite_clicked(game, play->pause_exit_spr, play->pause_exit_img, mpos)) {
        sfSprite_setTextureRect(play->pause_exit_spr, \
        (sfIntRect){2776, 0, 347, 110});
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        sfRenderWindow_close(game->window);
}

void play_pause_buttons_check(play_s *play, sfVector2i mpos, game_s *game)
{
    play->pause_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(play->pause_bg, (sfColor){0, 0, 0, 150});
    sfRectangleShape_setSize(play->pause_bg, (sfVector2f){1920, 1080});

    play_pause_resume_check(play, mpos, game);
    play_pause_menu_check(play, mpos, game);
    play_pause_exit_check(play, mpos, game);
}