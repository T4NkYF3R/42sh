/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** history_!.c
*/

#include "my.h"

char *error_point(int p)
{
    printf("%d: Event not found\n", p);
    return NULL;
}

char **set_args(char **args, int *p)
{
    int len = 0;

    (*p) -= 1;
    len = strlen(args[*p]);
    args[*p] = realloc(args[*p], sizeof(char) * len + 2);
    args[*p][len] = '\n';
    args[*p][len + 1] = '\0';
    return args;
}

char *do_history_point(char *str)
{
    char *buffer;
    char **args;
    char *save = NULL;
    int p = 0;

    buffer = read_history2();
    args = stwa(buffer);
    free(buffer);
    p = my_getnbr2(str);
    if (p > lenargs(args) || p <= 0) {
        free_tabs(args);
        return error_point(p);
    }
    args = set_args(args, &p);
    save = my_strcat(args[p], "");
    free_tabs(args);
    free(str);
    return save;
}

char *history_point(char *str)
{
    if (str[0] == '!' && str[1] != '!')
        return do_history_point(str);
    else
        return str;
}
