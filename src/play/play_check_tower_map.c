/*
** EPITECH PROJECT, 2021
** play_check_tower_map.c
** File description:
** functions to check towers on map
*/

#include "my.h"

void tower_upgrade_set_infos(play_s *play, int i)
{
    play->towers[i]->radius += 20;
    play->coin_counter -= 100;
    sfText_setString(play->coin_text, my_int_to_str(play->coin_counter));
    play->towers[i]->tier++;
    sfCircleShape_setRadius(play->towers[i]->circle, play->towers[i]->radius);
    sfCircleShape_setOrigin(play->towers[i]->circle, \
    (sfVector2f){play->towers[i]->radius, play->towers[i]->radius});
    sfClock_restart(play->towers[i]->upgrade_clock);
}

void tower_upgrade_check(game_s *game, play_s *play, sfVector2i mpos, int i)
{
    play->towers[i]->upgrade_ms = \
    sfTime_asMilliseconds(sfClock_getElapsedTime(\
    play->towers[i]->upgrade_clock));

    if (is_sprite_clicked_raw(game, play->towers[i]->spr, mpos) && \
    play->towers[i]->circle != NULL && play->towers[i]->tier < 3) {
        if (play->towers[i]->upgrade_ms > 200 && play->coin_counter >= 100)
            tower_upgrade_set_infos(play, i);
        if (play->towers[i]->tier == 3)
            sfSprite_setTextureRect(\
            play->towers[i]->arrow_spr, (sfIntRect){0, 0, 13, 24});
    }
}

void play_keycheck_tower_map_misc(play_s *play, int i)
{
    sfIntRect cur_rect = {0, 0, 0, 0};
    sfIntRect rect = {512, 0, 128, 145};

    cur_rect = sfSprite_getTextureRect(play->towers[i]->spr);
    if (cur_rect.left < 512 || play->selected == 0)
        return;
    play->coin_counter -= play->tower_cost[play->selected - 1];
    sfText_setString(play->coin_text, my_int_to_str(play->coin_counter));

    rect.left = (play->selected - 1) * 128;
    sfSprite_setTextureRect(play->towers[i]->spr, rect);

    if (play->hovered > 0)
        play_set_tower_infos(play);
}

void play_keycheck_tower_map(game_s *game, play_s *play, sfVector2i mpos)
{
    for (int i = 0; play->towers[i] != NULL; i++) {
        tower_upgrade_check(game, play, mpos, i);
        if (is_sprite_hovered_raw(game, play->towers[i]->spr, mpos)) {
            play->hovered = i + 1;
        }
        if (!is_tower_hovered(game, play, mpos))
            play->hovered = 0;
        if (play->hovered > 0 && is_sprite_clicked(game, play->towers[i]->spr, \
        play->towers_img, mpos) && play->coin_counter >= \
        play->tower_cost[play->selected - 1]) {
            play_keycheck_tower_map_misc(play, i);
        }
    }
}

void is_enemy_in_circle(play_s *play, int i, game_s *game)
{
    enemy_s *tmp = play->enemy;

    if (play == NULL)
        return;
    if (play->towers[i] == NULL)
        return;

    while (tmp) {
        if (play->towers[i]->circle == NULL)
            return;
        if (distance_between_sprite_circle(\
        tmp->sprite, play->towers[i]->circle) <= play->towers[i]->radius) {
            attack_enemy(play->towers[i], tmp, play, game);
        }
        tmp = tmp->next;
    }
}