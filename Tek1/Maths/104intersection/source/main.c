/*
** EPITECH PROJECT, 2017
** 104intersection
** File description:
** main.c
*/

#include "intersection.h"

void scan_char(char **argv, int i, int j)
{
	if (argv[i][j] < '0' || argv[i][j] > '9')
		exit (84);
}

void check_valid_arguments(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	while (i != argc) {
		if (argv[i][0] == '-' && i != 8) {
			j = j + 1;
		}

		while (argv[i][j] != '\0') {
			scan_char(argv, i, j);
			j = j + 1;
		}

		i = i + 1;
		j = 0;
	}
}

void get_points(char **argv, points_t *points)
{
	points->vx = strtod(argv[5], NULL);
	points->vy = strtod(argv[6], NULL);
	points->vz = strtod(argv[7], NULL);
	points->x = strtod(argv[2], NULL);
	points->y = strtod(argv[3], NULL);
	points->z = strtod(argv[4], NULL);
	points->p = strtod(argv[8], NULL);
}

int run_program(char **argv, points_t points)
{
	if (argv[1][0] < '1' || argv[1][0] > '3' || strlen(argv[1]) > 1) {
		printf("Invalid first argument\n");
		exit (84);
	}

	switch (argv[1][0]) {
		case '1':
			print_sphere(points);
			run_sphere(points);
			break;
		case '2':
			print_cylinder(points);
			run_cylinder(points);
			break;
		case '3':
			print_cone(points);
			run_cone(points);
			break;
	}

	return (0);
}

int main(int argc, char **argv)
{
	points_t points;

	if (argc != 9) {
		printf("Invalid number of arguments\n");

		return (84);
	} else {
		check_valid_arguments(argc, argv);
		get_points(argv, &points);
		run_program(argv, points);
	}

	return (0);
}
