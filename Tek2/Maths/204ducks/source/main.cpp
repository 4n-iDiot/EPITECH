/*
** EPITECH PROJECT, 2019
** 204ducks
** File description:
** main.cpp
*/

#include "ducks.hpp"

void help(void)
{
    std::ifstream file("help");
    std::string help;
    std::string buff;

    if (file.is_open()) {
        while (std::getline(file, buff)) {
            help = help + buff;
            help = help + '\n';
        }

        std::cout << help;
    }
}

int check_arg(char *av)
{
    int count_dot = 0;

    for (int i = 0 ; av[i] != '\0' ; i++) {
        if ((av[i] < '0' || av[i] > '9') && av[i] != '.') {
            return (1);
        }

        if (av[i] == '.') {
            count_dot += 1;
        }

        if (count_dot > 1) {
            return (1);
        }
    }

    if (atof(av) > 2.5 || atof(av) < 0) {
        return (1);
    }

    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (check_arg(av[1]) == 1) {
            return (84);
        }

        Ducks stats(atof(av[1]));
        stats.displayer();
    } else if (ac == 2 && !strcmp(av[1], "-h")) {
        help();
    } else {
        return (84);
    }

    return (0);
}
