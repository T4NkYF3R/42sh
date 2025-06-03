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
#include <fcntl.h>
#include <string.h>

int left_red2(char *filename, int *v, char **array, struct a *b)
{
    int fd = 0;

    if (!access(filename, 0)) {
        fd = open(filename, O_RDWR);
    } else {
        free_tabs(array);
        free(b);
        write(2, filename, my_strlen(filename));
        write(2, ": No such file or directory.\n", 29);
        free(filename);
        *v = 1;
    }
    return fd;
}

int left_red3(char **array, int i, int *v, struct a *b)
{
    if (!array[i + 1]) {
        free_tabs(array);
        free(b);
        write(2, "Missing name for redirect.\n", 27);
        *v = 1;
        return 1;
    }
    return 0;
}

char **left_red4(char **array, int i, char **filename)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    *filename = my_strcat(array[i + 1], "");
    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 0; str[j] && str[j] != '<'; j++)
        newarray[0][j] = str[j];
    newarray[0][j] = '\0';
    newarray[1] = NULL;
    free(str);
    free_tabs(array);
    return newarray;
}

int free_files(int fd, struct a *b, char *filename, char **array)
{
    close(fd);
    free(b);
    free(filename);
    free_tabs(array);
    return 0;
}

int left_red(struct a *a, int i, int *v, char **env)
{
    char *filename;
    int fd = 0;
    int stdinCopy = dup(0);
    struct a *b = malloc(sizeof(struct a));

    if (left_red3(a->array2, i, v, b))
        return 1;
    a->array2 = left_red4(a->array2, i, &filename);
    fd = left_red2(filename, v, a->array2, b);
    if (*v)
        return 1;
    dup2(fd, 0);
    b->array = a->array2;
    b->next = a;
    *v = loopfork(b, &env, 10000, *v);
    dup2(stdinCopy, 0);
    free_files(fd, b, filename, a->array2);
    close(stdinCopy);
    return 1;
}
