##
## EPITECH PROJECT, 2017
## groundhog
## File description:
## Makefile
##

SRCF	:=	source/

SRCFC	:=	source/calculs/

SRCFP	:=	source/prints/

SOURCE	:=	$(SRCF)main.c			\
		$(SRCF)groundhog.c		\
		$(SRCF)get_next_line.c		\
		$(SRCFC)compute_all.c		\
		$(SRCFC)compute_g.c		\
		$(SRCFC)compute_r.c		\
		$(SRCFC)compute_s.c		\
		$(SRCFC)compute_aberrations.c		\
		$(SRCFP)print_help.c	\
		$(SRCFP)manage_EOP.c

OBJECT	:=	$(SOURCE:.c=.o)

CPPFLAGS:=	-I include

CFLAGS	:=	-g3 -W -Wall -Wextra -lm

NAME	:=	groundhog

all:	$(NAME)

$(NAME):	$(OBJECT)
	$(CC) -o $@ $^ -lm

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
