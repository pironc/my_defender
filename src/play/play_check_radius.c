/*
** EPITECH PROJECT, 2021
** play_check_radius.c
** File description:
** function to check the distance between a sfSprite and a sfCircleShape
*/

#include "my.h"

float distance_between_sprite_circle(sfSprite *sprite, sfCircleShape *circle)
{
    sfVector2f pos1 = sfCircleShape_getPosition(circle);
    sfVector2f pos2 = sfSprite_getPosition(sprite);

    return (sqrt((pos2.x - pos1.x) * (pos2.x - pos1.x) + \
    (pos2.y - pos1.y) * (pos2.y - pos1.y)));
}