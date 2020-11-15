/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** calcul.c
*/

#include "architect.h"

void compute_translation(float i, float j, matrixA *matrix)
{
	float X = matrix->x + i;
	float Y = matrix->y + j;

	printf("Translation by the vector (%.f, %.f)\n", i, j);
	matrix->matrixbase[0][2] = i;
	matrix->matrixbase[1][2] = j;
	display_matrix(matrix);
	printf("(%.f,%.f) => (%.2f,%.2f)\n", matrix->x, matrix->y, X, Y);
}

void compute_homothety(float m, float n, matrixA *matrix)
{
	double X = matrix->x * m;
	double Y = matrix->y * n;

	printf("Homothety by the ratios %.f and %.f\n", m, n);
	matrix->matrixbase[0][0] = m;
	matrix->matrixbase[1][1] = n;
	display_matrix(matrix);
	printf("(%.f,%.f) => (%.2f,%.2f)\n", matrix->x, matrix->y, X, Y);
}

void compute_rotation(float alpha, matrixA *matrix)
{
	float A11 = cos(M_PI / 180 * alpha);
	float A12 = sin(M_PI / 180 * alpha) * (-1);
	float A21 = sin(M_PI / 180 * alpha);
	float A22 = cos(M_PI / 180 * alpha);
	float X = matrix->x * A11 + matrix->y * A12;
	float Y = matrix->x * A21 + matrix->y * A22;

	if (alpha > 360)
		alpha = fmod(alpha, 360);

	printf("Rotation at a %.f degree angle\n", alpha);
	matrix->matrixbase[0][0] = A11;
	matrix->matrixbase[0][1] = A12;
	matrix->matrixbase[1][0] = A21;
	matrix->matrixbase[1][1] = A22;
	display_matrix(matrix);
	printf("(%.f,%.f) => (%.2f,%.2f)\n", matrix->x, matrix->y, X, Y);
}

void compute_symetry(float alpha, matrixA *matrix)
{
	float A11 = sin(M_PI / 180 * alpha);
	float A12 = cos(M_PI / 180 * alpha);
	float A21 = cos(M_PI / 180 * alpha);
	float A22 = sin(M_PI / 180 * alpha) * (-1);
	float X = matrix->x * A11 + matrix->y * A12;
	float Y = matrix->x * A21 + matrix->y * A22;

	printf("Symmetry about an axis inclined with an angle of");
	printf("%.f degrees\n", alpha);

	if (fmod(alpha, 270) == 0) {
		A12 = A12 * (-1);
		A21 = A21 * (-1);
	}

	if (alpha > 360)
		alpha = fmod(alpha, 360);

	matrix->matrixbase[0][0] = A11;
	matrix->matrixbase[0][1] = A12;
	matrix->matrixbase[1][0] = A21;
	matrix->matrixbase[1][1] = A22;
	display_matrix(matrix);
	printf("(%.f,%.f) => (%.2f,%.2f)\n", matrix->x, matrix->y, X, Y);
}
