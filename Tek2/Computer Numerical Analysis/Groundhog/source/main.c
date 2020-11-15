/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** main.c
*/

#include "groundhog.h"

int check_arg(char **argv)
{
    if (argv[1][0] == '0' && strlen(argv[1]) == 1) {
        return (-1);
    }

    for (unsigned int i = 0 ; i != strlen(argv[1]) ; i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            return (-1);
        }
    }

    return (atoi(argv[1]));
}

int main(int argc, char **argv)
{
    groundhog_t var = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, false};

    if (argc == 2) {
        if (!strcmp(argv[1], "-h")) {
            print_help();
            return (0);
        } else if ((var.days = check_arg(argv)) == -1) {
            return (84);
        }

        return (groundhog(&var));
    } else {
        return (84);
    }

    return (0);
}
