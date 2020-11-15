/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** compute_aberrations.c
*/

#include "groundhog.h"

int check_if_saved(groundhog_t *var, int j, int k)
{
    for (int i = 0 ; i != k ; i++) {
        if (var->biggest_abe[i] == var->all_temp[j + var->days]) {
            return (1);
        }
    }

    return (0);
}

int get_biggest_abe_2(groundhog_t *var, int k, int value)
{
    float temp = fabsf(var->aberration[0]);

    for (int i = 1 ; i != var->abe_count ; i++) {
        if (fabsf(var->aberration[i]) >= temp && !check_if_saved(var, i, k)) {
            temp = var->aberration[i];
            value = i;
        }
    }

    return (value);
}

int get_biggest_abe(groundhog_t *var)
{
    int value = 0;

    var->biggest_abe = calloc(5, sizeof(float));

    if (var->abe_count < var->days) {
        return (84);
    }

    for (int k = 0 ; k != 5 ; k++) {
        value = get_biggest_abe_2(var, k, value);
        var->biggest_abe[k] = var->all_temp[value + var->days];
    }

    return (0);
}

void compute_aberrations(groundhog_t *var)
{
    float theo_val = 0;
    float exp_val = 0;

    theo_val = var->g;
    exp_val =
        fabs(var->period_temp[var->days] - var->period_temp[var->days - 1]);

    if (var->abe_count >= var->days + 1) {
        var->aberration =
        realloc(var->aberration, (var->abe_count + 1) * sizeof(float));
    }

    var->aberration[var->abe_count] = fabsf(exp_val - theo_val);
    var->abe_count ++;
}
