/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** compute_r.c
*/

#include "groundhog.h"

void compute_r(groundhog_t *var)
{
    var->r =
    ((var->period_temp[var->days] - var->period_temp[0])
    / var->period_temp[0]) * 100;
}
