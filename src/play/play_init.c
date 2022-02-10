/*
** EPITECH PROJECT, 2021
** play_init.c
** File description:
** function to initialize the main play
*/

#include "my.h"

void set_rect(sfSprite *spr, sfIntRect rect)
{
    sfSprite_setTextureRect(spr, rect);
}

void play_init_fade(play_s *play)
{
    play->fade_image = sfImage_createFromColor(1920, 1080, sfBlack);
    play->fade_sprite = sfSprite_create();
    play->fade_texture = sfTexture_createFromImage\
    (play->fade_image, NULL);
    play->fade_black = (sfColor){255, 255, 255, 0};
    sfSprite_setColor(play->fade_sprite, play->fade_black);
    sfSprite_setTexture(play->fade_sprite, play->fade_texture, sfTrue);

    play->fade_status = 0;
    play->fade_clock = sfClock_create();
}

void play_init_misc(play_s *play)
{
    play->enemy_texture = sfTexture_createFromFile(\
    "assets/sprite/enemy.png", NULL);
    play->pause = false;
    play->max_enemy = 2;
    play->enemy_clock = sfClock_create();
    play->coin_clock = sfClock_create();
    play->paused_timer = 0;
    play->fade_status = 0;
}

play_s *play_init(play_s *play)
{
    play = malloc(sizeof(*play));
    if (play == NULL)
        return (NULL);

    play->arrow_texture = sfTexture_createFromFile(\
    "assets/sprite/arrow_spritesheet.png", NULL);

    play_init_map(play);
    play_init_hud(play);
    play_init_towers_map(play);
    play_init_collision(play);
    play_init_pause(play);
    play_init_fade(play);
    play_init_misc(play);

    return (play);
}