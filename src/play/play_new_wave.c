/*
** EPITECH PROJECT, 2021
** play_new_wave.c
** File description:
** functions to create a new wave
*/

#include "my.h"

void new_enemy_set_infos(play_s *play, enemy_s *new_enemy, \
sfVector2f pos, int i)
{
    sfVector2f green_rect_pos = {-40, 296};
    sfVector2f red_rect_pos = {-40, 296};
    pos.x -= 50 * i;
    green_rect_pos.x -= 50 * i;
    red_rect_pos.x -= 50 * i;

    sfSprite_setTexture(new_enemy->sprite, play->enemy_texture, sfTrue);
    sfSprite_setTextureRect(new_enemy->sprite, (sfIntRect){5, 5, 30, 30});
    sfSprite_setOrigin(new_enemy->sprite, (sfVector2f){15, 15});
    sfSprite_setScale(new_enemy->sprite, (sfVector2f){-1, 1});
    sfSprite_setPosition(new_enemy->sprite, pos);
    sfRectangleShape_setSize(new_enemy->green_rect, (sfVector2f){40, 6});
    sfRectangleShape_setFillColor(new_enemy->green_rect, sfGreen);
    sfRectangleShape_setPosition(new_enemy->green_rect, green_rect_pos);
    sfRectangleShape_setSize(new_enemy->red_rect, (sfVector2f){40, 6});
    sfRectangleShape_setFillColor(new_enemy->red_rect, sfRed);
    sfRectangleShape_setPosition(new_enemy->red_rect, red_rect_pos);
}

void new_enemy(play_s *play, sfVector2f pos, int i)
{
    enemy_s *new_enemy = malloc(sizeof(*new_enemy));
    enemy_s *end = play->enemy;

    while (end->next)
        end = end->next;

    new_enemy->alive = true;
    new_enemy->direction = 4;
    new_enemy->pos = pos;
    new_enemy->sprite = sfSprite_create();
    new_enemy->green_rect = sfRectangleShape_create();
    new_enemy->red_rect = sfRectangleShape_create();
    new_enemy->health = 100;
    new_enemy_set_infos(play, new_enemy, pos, i);
    new_enemy->next = NULL;
    new_enemy->prev = end;
    end->next = new_enemy;
    play->enemy_end = new_enemy;
}

void start_new_wave_misc(play_s *play)
{
    sfVector2f green_rect_pos = {-40, 296};
    sfVector2f red_rect_pos = {-40, 296};

    sfRectangleShape_setSize(play->enemy->green_rect, (sfVector2f){40, 6});
    sfRectangleShape_setFillColor(play->enemy->green_rect, sfGreen);
    sfRectangleShape_setPosition(play->enemy->green_rect, green_rect_pos);

    sfRectangleShape_setSize(play->enemy->red_rect, (sfVector2f){40, 6});
    sfRectangleShape_setFillColor(play->enemy->red_rect, sfRed);
    sfRectangleShape_setPosition(play->enemy->red_rect, red_rect_pos);
    play->enemy->next = NULL;
    play->enemy->prev = NULL;
    play->coin_counter += 75;
    sfText_setString(play->coin_text, my_int_to_str(play->coin_counter));
}

void play_start_new_wave(play_s *play)
{
    sfVector2f pos = {-20, 320};

    play->enemy = malloc(sizeof(*play->enemy));
    play->enemy->alive = true;
    play->enemy->direction = 4;
    play->enemy->pos = pos;
    play->enemy->sprite = sfSprite_create();
    play->enemy->green_rect = sfRectangleShape_create();
    play->enemy->red_rect = sfRectangleShape_create();
    play->enemy->health = 100;
    sfSprite_setTexture(play->enemy->sprite, play->enemy_texture, sfTrue);
    sfSprite_setTextureRect(play->enemy->sprite, (sfIntRect){5, 5, 30, 30});
    sfSprite_setOrigin(play->enemy->sprite, (sfVector2f){15, 15});
    sfSprite_setScale(play->enemy->sprite, (sfVector2f){-1, 1});
    sfSprite_setPosition(play->enemy->sprite, pos);

    start_new_wave_misc(play);

    for (int i = 1; i < play->max_enemy; i++)
        new_enemy(play, pos, i);
}