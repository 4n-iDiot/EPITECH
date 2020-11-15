/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** groundhog.h
*/

#ifndef GROUNDHOG_H_
  #define GROUNDHOG_H_

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

typedef struct groundhog_s {
    float *all_temp;
    float *period_temp;
    float *aberration;
    float *biggest_abe;
    int days;
    int temp_count;
    int abe_count;
    int tendency;
    int all_count;
    float g;
    float r;
    float s;
    float oldR;
    bool is_r_neg;
} groundhog_t;

/* GENERAL */
char *get_next_line(int fd);
int groundhog(groundhog_t *var);

/* CALCULUS */
void compute_all(groundhog_t *var);
void compute_g(groundhog_t *var);
void compute_r(groundhog_t *var);
void compute_s(groundhog_t *var);
void compute_aberrations(groundhog_t *var);
int get_biggest_abe(groundhog_t *var);

/* PRINTS */
void print_help();
void manage_EOP(groundhog_t *var);

#endif /* GROUNDHOG_H_ */
