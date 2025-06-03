/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int get_path2(char **path, char **path3)
{
    if (!(*path))
        return 1;
    *path3 = my_strcat(*path, "");
    *path = strtok(*path3, ":");
    return 0;
}

char *get_path3(char *path, char *path2)
{
    if (path[my_strlen(path) - 1] != '/')
        path2 = my_strcat(path, "/");
    else
        path2 = my_strcat(path, "");
    return path2;
}

char *get_path(char **args, char **env)
{
    int i = 0;
    char *path = my_getenv(env, "PATH", &i);
    char *path2 = NULL;
    char *path3;

    if (get_path2(&path, &path3))
        return NULL;
    while (path) {
        path2 = get_path3(path, path2);
        path = my_strcat(path2, args[0]);
        free(path2);
        if (!access(path, 0))
            return path;
        free(path);
        path = strtok(NULL, ":");
    }
    free(path3);
    free(path);
    return NULL;
}
