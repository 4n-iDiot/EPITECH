/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** intersection.h
*/

#ifndef INTERSECTION_H_
	#define INTERSECTION_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct coor {
	double vx;
	double vy;
	double vz;
	double x;
	double y;
	double z;
	double p;
} points_t;

/* SPHERE.C */
int run_sphere(points_t points);
void print_result_sphere(points_t points, double result1, double result2,
	int i);
void print_sphere(points_t points);

/* CYLINDER.C */
int run_cylinder(points_t points);
void check_infinite(points_t points);
void print_result_cylinder(points_t points, double result1, double result2,
	int i);
void print_cylinder(points_t points);

/* CONE.C */
void run_cone(points_t points);
void check_infinite_cone(points_t points);
void print_result_cone(points_t points, double result1, double result2, int i);
void print_cone(points_t points);

#endif /* INTERSECTION_H_ */
