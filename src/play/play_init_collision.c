/*
** EPITECH PROJECT, 2021
** play_init_collision.c
** File description:
** function to check the enemy's collisions on the map
*/

#include "my.h"

void rectshape_setpos(sfRectangleShape *rect, sfVector2f vect)
{
    sfRectangleShape_setPosition(rect, vect);
}

void play_init_collision_bounds(play_s *play)
{
    play->collision_bounds = malloc(sizeof(sfIntRect) * 6);

    for (int i = 0; i < 6; i++) {
        play->collision_bounds[i] = \
        sfRectangleShape_getGlobalBounds(play->collision_rects[i]);
    }
}

void play_init_collision(play_s *play)
{
    play->collision_rects = malloc(sizeof(sfRectangleShape*) * 7);

    for (int i = 0; i < 6; i++)
        play->collision_rects[i] = sfRectangleShape_create();
    play->collision_rects[6] = NULL;

    rectshape_setpos(play->collision_rects[0], (sfVector2f){450, 300});
    rectshape_setpos(play->collision_rects[1], (sfVector2f){440, 960});
    rectshape_setpos(play->collision_rects[2], (sfVector2f){960, 950});
    rectshape_setpos(play->collision_rects[3], (sfVector2f){960, 565});
    rectshape_setpos(play->collision_rects[4], (sfVector2f){1600, 565});
    rectshape_setpos(play->collision_rects[5], (sfVector2f){1600, 310});

    sfRectangleShape_setSize(play->collision_rects[0], (sfVector2f){10, 100});
    sfRectangleShape_setSize(play->collision_rects[1], (sfVector2f){100, 10});
    sfRectangleShape_setSize(play->collision_rects[2], (sfVector2f){10, 100});
    sfRectangleShape_setSize(play->collision_rects[3], (sfVector2f){100, 10});
    sfRectangleShape_setSize(play->collision_rects[4], (sfVector2f){10, 100});
    sfRectangleShape_setSize(play->collision_rects[5], (sfVector2f){100, 10});

    play_init_collision_bounds(play);
}