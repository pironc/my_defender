/*
** EPITECH PROJECT, 2021
** menu_keycheck.c
** File description:
** functions to check for key presses
*/

#include "my.h"

void menu_play_button_check(game_s *game, menu_s *menu, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->play_spr);

    if (is_sprite_hovered(game, menu->play_spr, menu->play_img, mpos)) {
        sfSprite_setTextureRect(menu->play_spr, (sfIntRect){460, 0, 460, 110});
    } else {
        sfSprite_setTextureRect(menu->play_spr, (sfIntRect){0, 0, 460, 110});
    }
    if (is_sprite_clicked(game, menu->play_spr, menu->play_img, mpos)) {
        sfSprite_setTextureRect(menu->play_spr, (sfIntRect){920, 0, 460, 110});
        sfSound_play(game->click_sound);
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        game->cur_scn = 1;
}

void menu_howtoplay_button_check(game_s *game, menu_s *menu, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->howtoplay_spr);

    if (is_sprite_hovered(game, menu->howtoplay_spr, menu->howtoplay_img, mpos)) {
        sfSprite_setTextureRect(menu->howtoplay_spr, \
        (sfIntRect){1840, 0, 460, 110});
    } else {
        sfSprite_setTextureRect(menu->howtoplay_spr, \
        (sfIntRect){1380, 0, 460, 110});
    }
    if (is_sprite_clicked(game, menu->howtoplay_spr, menu->howtoplay_img, mpos)) {
        sfSprite_setTextureRect(menu->howtoplay_spr, \
        (sfIntRect){2300, 0, 460, 110});
        sfSound_play(game->click_sound);
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        game->cur_scn = 2;
}

void menu_settings_button_check(game_s *game, menu_s *menu, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->settings_spr);

    if (is_sprite_hovered(game, menu->settings_spr, menu->settings_img, mpos)) {
        sfSprite_setTextureRect(menu->settings_spr, \
        (sfIntRect){3220, 0, 460, 110});
    } else {
        sfSprite_setTextureRect(menu->settings_spr, \
        (sfIntRect){2760, 0, 460, 110});
    }
    if (is_sprite_clicked(game, menu->settings_spr, menu->settings_img, mpos)) {
        sfSprite_setTextureRect(menu->settings_spr, \
        (sfIntRect){3680, 0, 460, 110});
        sfSound_play(game->click_sound);
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        game->cur_scn = 3;
}

void menu_quit_button_check(game_s *game, menu_s *menu, sfVector2i mpos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(menu->quit_spr);

    if (is_sprite_hovered(game, menu->quit_spr, menu->quit_img, mpos)) {
        sfSprite_setTextureRect(menu->quit_spr, (sfIntRect){5980, 0, 460, 110});
    } else {
        sfSprite_setTextureRect(menu->quit_spr, (sfIntRect){5520, 0, 460, 110});
    }
    if (is_sprite_clicked(game, menu->quit_spr, menu->quit_img, mpos)) {
        sfSprite_setTextureRect(menu->quit_spr, (sfIntRect){6440, 0, 460, 110});
        sfSound_play(game->click_sound);
    }
    if (game->event.type == sfEvtMouseButtonReleased && \
        sfFloatRect_contains(&rect, mpos.x, mpos.y))
        sfRenderWindow_close(game->window);
}

void menu_keycheck(game_s *game, menu_s *menu)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        menu_play_button_check(game, menu, mpos);
        menu_howtoplay_button_check(game, menu, mpos);
        menu_settings_button_check(game, menu, mpos);
        menu_quit_button_check(game, menu, mpos);
    }
}