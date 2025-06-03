/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int error_env2(char ***args, int *v)
{
    if (!(*args)[2]) {
        (*args)[2] = NULL;
        return 0;
    }
    if ((*args)[3]) {
        *v = 1;
        write(2, "setenv: Too many arguments.\n", 29);
    }
    return 0;
}

int error_env1(char **args, int *v)
{
    if (!args[1]) {
        *v = 1;
        write(2, "unsetenv: Too few arguments.\n", 29);
    }
    return 0;
}

int do_setenv(char ***env, char **args, int *v)
{
    if (!my_strcmp(args[0], "setenv")) {
        if (!args[1]) {
            put_env(*env);
            free_tabs(args);
            return 1;
        }
        error_env2(&args, v);
        *env = my_setenv(*env, args, v);
        free_tabs(args);
        return 1;
    }
    return 0;
}

int my_env(char *buffer, char ***env, int *v)
{
    char **args = parse_spaces(buffer);

    if (do_setenv(env, args, v))
        return 1;
    if (!my_strcmp(args[0], "unsetenv")) {
        error_env1(args, v);
        for (int i = 1; args[i]; i++)
            *env = my_unsetenv(*env, args, args[i]);
        free_tabs(args);
        return 1;
    }
    free_tabs(args);
    return 0;
}
