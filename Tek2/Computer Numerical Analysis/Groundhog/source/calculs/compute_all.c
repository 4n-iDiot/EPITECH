/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** compute_all.c
*/

#include "groundhog.h"

void compute_all(groundhog_t *var)
{
    if (var->temp_count == var->days) {
        compute_s(var);
        printf("g=nan\tr=nan%c\ts=%.2f\n", '%',var->s);
    } else if (var->temp_count >= var->days + 1) {
        compute_g(var);
        compute_r(var);
        compute_s(var);
        compute_aberrations(var);
        if ((var->oldR > 0 && var->r < 0) || (var->oldR < 0 && var->r > 0)) {
            var->tendency += 1;
            printf("g=%.2f\tr=%.0f%c\ts=%.2f\ta switch occurs\n",
                    var->g, var->r, '%',var->s);
        } else {
            printf("g=%.2f\tr=%.0f%c\ts=%.2f\n", var->g, var->r, '%',var->s);
        }
    } else {
        printf("g=nan\tr=nan%c\ts=nan\n", '%');
    }

    var->oldR = var->r;
}
