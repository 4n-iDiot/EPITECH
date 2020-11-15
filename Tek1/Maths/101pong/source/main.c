/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display_angle(double zt, double vx, double vy, double vz)
{
	double angle = 0;

	if (vz >= 0 && zt >= 0) {
		if (vz == 0 && zt == 0) {
			printf("\nThe incidence angle is :\n0.00 degrees\n");
		} else {
			printf("\nThe ball won't reach the bat.\n");
		}
	} else if (vz <= 0 && zt <= 0) {
			printf("\nThe ball won't reach the bat.\n");
	} else {
		angle = 180 / M_PI * (asin(fabs(vz / sqrt((vx * vx) + (vy * vy)
							+ (vz * vz)))));
		printf("\nThe incidence angle is :\n%.2f degrees\n", angle);
	}
}

int display_coord(char **argv)
{
	double time = strtod(argv[7], NULL);
	double vx = strtod(argv[4], NULL) - strtod(argv[1], NULL);
	double vy = strtod(argv[5], NULL) - strtod(argv[2], NULL);
	double vz = strtod(argv[6], NULL) - strtod(argv[3], NULL);
	double vxt = vx * time + strtod((argv[4]), NULL);
	double vyt = vy * time + strtod((argv[5]), NULL);
	double vzt = vz * time + strtod((argv[6]), NULL);

	if (time < 0)
		return (84);

	printf("The speed vector coordinates are :\n");
	printf("(%.2f;%.2f;%.2f)", vx, vy, vz);
	printf("\nAt time t+%.f, ball coordinates will be :\n", time);
	printf("(%.2f;%.2f;%.2f)", vxt, vyt, vzt);
	display_angle(strtod(argv[6], NULL), vx, vy, vz);

	return (0);
}

int check_arguments(int argc, char **argv, int i)
{
	int j = 0;

	while (argv[i][j] != '\0') {
		if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '.'
			&& argv[i][j] != '-') {
			printf("Invalid arguments\n");

			return (84);
		}

		j = j + 1;
	}

	i = i + 1;

	if (i < argc)
		return (check_arguments(argc, argv, i));

	if (i >= argc)
		return (0);
}

int main (int argc, char **argv)
{
	int i = 1;
	int check_error = 0;

	if (argc != 8) {
		printf("Invalid number of arguments\n");
		return (84);
	}

	check_error = check_arguments(argc, argv, i);

	if (check_error == 84)
		return (84);

	display_coord(argv);

	return (0);
}
