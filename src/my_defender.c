/*
** EPITECH PROJECT, 2021
** my_defender.c
** File description:
** main my_defender function
*/

#include "my.h"

void sounds_init(game_s *game)
{
    game->music = sfMusic_createFromFile("assets/FlowerGarden.ogg");
    game->click_sound = sfSound_create();
    game->click_soundbuffer = \
    sfSoundBuffer_createFromFile("assets/sound/pet1.ogg");
    game->hitmarker_sound = sfSound_create();
    game->hitmarker_soundbuffer = \
    sfSoundBuffer_createFromFile("assets/sound/hitmarker.ogg");
    sfSound_setBuffer(game->click_sound, game->click_soundbuffer);
    sfMusic_setVolume(game->music, 1);
    sfSound_setVolume(game->click_sound, 1);
    sfMusic_setLoop(game->music, sfTrue);
    sfSound_setBuffer(game->hitmarker_sound, game->hitmarker_soundbuffer);
    sfSound_setVolume(game->hitmarker_sound, 1);
}

int get_file_size(char *str)
{
    char *c = malloc(sizeof(char) * 1);
    int count = 0;
    int fd = open(str, O_RDONLY);

    while (read(fd, c, 1) == 1)
        count++;
    close(fd);
    return (count);
}

game_s *game_init(game_s *game)
{
    game = malloc(sizeof(*game));
    int fd = 0;
    int file_size = 0;
    char *score = NULL;

    game->cur_scn = 0;
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, \
    "Paint Defender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 144);
    sounds_init(game);

    game->highest_score = 0;
    game->current_score = 0;

    if ((fd = open("score", O_RDONLY)) == -1)
        return (game);
    file_size = get_file_size("score");
    score = malloc(sizeof(char) * (file_size + 1));
    score[file_size] = '\0';
    read(fd, score, file_size);
    game->highest_score = my_atoi(score);

    return (game);
}

void game_dispose(game_s *game)
{
    sfSoundBuffer_destroy(game->hitmarker_soundbuffer);
    sfSound_destroy(game->hitmarker_sound);
    sfSoundBuffer_destroy(game->click_soundbuffer);
    sfSound_destroy(game->click_sound);
    sfMusic_destroy(game->music);
    free(game);
}

int my_defender(void)
{
    int (*scene[])(game_s*) = {menu, play, howtoplay, settings, game_over};
    game_s *game = NULL;
    game = game_init(game);

    sfMusic_play(game->music);
    while (sfRenderWindow_isOpen(game->window)) {
        scene[game->cur_scn](game);
    }
    game_dispose(game);
    return (0);
}