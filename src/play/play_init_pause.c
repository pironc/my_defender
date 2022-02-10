/*
** EPITECH PROJECT, 2021
** play_init_pause.c
** File description:
** functions to initialize pause menu in play
*/

#include "my.h"

void play_init_pause_header(play_s *play)
{
    play->pause_header_texture = sfTexture_createFromFile(\
    "assets/sprite/pause_header.png", NULL);
    play->pause_header_spr = sfSprite_create();
    sfSprite_setTexture(play->pause_header_spr, \
    play->pause_header_texture, sfTrue);
    sfSprite_setPosition(play->pause_header_spr, (sfVector2f){762.5, 250});
}

void play_init_pause_resume(play_s *play)
{
    play->pause_resume_spr = sfSprite_create();
    sfSprite_setTexture(play->pause_resume_spr, \
    play->pause_spritesheet, sfTrue);
    sfSprite_setTextureRect(play->pause_resume_spr, \
    (sfIntRect){0, 0, 347, 110});
    sfSprite_setPosition(play->pause_resume_spr, (sfVector2f){786.5, 420});
    play->pause_resume_img = sfTexture_copyToImage(play->pause_spritesheet);
}

void play_init_pause_menu(play_s *play)
{
    play->pause_menu_spr = sfSprite_create();
    sfSprite_setTexture(play->pause_menu_spr, play->pause_spritesheet, sfTrue);
    sfSprite_setTextureRect(play->pause_menu_spr, \
    (sfIntRect){1041, 0, 347, 110});
    sfSprite_setPosition(play->pause_menu_spr, (sfVector2f){786.5, 550});
    play->pause_menu_img = sfTexture_copyToImage(play->pause_spritesheet);
}

void play_init_pause_exit(play_s *play)
{
    play->pause_exit_spr = sfSprite_create();
    sfSprite_setTexture(play->pause_exit_spr, play->pause_spritesheet, sfTrue);
    sfSprite_setTextureRect(play->pause_exit_spr, \
    (sfIntRect){2082, 0, 347, 110});
    sfSprite_setPosition(play->pause_exit_spr, (sfVector2f){786.5, 680});
    play->pause_exit_img = sfTexture_copyToImage(play->pause_spritesheet);
}

void play_init_pause(play_s *play)
{
    play->pause_spritesheet = sfTexture_createFromFile(\
    "assets/sprite/pause_menu_spritesheet.png", NULL);

    play_init_pause_header(play);
    play_init_pause_resume(play);
    play_init_pause_menu(play);
    play_init_pause_exit(play);
}