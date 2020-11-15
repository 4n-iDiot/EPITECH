/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** cylinder.c
*/

#include "intersection.h"

int run_cylinder(points_t points)
{
	double t_pow = pow(points.vx, 2) + pow(points.vy, 2);
	double t = (2 * points.vx * points.x) + (2 * points.vy * points.y);
	double c = pow(points.x, 2) + pow(points.y, 2) - pow(points.p, 2);
	double delta = 0;
	double result1 = 0;
	double result2 = 0;

	check_infinite(points);
	delta = pow(t, 2) - (4 * t_pow * c);

	if (delta == 0) {
		result1 = -t / (2 * t_pow);
		print_result_cylinder(points, result1, result2, 1);
	} else if (delta > 0) {
		result1 = (-t + sqrt(delta)) / (2 * t_pow);
		result2 = (-t - sqrt(delta)) / (2 * t_pow);
		print_result_cylinder(points, result1, result2, 2);
	} else
		printf("No intersection point.\n");

	return (0);
}

void check_infinite(points_t points)
{
	if (points.vx == 0 && points.vy == 0) {
		if (abs(points.x) <= points.p && abs(points.y) <= points.p) {
			printf("There is an infinite number of intersection points.\n");
			exit (0);
		}
	}
}

void print_result_cylinder(points_t points, double result1, double result2,
	int i)
{
	if (i == 2) {
		printf("%i intersection points :\n", i);
	}	else {
		printf("%i intersection point :\n", i);
	}

	printf("(%.3f, ", points.vx * result1 + points.x);
	printf("%.3f, ", points.vy * result1 + points.y);
	printf("%.3f)\n", points.vz * result1 + points.z);

	if (i == 2) {
		printf("(%.3f, ", points.vx * result2 + points.x);
		printf("%.3f, ", points.vy * result2 + points.y);
		printf("%.3f)\n", points.vz * result2 + points.z);
	}
}

void print_cylinder(points_t points)
{
	printf("cylinder of radius %.f\n", points.p);
	printf("straight line going through the ");
	printf("(%.f,%.f,%.f) ", points.x, points.y, points.z);
	printf("point and of direction vector ");
	printf("(%.f,%.f,%.f)\n", points.vx, points.vy, points.vz);
}
