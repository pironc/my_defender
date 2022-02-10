/*
** EPITECH PROJECT, 2021
** play_init_hud.c
** File description:
** function to initialize the game's hud
*/

#include "my.h"

void play_init_timer(play_s *play)
{
    play->selected = 0;
    play->timer = 6;
    play->timer_clock = sfClock_create();
    play->timer_elapsed_ms = sfTime_asSeconds(\
    sfClock_getElapsedTime(play->timer_clock));
    play->timer_text = sfText_create();
    play->font = sfFont_createFromFile("assets/font/comic.ttf");
    sfText_setString(play->timer_text, "30");
    sfText_setFont(play->timer_text, play->font);
    sfText_setColor(play->timer_text, sfBlack);
    sfText_setCharacterSize(play->timer_text, 45);
    sfText_setPosition(play->timer_text, (sfVector2f){935, 70});

    play->next_wave_spr = sfSprite_create();
    play->next_wave_texture = sfTexture_createFromFile(\
    "assets/img/next_wave.png", NULL);
    sfSprite_setTexture(play->next_wave_spr, play->next_wave_texture, sfTrue);
    sfSprite_setPosition(play->next_wave_spr, (sfVector2f){838, 20});
}

void play_init_skip_button(play_s *play)
{
    play->skip_sprite = sfSprite_create();
    play->skip_texture = sfTexture_createFromFile(\
    "assets/img/skip_spritesheet.png", NULL);
    sfSprite_setTexture(play->skip_sprite, play->skip_texture, sfTrue);
    sfSprite_setPosition(play->skip_sprite, (sfVector2f){890, 130});
    sfSprite_setTextureRect(play->skip_sprite, (sfIntRect){0, 0, 132, 64});
}

void play_init_hud_banner(play_s *play)
{
    play->hud_sprite = sfSprite_create();
    play->hud_texture = sfTexture_createFromFile(\
    "assets/img/top_hud.png", NULL);
    sfSprite_setTexture(play->hud_sprite, play->hud_texture, sfTrue);
}

void play_init_hud(play_s *play)
{
    play_init_skip_button(play);
    play_init_hud_banner(play);
    play_init_towers_hud(play);
    play_init_timer(play);
    play_init_coins(play);
    play_init_heart(play);
    play_init_score(play);
}