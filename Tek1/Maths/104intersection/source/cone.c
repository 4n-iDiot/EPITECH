/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** cone.c
*/

#include "intersection.h"

void run_cone(points_t points)
{
	double t_pow = pow(points.vx, 2) + pow(points.vy, 2) -
	(pow(points.vz, 2) * pow(tan(points.p * M_PI/180), 2));
	double t = (2 * points.vx * points.x) + (2 * points.vy * points.y) -
	(2 * points.vz * points.z * pow(tan(points.p * M_PI/180), 2));
	double c = pow(points.x, 2) + pow(points.y, 2) - pow(points.z, 2) *
	pow(tan(points.p * M_PI/180), 2);
	double delta = 0;
	double result1 = 0;
	double result2 = 0;

	check_infinite_cone(points);
	delta = pow(t, 2) - (4 * t_pow * c);

	if (delta == 0) {
		result1 = -t / (2 * t_pow);
		print_result_cone(points, result1, result2, 1);
	} else if (delta > 0) {
		result1 = (-t + sqrt(delta)) / (2 * t_pow);
		result2 = (-t - sqrt(delta)) / (2 * t_pow);
		print_result_cone(points, result1, result2, 2);
	} else {
		printf("No intersection point.\n");
	}
}

void check_infinite_cone(points_t points)
{
	if (180 / M_PI * (asin(fabs(points.vz / sqrt((points.vx * points.vx) +
	 (points.vy * points.vy) + (points.vz * points.vz))))) < points.p) {
		printf("There is an infinite number of intersection points.\n");
 		exit(0);
	}
}

void print_result_cone(points_t points, double result1, double result2, int i)
{
	if (i == 2) {
		printf("%i intersection points :\n", i);
	} else {
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

void print_cone(points_t points)
{
	printf("cone of %.f degree angle\n", points.p);
	printf("straight line going through the ");
	printf("(%.f,%.f,%.f) ", points.x, points.y, points.z);
	printf("point and of direction vector ");
	printf("(%.f,%.f,%.f)\n", points.vx, points.vy, points.vz);
}
