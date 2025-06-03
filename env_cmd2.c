/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

char *my_getenv(char **env, char *str, int *i)
{
    while (env[*i] && my_strcmp2(env[*i], str))
        (*i)++;
    if (!env[*i])
        return NULL;
    return env[*i] + my_strlen(str) + 1;
}

static int if_error(int *a, int *v)
{
    if (*a) {
        *v = 1;
        return 1;
    }
    return 0;
}

char **my_setenv(char **env, char **args, int *v)
{
    int i = 0;
    int a = 0;
    char *tmp = "=";

    env = test_args(args, &a, env);
    env = my_setenv2(env, &i, args, &a);
    if (if_error(&a, v) == 1)
        return env;
    env = realloc(env, sizeof(char *) * (env_size(env) + 2));
    if (!errno || errno == 25) {
        if (args[2])
            tmp = my_strcat("=", args[2]);
        env[i] = my_strcat(args[1], tmp);
        if (args[2])
            free(tmp);
        env[i + 1] = NULL;
        return env;
    }
    return env;
}

char **my_unsetenv(char **env, char **args, char *arg)
{
    int i = 0;

    if (!arg)
        return env;
    while (env[i]) {
        if (!my_strcmp2(env[i], arg)) {
            env = reset_env(i, env);
            return env;
        }
        i++;
    }
    return env;
}

void print_env(char **args, char **env)
{
    if (!my_strcmp(args[0], "env")) {
        put_env(env);
        free_tabs(args);
        free_tabs(env);
        _exit(0);
    }
}

char **setenv3(char **env, int *a, char **args)
{
    if (args[1][0] >= 'a' && args[1][0] <= 'z')
        return env;
    if (args[1][0] >= 'A' && args[1][0] <= 'Z')
        return env;
    write(2, "setenv: Variable name must begin with a letter.\n", 48);
    (*a)++;
    return env;
}
