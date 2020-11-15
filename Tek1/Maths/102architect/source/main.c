/*
** EPITECH PROJECT, 2017
** 102arcitect
** File description:
** 102architect.c
*/

#include "architect.h"

char get_flags(char *arg, int argc, char **argv)
{
	if (arg[1] == 't') {
		if (argc != 6)
			exit (84);

		return ('t');
	} else if (arg[1] == 'h') {
		if (argc != 6)
			exit (84);

		return ('h');
	} else if (arg[1] == 'r') {
		if (argc != 5)
			exit (84);

		return ('r');
	} else if (arg[1] == 's') {
		if (argc != 5)
			exit (84);

		return ('s');
	}

	exit(84);
}

int get_params(char **argv, int i, char flag, matrixA *matrix)
{
	float params1 = 0;
	float params2 = 0;

	if (flag == 't') {
		params1 = atof(argv[i + 1]);
		params2 = atof(argv[i + 2]);
		compute_translation(params1, params2, matrix);

		return (0);
	} else if (flag == 'h') {
		params1	= atof(argv[i + 1]);
		params2	= atof(argv[i + 2]);
		compute_homothety(params1, params2, matrix);

		return (0);
	} else if (flag == 'r' || flag == 's') {
		get_params_2(argv, i, flag, matrix);

		return (0);
	}

	exit (84);
}

int get_params_2(char **argv, int i, char flag, matrixA *matrix)
{
	float params1 = 0;

	if (flag == 'r') {
		params1 = atof(argv[i + 1]);
		compute_rotation(params1, matrix);

		return (0);
	} else if (flag == 's') {
		params1 = atof(argv[i + 1]);
		compute_symetry(params1, matrix);

		return (0);
  }

	exit (84);
}

void init_matrix(matrixA *matrix)
{
	matrix->matrixbase[0][0] = (float) 1;
	matrix->matrixbase[0][1] = (float) 0;
	matrix->matrixbase[0][2] = (float) 0;
	matrix->matrixbase[1][0] = (float) 0;
	matrix->matrixbase[1][1] = (float) 1;
	matrix->matrixbase[1][2] = (float) 0;
	matrix->matrixbase[2][0] = (float) 0;
	matrix->matrixbase[2][1] = (float) 0;
	matrix->matrixbase[2][2] = (float) 1;
}

int main(int argc, char **argv)
{
	matrixA matrix;
	char flag;
	int i = 3;
	int error = 0;

	if (argc < 5)
		exit (84);

	check_arguments(argc, argv);
	init_matrix(&matrix);
	matrix.x = atof(argv[1]);
	matrix.y = atof(argv[2]);
	check_flag(argv[3]);
	flag = get_flags(argv[3], argc, argv);
	get_params(argv, i, flag, &matrix);

	return (0);
}
