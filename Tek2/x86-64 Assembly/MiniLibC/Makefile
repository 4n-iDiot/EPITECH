##
## EPITECH PROJECT, 2019
## malloc
## File description:
## Makefile
##

SOURCES	=	sources/strlen.asm	\
			sources/strchr.asm	\
			sources/strcmp.asm	\
			sources/strncmp.asm	\
			sources/strcspn.asm	\
			sources/strpbrk.asm	\
			sources/strcasecmp.asm	\
			sources/strstr.asm	\
			sources/memset.asm	\
			sources/memcpy.asm	\
			sources/rindex.asm

CFLAGS	+=	- fPIC -shared

ASMFLAGS	=	-f elf64

NAME	=	libasm.so

OBJS	=	$(SOURCES:.asm=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ld $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.asm
	nasm $(ASMFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
