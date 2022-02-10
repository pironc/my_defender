##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

TEST_SRC	=		../src/								\
\
					test_MY_PROJECT_NAME.c 				\

TEST_OBJ	= 		$(TEST_SRC:.c=.o)

TEST_NAME	=		unit_tests

CFLAGS 		= 		-I../include --coverage -lcriterion

LIB 		=		-L../lib/my -lmy

all: $(TEST_NAME)

$(TEST_NAME): 		$(TEST_OBJ)
		gcc -o $(TEST_NAME) $(TEST_OBJ) $(CFLAGS) $(LIB)
		cp ./unit_tests ../

clean:
		$(RM) *.o
		$(RM) *.gc*

fclean:		clean
		$(RM) unit_tests
		$(RM) tests/unit_tests

re: 	fclean all

.PHONY  : all clean fclean re