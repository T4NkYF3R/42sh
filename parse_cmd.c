/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int parse_cmd2(char *cmd, int *v, char **env, char **array)
{
    free_tabs(array);
    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '>') {
            write(2, "Missing name for redirect.\n", 27);
            *v = 1;
            return 1;
        }
        if (cmd[i] == '|') {
            write(2, "Invalid null command.\n", 22);
            *v = 1;
            return 1;
        }
        if (cmd[i] == '<') {
            write(2, "Missing name for redirect.\n", 27);
            *v = 1;
            return 1;
        }
    }
    return 0;
}

int find_red(char **array)
{
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "<"))
            return 1;
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "<<"))
            return 1;
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], ">"))
            return 1;
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], ">>"))
            return 1;
    return 0;
}

int parse_binary(struct a *a, int *v, char **env)
{
    char **array = parse_spaces(a->array[a->i]);
    char *cmd = a->array[a->i];

    a->array2 = array;
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "||"))
            return double_pipe(a, i, v, env);
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "&&"))
            return double_and(a, i, v, env);
    free_tabs(array);
    return 0;
}

int parse_cmd(struct a *a, int *v, char **env)
{
    char **array = parse_spaces(a->array[a->i]);
    char *cmd = a->array[a->i];

    a->array2 = parse_flags(array);
    for (int i = 1; array[i]; i++)
        if (!my_strcmp(array[i], "|"))
            return pipe_red(a, i, v, env);
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "<"))
            return left_red(a, i, v, env);
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], "<<"))
            return left_red(a, i, v, env);
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], ">"))
            return right_red(a, i, v, env);
    for (int i = 0; array[i]; i++)
        if (!my_strcmp(array[i], ">>"))
            return d_right_red(a, i, v, env);
    return parse_cmd2(cmd, v, env, array);
}
