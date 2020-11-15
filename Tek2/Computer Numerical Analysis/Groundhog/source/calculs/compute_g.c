/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** compute_g.c
*/

#include "groundhog.h"

void compute_g(groundhog_t *var)
{
    float average = 0;

    for (int i = 0, j = 1; i != var->days ; ++i, ++j) {
      if (var->period_temp[j] > var->period_temp[i]) {
          average += fabsf((var->period_temp[j] - var->period_temp[i]));
      }
    }

    var->g = average / var->days;
}
