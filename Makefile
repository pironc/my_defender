##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

SRC			=		src/main.c 									\
					src/my_defender.c 							\
\
					src/menu/menu.c 							\
					src/menu/menu_init.c 						\
					src/menu/menu_init_buttons.c 				\
					src/menu/menu_keycheck.c 					\
					src/menu/menu_draw.c	 					\
					src/menu/menu_dispose.c	 					\
\
					src/play/play.c 							\
					src/play/play_init.c 						\
					src/play/play_init_map.c 					\
					src/play/play_init_hud.c 					\
					src/play/play_init_hud_extra.c				\
					src/play/play_init_towers_hud.c 			\
					src/play/play_init_towers_map.c 			\
					src/play/play_init_collision.c 				\
					src/play/play_init_pause.c 					\
\
					src/play/play_collision_check.c 			\
					src/play/play_check_tower_map.c 			\
					src/play/play_wave_check.c 					\
					src/play/play_check_fade.c 					\
					src/play/play_attack_enemy.c				\
					src/play/play_new_wave.c 					\
					src/play/play_move_enemy.c 					\
					src/play/play_animate_coin.c 				\
\
					src/play/play_set_tower_infos.c 			\
					src/play/play_keycheck.c 					\
					src/play/play_keycheck_towers_hud.c 		\
					src/play/play_pause_check.c 				\
					src/play/play_draw.c	 					\
					src/play/play_dispose.c	 					\
					src/play/play_check_radius.c 				\
\
					src/howtoplay/howtoplay.c 					\
					src/howtoplay/howtoplay_init.c 				\
					src/howtoplay/howtoplay_keycheck.c 			\
					src/howtoplay/howtoplay_draw.c	 			\
					src/howtoplay/howtoplay_dispose.c	 		\
\
					src/settings/settings.c 					\
					src/settings/settings_init.c 				\
					src/settings/settings_keycheck.c 			\
					src/settings/settings_change_audio.c 		\
					src/settings/settings_draw.c	 			\
					src/settings/settings_dispose.c	 			\
\
					src/game_over/game_over.c 					\
					src/game_over/game_over_init.c 				\
					src/game_over/game_over_keycheck.c 			\
					src/game_over/game_over_draw.c	 			\
					src/game_over/game_over_dispose.c	 		\

OBJ 		= 		$(SRC:.c=.o)

NAME 		=		my_defender

#Werror

CFLAGS 		= 		-Wextra -Wshadow -W -Wall -lcsfml-graphics \
					-lcsfml-window -lcsfml-system -lcsfml-audio -I./include \
					-lm

LIB 		=		-L./lib/my -lmy

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		$(RM) src/*.o
		$(RM) src/*.gc*
		$(RM) src/menu/*.o
		$(RM) src/menu/*.gc*
		$(RM) src/play/*.o
		$(RM) src/play/*.gc*
		$(RM) src/howtoplay/*.o
		$(RM) src/howtoplay/*.gc*
		$(RM) src/settings/*.o
		$(RM) src/settings/*.gc*
		$(RM) tests/*.o
		$(RM) tests/*.gc*
		$(RM) lib/my/*.o
		$(RM) lib/my/*.gc*
		$(RM) lib/my/my_printf/*.o
		$(RM) lib/my/my_printf/*.gc*
		$(RM) lib/my/CSFML/*.o
		$(RM) lib/my/CSFML/*.gc*

fclean:		clean
		$(RM) unit_tests
		$(RM) tests/unit_tests
		$(RM) lib/my/libmy.a
		$(RM) my_defender

re: 	fclean all

run_tests:
		make -C lib/my/
		make -C tests/
		./unit_tests

.PHONY  : all clean fclean re test