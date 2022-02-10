/*
** EPITECH PROJECT, 2021
** is_tower_hovered.c
** File description:
** function to check if a tower is hovered
*/

#include "my.h"

bool is_tower_hovered(game_s *game, play_s *play, sfVector2i mpos)
{
    for (int i = 0; play->towers[i] != NULL; i++) {
        if (is_sprite_hovered_raw(game, play->towers[i]->spr, mpos))
            return (true);
        if (is_sprite_clicked_raw(game, play->towers[i]->spr, mpos))
            return (true);
    }
    return (false);
}