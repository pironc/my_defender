/*
** EPITECH PROJECT, 2021
** play_set_tower_infos.c
** File description:
** functions to set towers in play
*/

#include "my.h"

void set_4(towers_s *tower)
{
    tower->circle = sfCircleShape_create();
    sfVector2f circle_pos = sfSprite_getPosition(tower->spr);
    circle_pos.x += 64;
    circle_pos.y += 72.5;

    tower->radius = 190;
    tower->type = 3;
    tower->tier = 0;

    sfCircleShape_setOrigin(tower->circle, \
    (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(tower->circle, sfGreen);
    sfCircleShape_setOutlineThickness(tower->circle, 3);
    sfCircleShape_setPosition(tower->circle, circle_pos);
}

void set_3(towers_s *tower)
{
    tower->circle = sfCircleShape_create();
    sfVector2f circle_pos = sfSprite_getPosition(tower->spr);
    circle_pos.x += 64;
    circle_pos.y += 72.5;

    tower->radius = 170;
    tower->type = 2;
    tower->tier = 0;

    sfCircleShape_setOrigin(tower->circle, \
    (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(tower->circle, sfGreen);
    sfCircleShape_setOutlineThickness(tower->circle, 3);
    sfCircleShape_setPosition(tower->circle, circle_pos);
}

void set_2(towers_s *tower)
{
    tower->circle = sfCircleShape_create();
    sfVector2f circle_pos = sfSprite_getPosition(tower->spr);
    circle_pos.x += 64;
    circle_pos.y += 72.5;

    tower->radius = 145;
    tower->type = 1;
    tower->tier = 0;

    sfCircleShape_setOrigin(tower->circle, \
    (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(tower->circle, sfGreen);
    sfCircleShape_setOutlineThickness(tower->circle, 3);
    sfCircleShape_setPosition(tower->circle, circle_pos);
}

void set_1(towers_s *tower)
{
    tower->circle = sfCircleShape_create();
    sfVector2f circle_pos = sfSprite_getPosition(tower->spr);
    circle_pos.x += 64;
    circle_pos.y += 72.5;

    tower->radius = 140;
    tower->type = 0;
    tower->tier = 0;

    sfCircleShape_setOrigin(tower->circle, \
    (sfVector2f){tower->radius, tower->radius});
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setFillColor(tower->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(tower->circle, sfGreen);
    sfCircleShape_setOutlineThickness(tower->circle, 3);
    sfCircleShape_setPosition(tower->circle, circle_pos);
    sfClock_restart(tower->upgrade_clock);
}

void play_set_tower_infos(play_s *play)
{
    void (*set_tower_info[])(towers_s*) = {set_1, set_2, set_3, set_4};
    set_tower_info[play->selected - 1](play->towers[play->hovered - 1]);
}