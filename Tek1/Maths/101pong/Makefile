##
## EPITECH PROJECT, 2017
## 101pong
## File description:
## Makefile
##

SRC	=	source/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lm -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
