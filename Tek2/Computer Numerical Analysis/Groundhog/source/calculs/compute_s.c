/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** compute_s.c
*/

#include "groundhog.h"

void compute_s(groundhog_t *var)
{
    static int loop = 0;
    float average = 0;
    float variance = 0;

    for (int i = 0; i != var->days ; ++i) {
        average += var->period_temp[i + loop];
    }

    average /= var->days;

    for (int i = 0; i != var->days ; ++i) {
        variance += pow((var->period_temp[i + loop] - average), 2);
    }

    variance /= var->days;
    var->s = pow(variance, 0.5);
    loop = 1;
}
