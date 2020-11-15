/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** architect.h
*/

#ifndef ARCHITECT_H_
#define ARCHITECT_H_

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct matrix {
	float x;
	float y;
	float matrixbase[3][3];
} matrixA;


/* MAIN.C */
char get_flags(char *arg, int argc, char **argv);
int get_params(char **argv, int i, char flag, matrixA *matrix);
int get_params_2(char **argv, int i, char flag, matrixA *matrix);

/* CALCUL.C */
void compute_translation(float i, float j, matrixA *matrix);
void compute_rotation(float alpha, matrixA *matrix);
void compute_homothety(float m, float n, matrixA *matrix);
void compute_symetry(float alpha, matrixA *matrix);

/* MATRIX.C */
void display_matrix(matrixA *matrix);
int check_after_flag(char flag, int argc, char **argv);
int check_flag(char *flag);
int check_arguments(int argc, char **argv);

#endif /* ARCHITECT_H_ */
