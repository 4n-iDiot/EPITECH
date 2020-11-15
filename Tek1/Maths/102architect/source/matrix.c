/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** matrix.c
*/

#include "architect.h"

void display_matrix(matrixA *matrix)
{
	printf("%.2f  ", matrix->matrixbase[0][0]);
	printf("%.2f  ", matrix->matrixbase[0][1]);
	printf("%.2f\n", matrix->matrixbase[0][2]);
	printf("%.2f  ", matrix->matrixbase[1][0]);
	printf("%.2f  ", matrix->matrixbase[1][1]);
	printf("%.2f\n", matrix->matrixbase[1][2]);
	printf("0.00   0.00   1.00\n");
}

int check_arguments(int argc, char **argv)
{
	int i = 0;

	if (argv[3][0] != '-')
		exit (84);

	while (argv[1][i] != '\0') {
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit (84);

		i = i + 1;
	}

	i = 0;

	while (argv[2][i] != '\0') {
		if (argv[2][i] < '0' || argv[2][i] > '9')
			exit (84);

		i = i + 1;
	}

	return (0);
}

int check_flag(char *flag)
{
	if (strlen(flag) != 2)
		exit (84);

	return (0);
}

int check_letters(int k, int l, char **argv)
{
	int i = 0;

	while (argv[k][i] != '\0') {
		if (argv[l][i] < '0' || argv[l][i] > '9')
			exit (84);

		i = i + 1;
	}

	i = 0;

	while (argv[l][i] != '\0') {
		if (argv[l][i] < '0' || argv[l][i] > '9')
			exit (84);

		i = i + 1;
	}

	return (0);
}
