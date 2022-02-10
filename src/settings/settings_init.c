/*
** EPITECH PROJECT, 2021
** settings_init.c
** File description:
** function to initialize the main settings
*/

#include "my.h"

void settings_init_sound_button(settings_s *settings)
{
    settings->sound_button_texture_rect = (sfIntRect){0, 0, 310, 300};
    settings->sound_button_sprite = sfSprite_create();
    settings->sound_button_texture = sfTexture_createFromFile(\
    "assets/img/sound_buttons.png", NULL);
    sfSprite_setTexture(settings->sound_button_sprite, \
    settings->sound_button_texture, sfFalse);
    sfSprite_setTextureRect(settings->sound_button_sprite, \
    settings->sound_button_texture_rect);
    sfSprite_setPosition(settings->sound_button_sprite, \
    (sfVector2f){1050, 300});
    sfSprite_setScale(settings->sound_button_sprite, (sfVector2f){0.5, 0.5});
    settings->sound_button_img = sfTexture_copyToImage(\
    settings->sound_button_texture);
}

void settings_init_music_button(settings_s *settings)
{
    settings->music_button_texture_rect = (sfIntRect){0, 0, 310, 300};
    settings->music_button_sprite = sfSprite_create();
    settings->music_button_texture = sfTexture_createFromFile(\
    "assets/img/music_buttons.png", NULL);
    sfSprite_setTexture(settings->music_button_sprite, \
    settings->music_button_texture, sfFalse);
    sfSprite_setTextureRect(settings->music_button_sprite, \
    settings->music_button_texture_rect);
    sfSprite_setPosition(settings->music_button_sprite, (sfVector2f){650, 300});
    sfSprite_setScale(settings->music_button_sprite, (sfVector2f){0.5, 0.5});
    settings->music_button_img = sfTexture_copyToImage(\
    settings->music_button_texture);
}

void settings_init_background(settings_s *settings)
{
    settings->bg_sprite = sfSprite_create();
    settings->bg_texture = sfTexture_createFromFile(\
    "assets/img/menu_bg.png", NULL);
    sfSprite_setTexture(settings->bg_sprite, settings->bg_texture, sfFalse);
    sfSprite_setScale(settings->bg_sprite, (sfVector2f){1.563, 1.41});

    settings->back_arrow_sprite = sfSprite_create();
    settings->back_arrow_texture = sfTexture_createFromFile(\
    "assets/sprite/arrow.png", NULL);
    sfSprite_setTexture(settings->back_arrow_sprite, \
    settings->back_arrow_texture, sfFalse);
    sfSprite_setPosition(settings->back_arrow_sprite, (sfVector2f){350, 95});
}

void settings_init_title(settings_s *settings)
{
    settings->title_sprite = sfSprite_create();
    settings->title_texture = sfTexture_createFromFile(\
    "assets/sprite/buttons_main_menu.png", NULL);
    sfSprite_setTextureRect(settings->title_sprite, \
    (sfIntRect){2760, 0, 460, 110});
    sfSprite_setTexture(settings->title_sprite, \
    settings->title_texture, sfFalse);
    sfSprite_setPosition(settings->title_sprite, (sfVector2f){730, 100});
}

settings_s *settings_init(settings_s *settings)
{
    settings = malloc(sizeof(*settings));
    if (settings == NULL)
        return (NULL);

    settings_init_background(settings);
    settings_init_title(settings);
    settings_init_music_button(settings);
    settings_init_sound_button(settings);

    return (settings);
}