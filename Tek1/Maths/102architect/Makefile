##
## EPITECH PROJECT, 2017
## 102architect
## File description:
## Makefile
##

SRC	=	source/matrix.c	\
			source/main.c	\
			source/calcul.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lm -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
