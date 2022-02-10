/*
** EPITECH PROJECT, 2021
** play_init_hud_extra.c
** File description:
** functions to initialize the rest of the HUD
*/

#include "my.h"

void play_init_score(play_s *play)
{
    play->score = 0;
    play->score_count_text = sfText_create();
    sfText_setFont(play->score_count_text, play->font);
    sfText_setString(play->score_count_text, "0");
    sfText_setColor(play->score_count_text, sfBlack);
    sfText_setCharacterSize(play->score_count_text, 33);
    sfText_setPosition(play->score_count_text, (sfVector2f){1370, 83});

    play->score_text = sfText_create();
    sfText_setFont(play->score_text, play->font);
    sfText_setString(play->score_text, "Score:");
    sfText_setColor(play->score_text, sfBlack);
    sfText_setCharacterSize(play->score_text, 33);
    sfText_setPosition(play->score_text, (sfVector2f){1250, 83});
}

void play_init_heart(play_s *play)
{
    play->heart_sprite = sfSprite_create();
    play->heart_texture = sfTexture_createFromFile(\
    "assets/img/heart.png", NULL);
    sfSprite_setTexture(play->heart_sprite, play->heart_texture, sfTrue);
    sfSprite_setScale(play->heart_sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setPosition(play->heart_sprite, (sfVector2f){1650, 86});
    play->heart_counter = 10;
    play->heart_text = sfText_create();
    sfText_setFont(play->heart_text, play->font);
    sfText_setString(play->heart_text, "10");
    sfText_setColor(play->heart_text, sfBlack);
    sfText_setCharacterSize(play->heart_text, 33);
    sfText_setPosition(play->heart_text, (sfVector2f){1700, 83});
}

void play_init_coins(play_s *play)
{
    play->coin_texture_rect = (sfIntRect){0, 0, 16, 16};
    play->coin_sprite = sfSprite_create();
    play->coin_texture = sfTexture_createFromFile(\
    "assets/sprite/coins.png", NULL);
    sfSprite_setTexture(play->coin_sprite, play->coin_texture, sfTrue);
    sfSprite_setTextureRect(play->coin_sprite, play->coin_texture_rect);
    sfSprite_setScale(play->coin_sprite, (sfVector2f){2.5, 2.3});
    sfSprite_setPosition(play->coin_sprite, (sfVector2f){1470, 86});
    play->coin_counter = 200;
    play->coin_text = sfText_create();
    sfText_setFont(play->coin_text, play->font);
    sfText_setString(play->coin_text, "200");
    sfText_setColor(play->coin_text, sfBlack);
    sfText_setCharacterSize(play->coin_text, 33);
    sfText_setPosition(play->coin_text, (sfVector2f){1520, 83});
    play->tower_cost = malloc(sizeof(int) * 4);
    for (int i = 0, cost = 100; i < 4; i++, cost += 100)
        play->tower_cost[i] = cost;
}