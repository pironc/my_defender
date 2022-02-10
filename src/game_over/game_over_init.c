/*
** EPITECH PROJECT, 2021
** game_over_init.c
** File description:
** function to initialize the main game_over
*/

#include "my.h"

void game_over_init_back(game_over_s *game_over)
{
    game_over->back_texture = sfTexture_createFromFile(\
    "assets/sprite/back_to_menu.png", NULL);
    game_over->back_sprite = sfSprite_create();
    sfSprite_setTexture(game_over->back_sprite, \
    game_over->back_texture, sfTrue);
    sfSprite_setPosition(game_over->back_sprite, (sfVector2f){650, 620});
    sfSprite_setTextureRect(game_over->back_sprite, \
    (sfIntRect){0, 0, 620, 149});
}

void game_over_init_score(game_s *game, game_over_s *game_over)
{
    int score = game->current_score;
    int offset = 1920 / 2 - (my_strlen(my_int_to_str(score)) * 13);
    sfVector2f pos = {offset, 520};

    game_over->score_text = sfText_create();
    game_over->font = sfFont_createFromFile("assets/font/comic.ttf");
    sfText_setString(game_over->score_text, my_int_to_str(score));
    sfText_setFont(game_over->score_text, game_over->font);
    sfText_setColor(game_over->score_text, sfWhite);
    sfText_setCharacterSize(game_over->score_text, 40);
    sfText_setPosition(game_over->score_text, pos);
}

void game_over_init_title(game_over_s *game_over)
{
    game_over->score_title_texture = sfTexture_createFromFile(\
    "assets/sprite/game_over_header.png", NULL);
    game_over->score_title_spr = sfSprite_create();
    sfSprite_setTexture(\
    game_over->score_title_spr, game_over->score_title_texture, sfTrue);
    sfSprite_setPosition(game_over->score_title_spr, (sfVector2f){676.5, 200});
}

game_over_s *game_over_init(game_s *game, game_over_s *game_over)
{
    game_over = malloc(sizeof(*game_over));
    if (game_over == NULL)
        return (NULL);

    game_over_init_title(game_over);
    game_over_init_score(game, game_over);
    game_over_init_back(game_over);
    return (game_over);
}