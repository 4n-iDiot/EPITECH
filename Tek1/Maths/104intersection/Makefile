##
## EPITECH PROJECT, 2018
## 104intersection
## File description:
## Makefile
##

SRC	=	source/main.c	\
			source/sphere.c	\
			source/cylinder.c	\
			source/cone.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/

NAME	=	104intersection

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
