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

char **check_env(char **env)
{
    char buffer[1024];

    if (!env[0]) {
        env = malloc(sizeof(char *) * 4);
        env[0] = my_strcat("PATH=/usr/local/bin:/usr/bin:/usr/local/sbin", "");
        env[1] = my_strcat("PWD=", getcwd(buffer, 1024));
        env[2] = my_strcat("OLDPWD=", getcwd(buffer, 1024));
        env[3] = NULL;
    }
    return env;
}

static char **my_setenv_if_succed(char **env, char **args, int i, int *a)
{
    char *tmp = "=";

    free(env[i]);
    if (args[2])
        tmp = my_strcat("=", args[2]);
    env[i] = my_strcat(args[1], tmp);
    if (args[2])
        free(tmp);
    (*a)++;
    return env;
}

char **my_setenv2(char **env, int *j, char **args, int *a)
{
    int i = *j;

    while (env[i]) {
        if (!my_strcmp2(env[i], args[1])) {
            env = my_setenv_if_succed(env, args, i, a);
            return env;
        }
        i++;
    }
    *j = i;
    return env;
}

void put_env(char **env)
{
    int i = 0;

    if (!env || !env[0])
        return;
    while (env[i]) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
        i++;
    }
}

char **reset_env(int i, char **env)
{
    free(env[i]);
    env[i] = env[i + 1];
    while (env[i]) {
        env[i] = env[i + 1];
        i++;
    }
    return env;
}

char **copyenv(char **env, int size)
{
    char **newenv = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    int j = 0;
    FILE *fptr;

    while (env[i]) {
        newenv[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        j = 0;
        while (env[i][j]) {
            newenv[i][j] = env[i][j];
            j++;
        }
        newenv[i][j] = '\0';
        i++;
    }
    newenv[i] = NULL;
    fptr = fopen("local_environement.txt", "w");
    fclose(fptr);
    return newenv;
}
