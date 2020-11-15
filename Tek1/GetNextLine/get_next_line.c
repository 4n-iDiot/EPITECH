/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

char *second_stock(char *buf, char *line, char *save, int i, int compteur)
{
	char *last = NULL;
	int j = 0;
	int k = 0;
	int n = 0;
	static int r = 0;

	if (compteur != 0)
		r = 0;

	last = malloc(5000);

	if (i <= READ_SIZE && compteur == 1) {
		while (save[k] != '\0') {
			line[r] = save[k];
			r = r + 1;
			k = k + 1;
		}
	}

	while (j - 1 != i) {
		if (buf[j] == '\0') {
			line[r] = buf[j];
			r = 0;

			while (line[r] != '\0') {
				last[n] = line[r];
				n = n + 1;
				r = r + 1;
			}

			return (last);
		}

		line[r] = buf[j];
		r = r + 1;
		j = j + 1;
	}

	return (line);
}

char *stock_after_end_line(char *buf, int i, int id)
{
	char *save = NULL;
	int j = 0;

	save = malloc(5000);

	if (buf[i] != NULL && id == 0) {
		while (i < READ_SIZE) {
			save[j] = buf[i];
			j= j + 1;
			i = i + 1;
		}
	}

	return (save);
}

char *first_stock(int fd)
{
	char *save = NULL;
	char *last = NULL;
	static char *buf = NULL;
	static char line[5000];
	int readi = 0;
	int i = 0;
	static int compteur = 0;

	buf = malloc(sizeof(char) * READ_SIZE);

	while ((readi = read(fd, buf, READ_SIZE)) != 0) {
		while (i != READ_SIZE) {
			if (buf[i] == '\0' || buf[i] == '\n') {
				save = stock_after_end_line(buf, i + 1, 0);
				buf[i] = '\0';
				last = second_stock(buf, line, save, i, compteur);
				compteur = 1;

				return (last);
			}

			i = i + 1;
		}

		second_stock(buf, line, save, i, compteur);
		i = 0;
		compteur = 0;
	}
}

char *get_next_line(int fd)
{
	char *last = NULL;

	if (fd == -1)
		return (NULL);

	last = first_stock(fd);

	return (last);
}
