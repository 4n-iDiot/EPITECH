/*
** EPITECH PROJECT, 2017
** groundhog
** File description:
** get_next_line.h
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#	define READ_SIZE (300)
#endif /* !READ_SIZE */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(char const *str);
char *get_next_line(int fd);

#endif /* GET_NEXT_LINE_H_ */
