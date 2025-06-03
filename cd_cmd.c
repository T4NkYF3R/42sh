/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int set_cd(char *buffer, char ***env, int *v)
{
    char **args = parse_spaces(buffer);

    if (!my_strcmp(args[0], "cd")) {
        *env = my_cd(*env, args[1], v);
        free_tabs(args);
        return 1;
    }
    free_tabs(args);
    return 0;
}

char *my_cd2(char *arg, char **env, int i, char *dir)
{
    if (!arg || (my_strcmp(arg, "~")) == 0)
        dir = my_getenv(env, "HOME", &i);
    else if ((my_strcmp(arg, "-")) == 0)
        dir = my_getenv(env, "OLDPWD", &i);
    else
        dir = arg;
    if (!dir)
        dir = "";
    return dir;
}

char **else_error(char *arg, char *dir, int *v, char **env)
{
    my_cd_error(arg, dir);
    *v = 1;
    return env;
}

static char **my_cd3(char **env, char *dir)
{
    int i = 0;
    int j = 0;
    char *newline;

    my_getenv(env, "OLDPWD", &i);
    newline = my_getenv(env, "PWD", &j);
    if (!env[i])
        env[i + 1] = NULL;
    else
        free(env[i]);
    env[i] = my_strcat("OLDPWD=", newline);
    free(env[j]);
    env[j] = my_strcat("PWD=", dir);
    return env;
}

char **my_cd(char **env, char *arg, int *v)
{
    static char *dir;
    char buf[1024];
    char *newline;
    int i = 0;
    int j = 0;

    dir = my_cd2(arg, env, i, dir);
    my_getenv(env, "PWD", &j);
    if (!env[j])
        env[j + 1] = NULL;
    else
        free(env[j]);
    env[j] = my_strcat("PWD=", getcwd(buf, sizeof(buf)));
    if (!chdir(dir))
        dir = getcwd(buf, sizeof(buf));
    else
        return else_error(arg, dir, v, env);
    return my_cd3(env, dir);
}

void my_cd_error(char *arg, char *dir)
{
    if (access(dir, 0)) {
        write(2, arg, my_strlen(arg));
        write(2, ": No such file or directory.\n", 29);
    } else {
        write(2, arg, my_strlen(arg));
        write(2, ": Not a directory.\n", 19);
    }
}
