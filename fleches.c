/*
** EPITECH PROJECT, 2024
** fleches
** File description:
** ss
*/

#include "my.h"
#include <ncurses.h>
#include <stddef.h>
#include <fcntl.h>

char *up_key(int *i, int *j, char **args)
{
    char *input = NULL;

    if (*j > 0) {
        printf("%s", args[*j - 1]);
        *i = my_strlen(args[*j - 1]);
        input = my_strcat("", args[*j - 1]);
    } else {
        *j += 1;
    }
    return input;
}

char *down_key(int *i, int *j, char **args)
{
    char *input = NULL;
    int k = lenargs(args);

    if (*j < k) {
        printf("%s", args[*j]);
        *i = my_strlen(args[*j]);
        input = my_strcat(args[*j], "");
    } else {
        *j -= 1;
    }
    return input;
}
