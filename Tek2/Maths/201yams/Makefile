##
## EPITECH PROJECT, 2018
## 201yams
## File description
## Makefile
##

SOURCE  :=      $(wildcard source/*.cpp)

OBJECT  :=      $(SOURCE:.cpp=.o)

CPPFLAGS:=      -Iinclude

CXXFLAGS:=      -g3 -Wall -Wextra

NAME    :=      201yams

all: $(NAME)

$(NAME): $(OBJECT)
		$(CXX) -o $@ $^

clean:
		$(RM) $(OBJECT)

fclean: clean
		$(RM) $(NAME)

re: clean all

test: all
		./$(NAME) | cat -e | diff output -

.PHONY: re clean fclean all test
