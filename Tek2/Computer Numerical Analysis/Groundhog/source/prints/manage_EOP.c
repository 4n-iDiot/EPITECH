/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** manage_EOP.c
*/

#include "groundhog.h"

void manage_EOP(groundhog_t *var)
{
    printf("Global tendency switched %i times\n", var->tendency);
    printf("5 weirdest values are [");
    for (int i = 0 ; i != 5 ; i++) {
        printf("%.1f", var->biggest_abe[i]);

        if (i == 4) {
            break;
        }

        printf(", ");
    }

    printf("]\n");
    free(var->all_temp);
    free(var->period_temp);
    free(var->aberration);
    free(var->biggest_abe);
}
