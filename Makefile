##
## EPITECH PROJECT, 2022
## makefile for do_op
## File description:
## makefile for do_op
##

SRC =		sokoban.c		\
		create_tab.c		\
		end.c			\
		error.c			\
		game.c			\
		gestion_interaction.c	\
		my_strlen.c

NAME	=	my_sokoban

FLAG	=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I include/ -lncurses

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)
	rm -f test

re:	fclean all
