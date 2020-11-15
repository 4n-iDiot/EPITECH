/*
** EPITECH PROJECT, 2017
** groundhog
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

int set_new_buffer(char buffer[], int i, char *str, int my_strlen)
{
	int k = 0;
	int size = 0;

	if (my_strlen == 1) {
		while (str[size] != '\0')
			size = size + 1;
		return (size);
	} else {
		size = set_new_buffer("\0", 0, buffer, 1);
		for (i = i ; i < size ; i++) {
			buffer[k] = buffer[i];
			k = k + 1;
		}
		while (k < size) {
			buffer[k] = '\0';
			k = k + 1;
		}
	}
	return (0);
}

char *my_realloc(char *array, int size)
{
	char *new_array = NULL;
	int i = 0;

	new_array = malloc((set_new_buffer("\0", 0, array, 1) + size) * 2);
	if (new_array == NULL)
		return (NULL);
	while (array[i] != '\0') {
		new_array[i] = array[i];
		i = i + 1;
	}
	new_array[i] = '\0';
	return (new_array);
}

int file_line(char buffer[], char *stock_line, int *j)
{
	int i = 0;

	while (buffer[i] != '\0' && buffer[i] != '\n') {
		stock_line[*j] = buffer[i];
		i = i + 1;
		*j = *j + 1;
	}
	stock_line[*j] = '\0';
	if (buffer[i] == '\n') {
		i = i + 1;
		set_new_buffer(buffer, i, NULL, 0);
		return (1);
	}
	return (0);
}

char *read_file(char *stock_line, char buffer[], int fd, int *rd)
{
	int j = 0;

	if (set_new_buffer("\0", 0, buffer, 1) != 0) {
		if (file_line(buffer, stock_line, &j))
			return (stock_line);
	}
	while ((*rd = read(fd, buffer, READ_SIZE)) != 0) {
		buffer[*rd] = '\0';
		if (*rd == -1)
			return (NULL);
		if (file_line(buffer, stock_line, &j))
			break;
		if ((stock_line = my_realloc(stock_line, READ_SIZE)) == NULL)
			return (NULL);
		for (int i = 0 ; buffer[i] != '\0' ; i++)
			buffer[i] = '\0';
	}
	return (stock_line);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1];
	char *stock_line = NULL;
	int rd = 0;

	if (fd == -1)
		return (NULL);
	if ((stock_line = malloc(READ_SIZE * 2)) == NULL)
		return (NULL);
	stock_line[0] = '\0';
	if ((stock_line = read_file(stock_line, buffer, fd, &rd)) == NULL)
		return (NULL);
	if (rd == 0) {
		for (int i = 0 ; buffer[i] != '\0' ; i++)
			buffer[i] = '\0';
	}
	if (set_new_buffer("\0", 0, stock_line, 1) == 0
	&& set_new_buffer("\0", 0, buffer, 1) == 0 && rd == 0)
		return (NULL);
	return (stock_line);
}
