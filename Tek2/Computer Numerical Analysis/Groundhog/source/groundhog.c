/*
** EPITECH PROJECT, 2019
** groundhog
** File description:
** groundhog.c
*/

#include "groundhog.h"

int clean_str(char *buf)
{
    bool check = false;

    for (int i = 0 ; buf[i] != '\0' ; ++i) {
        if (buf[i] == ' ') {
            check = true;
        }

        if (buf[i] != ' ' && check == true) {
            return (84);
        }
    }
    return (0);
}

char check_buffer(char *buffer)
{
    int check_minus = 0;
    int check_dot = 0;

    if (clean_str(buffer) == 84) {
        return ('f');
    }

    if (strlen(buffer) == 0) {
        return ('f');
    } else if (buffer[0] == '-') {
        check_minus = 1;
    }

    for (unsigned int i = 0 + check_minus ; i != strlen(buffer) ; i++) {
        if ((buffer[i] < '0' || buffer[i] > '9')
          && buffer[i] != '.' && buffer[i] != ' ') {
            return ('f');
        } else if (buffer[i] == '.') {
            check_dot += 1;
        }

        if (check_dot == 2) {
            return ('f');
        }
    }
    return ('t');
}

void swap_period_temp(groundhog_t *var, float buf)
{
    static int all_temp_count = 0;

    if (var->temp_count < var->days + 1) {
        var->period_temp[var->temp_count] = buf;
        var->all_temp[var->temp_count] = buf;
        var->temp_count += 1;
        all_temp_count += 1;

        return;
    }

    for (int i = 0 ; i != var->days ; i++) {
        var->period_temp[i] = var->period_temp[i + 1];
    }

    var->period_temp[var->days] = buf;
    var->all_temp =
    realloc(var->all_temp, (all_temp_count + 1) * sizeof(float));
    var->all_temp[all_temp_count] = buf;
    all_temp_count += 1;
    var->all_count = all_temp_count;
}

int groundhog(groundhog_t *var)
{
    int ret = 0;
    char *buffer = NULL;

    var->all_temp = calloc((var->days + 1), sizeof(float));
    var->period_temp = calloc((var->days + 1), sizeof(float));
    var->aberration = calloc((var->days + 1), sizeof(float));

    while (42) {
        buffer = get_next_line(0);

        if (!strcmp(buffer, "STOP")) {
            break;
        } else if (check_buffer(buffer) == 't') {
            swap_period_temp(var, strtof(buffer, NULL));
            compute_all(var);
        } else {
            ret = 84;
            break;
        }

        free(buffer);
    }

    if (var->all_count > var->days && ret == 0) {
        get_biggest_abe(var);
        manage_EOP(var);
    }

    return (ret);
}
