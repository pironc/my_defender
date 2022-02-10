/*
** EPITECH PROJECT, 2020
** _MY_H_
** File description:
** _MY_H_
*/

#ifndef _MY_H_
#define _MY_H_

#include "my_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/* STRUCTS */

typedef struct enemy_t {
    sfVector2f pos;
    sfSprite *sprite;
    int direction;
    bool alive;
    struct enemy_t *next;
    struct enemy_t *prev;
    int health;
    sfRectangleShape *green_rect;
    sfRectangleShape *red_rect;
}enemy_s;

typedef struct towers_t {
    float type;
    int radius;
    int tier;
    sfSprite *spr;
    sfSprite *arrow_spr;
    sfCircleShape *circle;
    sfClock *clock;
    sfClock *upgrade_clock;
    float upgrade_ms;
    float elapsed;
}towers_s;

typedef struct game_t {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    int cur_scn;
    int current_score;
    int highest_score;

    //Sound
    sfSoundBuffer *click_soundbuffer;
    sfSound *click_sound;
    sfMusic *music;
    sfBool music_status;
    sfBool sound_status;
    sfSoundBuffer *hitmarker_soundbuffer;
    sfSound *hitmarker_sound;
}game_s;

typedef struct menu_t {
    // Background
    sfSprite *bg_sprite;
    sfTexture *bg_texture;

    // Logo
    sfSprite *logo_sprite;
    sfTexture *logo_texture;
    sfSprite *logo_star_spr;
    sfTexture *logo_star_texture;

    /* Buttons */

    //Play
    sfSprite *play_spr;
    sfImage *play_img;

    //Howtoplay
    sfSprite *howtoplay_spr;
    sfImage *howtoplay_img;

    //Settings
    sfSprite *settings_spr;
    sfImage *settings_img;

    //Quit
    sfSprite *quit_spr;
    sfImage *quit_img;

    sfTexture *buttons_texture;

    //Highest score
    sfText *highest_score_title_txt;
    sfText *high_score_txt;
    sfFont *font;
}menu_s;

typedef struct play_t { //TODO almost done
    //Sprite map
    sfSprite *map_sprite;
    sfTexture *map_texture;

    //Rectangles collision
    sfRectangleShape **collision_rects;
    sfFloatRect *collision_bounds;

    //Background hud
    sfSprite *hud_sprite;
    sfTexture *hud_texture;

    //Skip button
    sfSprite *skip_sprite;
    sfTexture *skip_texture;

    //Towers hud
    sfSprite *tower1_hud_sprite;
    sfSprite *tower2_hud_sprite;
    sfSprite *tower3_hud_sprite;
    sfSprite *tower4_hud_sprite;
    sfTexture *tower_hud_textures;

    //Coins
    sfSprite *coin_sprite;
    sfTexture *coin_texture;
    sfText *coin_text;
    sfIntRect coin_texture_rect;
    int *tower_cost;
    int coin_counter;
    sfClock *coin_clock;
    sfTime coin_time;
    float coin_chrono;

    //Heart
    sfSprite *heart_sprite;
    sfTexture *heart_texture;
    sfText *heart_text;
    int heart_counter;

    //Score
    sfText *score_text;
    sfText *score_count_text;
    int score;

    //Next wave
    sfSprite *next_wave_spr;
    sfTexture *next_wave_texture;

    //Timer
    sfText *timer_text;
    sfClock *timer_clock;
    float timer_elapsed_ms;
    int timer;
    float paused_timer;

    //Towers map
    sfTexture *tower_map_textures;
    sfImage *towers_img;
    struct towers_t **towers;

    //Pause
    sfSprite *pause_header_spr;
    sfTexture *pause_header_texture;

    sfSprite *pause_resume_spr;
    sfImage *pause_resume_img;
    sfSprite *pause_menu_spr;
    sfImage *pause_menu_img;
    sfSprite *pause_exit_spr;
    sfImage *pause_exit_img;
    sfTexture *pause_spritesheet;

    sfRectangleShape *pause_bg;

    //Fade out
    sfImage *fade_image;
    sfSprite *fade_sprite;
    sfTexture *fade_texture;
    sfColor fade_black;

    int fade_status;
    sfTime fade_timer;
    sfClock *fade_clock;

    //Enemy
    sfTexture *enemy_texture;
    struct enemy_t *enemy;
    int max_enemy;
    sfClock *enemy_clock;
    struct enemy_t *enemy_end;

    //Misc
    sfFont *font;
    sfTexture *arrow_texture;
    int selected;
    int hovered;
    bool pause;
}play_s;

typedef struct howtoplay_t { //TODO 100% DONE
    sfSprite *bg_sprite;
    sfTexture *bg_texture;

    sfSprite *back_arrow_sprite;
    sfTexture *back_arrow_texture;
}howtoplay_s;

typedef struct settings_t { // 30% DONE (add music/sound on/off)
    //TODO remove (unused in the play scene later on)

    sfSprite *bg_sprite;
    sfTexture *bg_texture;

    sfSprite *title_sprite;
    sfTexture *title_texture;

    sfSprite *back_arrow_sprite;
    sfTexture *back_arrow_texture;

    sfSprite *music_button_sprite;
    sfTexture *music_button_texture;
    sfImage *music_button_img;
    sfIntRect music_button_texture_rect;

    sfSprite *sound_button_sprite;
    sfTexture *sound_button_texture;
    sfImage *sound_button_img;
    sfIntRect sound_button_texture_rect;
}settings_s;

typedef struct game_over_t { //TODO 0% DONE
    sfSprite *score_title_spr;
    sfTexture *score_title_texture;

    sfText *score_text;
    sfFont *font;

    sfSprite *back_sprite;
    sfTexture *back_texture;
}game_over_s;

/* LIB FUNCTIONS */

int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);
int my_strlen(char *str);
int my_str_isnum(char const *str);
int my_str_isalpha(char const *str);
char *my_int_to_str(int nb);
char *my_uint_to_str(unsigned int nb);
int my_atoi(const char *nptr);
unsigned int my_atoui(const char *nptr);
void my_put_unsigned_nbr(unsigned int nb);
int print_error(char *str);
int my_arrlen(char **arr);
char *my_strdup(char const *src);

// CSFML

void init_object(sfSprite **spr, sfTexture **texture, char *texture_path);
void init_sound(sfSound *sound, sfSoundBuffer *soundbuffer, char *filepath);
void text_init(sfText *text, char *string, unsigned int size, sfColor color);
void text_set_font(sfText *text, sfFont *font, char *font_path);
void text_set_outlinecolor(sfText *text, float thickness, sfColor color);
sfBool is_sprite_clicked(game_s *game, sfSprite *spr, sfImage *img, sfVector2i mpos);
sfBool is_sprite_clicked_raw(game_s *game, sfSprite *spr, sfVector2i mpos);
sfBool is_sprite_hovered(game_s *game, sfSprite *spr, sfImage *img, sfVector2i mpos);
sfBool is_sprite_hovered_raw(game_s *game, sfSprite *spr, sfVector2i mpos);
bool is_tower_hovered(game_s *game, play_s *play, sfVector2i mpos);
float distance_between_sprite_circle(sfSprite *sprite, sfCircleShape *circle);

/* PROJECT FUNCTIONS */

int my_defender(void);

/*

0 : menu ->
        4 buttons
            play
            how to play
            settings
            quit

1 : play ->
        N/A

2 : how to play ->
        1 image
        1 back button (middle bottom)

3 : settings ->
        Music ON/OFF
            music slider?
        Sound effects ON/OFF

4 : game over

*/

void set_rect(sfSprite *spr, sfIntRect rect);

// menu
int menu(game_s *game);
menu_s *menu_init(game_s *game, menu_s *menu);
void menu_init_buttons(menu_s *menu);
void menu_keycheck(game_s *game, menu_s *menu);
void menu_draw(game_s *game, menu_s *menu);
void menu_dispose(menu_s *menu);

//play
int play(game_s *game);

play_s *play_init(play_s *play);
void play_init_map(play_s *play);
void play_init_hud(play_s *play);
void play_init_towers_hud(play_s *play);
void play_init_towers_map(play_s *play);
void play_init_collision(play_s *play);
void play_init_pause(play_s *play);
void play_init_score(play_s *play);
void play_init_heart(play_s *play);
void play_init_coins(play_s *play);

void play_set_tower_infos(play_s *play);
void play_collision_check(game_s *game, play_s *play);
void play_move_enemy(play_s *play);
void play_keycheck_tower_map(game_s *game, play_s *play, sfVector2i mpos);
void is_enemy_in_circle(play_s *play, int i, game_s *game);

void play_start_new_wave(play_s *play);

void play_keycheck(game_s *game, play_s *play);
void play_keycheck_towers_hud(game_s *game, play_s *play, sfVector2i mpos);
void play_pause_buttons_check(play_s *play, sfVector2i mpos, game_s *game);
void play_is_wave_ended(play_s *play);
void play_fade_start(game_s *game, play_s *play);
void attack_enemy(towers_s *tower, enemy_s *enemy, play_s *play, game_s *game);
void animate_coin(play_s *play);
void tower_upgrade_check(game_s *game, play_s *play, sfVector2i mpos, int i);

void play_draw(game_s *game, play_s *play);

void play_dispose(play_s *play);

//howtoplay
int howtoplay(game_s *game);
howtoplay_s *howtoplay_init(howtoplay_s *howtoplay);
void howtoplay_keycheck(game_s *game, howtoplay_s *howtoplay);
void howtoplay_draw(game_s *game, howtoplay_s *howtoplay);
void howtoplay_dispose(howtoplay_s *howtoplay);

//settings
int settings(game_s *game);
settings_s *settings_init(settings_s *settings);
void settings_keycheck(game_s *game, settings_s *settings);
void settings_draw(game_s *game, settings_s *settings);
void settings_dispose(settings_s *settings);

void change_sound_status(game_s *game);
void change_music_status(game_s *game);

void update_music_sound_status(game_s *game);
void update_music_sounds_buttons(game_s *game, settings_s *settings);

//game_over
int game_over(game_s *game);
game_over_s *game_over_init(game_s *game, game_over_s *game_over);
void game_over_keycheck(game_s *game, game_over_s *game_over);
void game_over_draw(game_s *game, game_over_s *game_over);
void game_over_dispose(game_over_s *game_over);

#endif /* !_MY_H_ */