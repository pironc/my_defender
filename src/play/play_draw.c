/*
** EPITECH PROJECT, 2021
** play_draw.c
** File description:
** function to draw sprites in play scene
*/

#include "my.h"

void play_draw_coins_text(game_s *game, play_s *play)
{
    sfRenderWindow_drawText(game->window, play->coin_text, NULL);
}

void play_draw_enemy(game_s *game, play_s *play)
{
    enemy_s *tmp = play->enemy_end;

    while (tmp) {
        if (tmp->alive) {
            sfRenderWindow_drawRectangleShape(\
            game->window, tmp->red_rect, NULL);
            sfRenderWindow_drawRectangleShape(\
            game->window, tmp->green_rect, NULL);
            sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        }
        tmp = tmp->prev;
    }
}

void play_draw_pause(game_s *game, play_s *play)
{
    if (play->pause) {
        sfRenderWindow_drawRectangleShape(game->window, play->pause_bg, NULL);
        sfRenderWindow_drawSprite(game->window, play->pause_header_spr, NULL);
        sfRenderWindow_drawSprite(game->window, play->pause_resume_spr, NULL);
        sfRenderWindow_drawSprite(game->window, play->pause_menu_spr, NULL);
        sfRenderWindow_drawSprite(game->window, play->pause_exit_spr, NULL);
    }
}

void play_draw_hud(game_s *game, play_s *play)
{
    sfRenderWindow_drawSprite(game->window, play->hud_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->skip_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->tower1_hud_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->tower2_hud_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->tower3_hud_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->tower4_hud_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->next_wave_spr, NULL);
    sfRenderWindow_drawText(game->window, play->timer_text, NULL);
    sfSprite_setTextureRect(play->coin_sprite, play->coin_texture_rect);
    sfRenderWindow_drawSprite(game->window, play->heart_sprite, NULL);
    sfRenderWindow_drawText(game->window, play->heart_text, NULL);
    sfRenderWindow_drawSprite(game->window, play->coin_sprite, NULL);
    play_draw_coins_text(game, play);
    sfRenderWindow_drawText(game->window, play->score_text, NULL);
    sfRenderWindow_drawText(game->window, play->score_count_text, NULL);
}

void play_draw(game_s *game, play_s *play)
{
    sfRenderWindow_drawSprite(game->window, play->map_sprite, NULL);

    if (play->timer == -1)
        play_draw_enemy(game, play);

    for (int i = 0; play->towers[i] != NULL; i++)
        sfRenderWindow_drawSprite(game->window, play->towers[i]->spr, NULL);
    if (play->hovered > 0 && play->towers[play->hovered - 1]->circle) {
        sfRenderWindow_drawCircleShape(\
        game->window, play->towers[play->hovered - 1]->circle, NULL);
        sfRenderWindow_drawSprite(\
        game->window, play->towers[play->hovered - 1]->arrow_spr, NULL);
    }
    play_draw_hud(game, play);
    play_draw_pause(game, play);

    if (play->fade_status == 1)
        sfRenderWindow_drawSprite(game->window, play->fade_sprite, NULL);
}