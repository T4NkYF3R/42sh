/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int repeat_errors(char **args)
{
    if (my_arrlen(args) < 3) {
        free_tabs(args);
        fprintf(stderr, "repeat: Too few arguments.\n");
        return 1;
    } else if (atoi(args[1]) == 0 && args[1][0] != '0') {
        fprintf(stderr, "repeat: Badly formed number.\n");
        free_tabs(args);
        return 1;
    }
    return 0;
}

char *full_command(char **args)
{
    char *tmp = my_strcat("", "");

    for (int i = 0; i < atoi(args[1]); ++i) {
        for (int j = 2; args[j]; ++j)
            tmp = my_strcat(tmp, args[j]);
        if (i < atoi(args[1]) - 1)
            tmp = my_strcat(tmp, ";");
    }
    free_tabs(args);
    return tmp;
}

char *repeat(char *buffer)
{
    char **args = parse_spaces(buffer);

    if (strcmp(args[0], "repeat") == 0) {
        if (repeat_errors(args))
            return my_strcat("", "\n");
        return full_command(args);
    }
    free_tabs(args);
    return buffer;
}
