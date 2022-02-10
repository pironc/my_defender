##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## lib makefile
##

SRC		=		my_getnbr.c					\
				my_atoi.c					\
				my_atoui.c					\
				my_int_to_str.c				\
				my_uint_to_str.c			\
				my_put_nbr.c 				\
				my_put_unsigned_nbr.c 		\
				my_putchar.c 				\
				my_putstr.c 				\
				my_revstr.c 				\
				my_strlen.c 				\
				my_str_isalpha.c 			\
				my_str_isnum.c 				\
				my_strcmp.c 				\
				my_strncmp.c 				\
				my_strcpy.c 				\
				my_strncpy.c 				\
				print_error.c 				\
				my_arrlen.c 				\
				my_putarr.c 				\
				my_str_to_word_array.c      \
				my_strdup.c 				\
				my_strcat.c 				\
				my_str_begin_matches.c 		\
\
				my_printf/my_printf.c					\
				my_printf/flags_0to4.c					\
				my_printf/flags_bases.c					\
				my_printf/flags_check.c					\
				my_printf/flags_special.c				\
				my_printf/special_flags.c				\
				my_printf/modulo_check.c				\
				my_printf/my_put_unsigned_nbr.c			\
				my_printf/flags_bases_nesteds.c 		\
				my_printf/flags_0to4_nesteds.c 			\
\
				CSFML/init_object.c 					\
				CSFML/create_sound.c 					\
				CSFML/create_text.c 					\
				CSFML/is_sprite_clicked.c 				\
				CSFML/is_sprite_clicked_raw.c 			\
				CSFML/is_sprite_hovered.c 				\
				CSFML/is_sprite_hovered_raw.c 			\
				CSFML/is_tower_hovered.c 			\

OBJ 	= 		$(SRC:.c=.o)

NAME 	=		libmy.a

CFLAGS 	=		-I../../include

all: $(NAME)

$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)