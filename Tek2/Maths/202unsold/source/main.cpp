/*
** EPITECH PROJECT, 2019
** 202Unsold
** File description:
** main.cpp
*/

#include "unsold.hpp"

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

int check_arg(char **av)
{
    for (unsigned int i = 0 ; i != strlen(av[1]) ; i++) {
        if (av[1][i] < '0' || av[1][i] > '9') {
            return (1);
        }
    }

    for (unsigned int i = 0 ; i != strlen(av[2]) ; i++) {
        if (av[2][i] < '0' || av[2][i] > '9') {
            return (1);
        }
    }

    if (atoi(av[1]) < 50 || atoi(av[2]) < 50) {
        return (1);
    }

    return (0);
}

int main(int ac, char **av)
{
    if (ac == 3) {
        if (check_arg(av) == 1) {
            return (84);
        }

        unsold proba(atoi(av[1]), atoi(av[2]));
        proba.probability();
        proba.display_first_part();
        proba.display_second_part();
        proba.display_third_part();
    } else if (ac == 2 && !strcmp(av[1], "-h")) {
        help();
    } else {
        return (84);
    }

    return (0);
}
