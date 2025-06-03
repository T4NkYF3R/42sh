/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

char **right_red2(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 0; str[j] && str[j] != '>'; j++)
        newarray[0][j] = str[j];
    newarray[0][j] = '\0';
    newarray[1] = NULL;
    free(str);
    free_tabs(array);
    return newarray;
}

static int error_right_red(struct a *a, int i, struct a *b, int *v)
{
    if (!(a->array2)[i + 1]) {
        free(b);
        free_tabs(a->array2);
        write(2, "Missing name for redirect.\n", 27);
        *v = 1;
        return 1;
    }
    return 0;
}

int right_red(struct a *a, int i, int *v, char **env)
{
    char *filename;
    int fd;
    int stdoutCopy = dup(1);
    struct a *b = malloc(sizeof(struct a));

    if (error_right_red(a, i, b, v) == 1)
        return 1;
    filename = my_strcat((a->array2)[i + 1], "");
    a->array2 = right_red2(a->array2, i, v, env);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXO | S_IRWXU);
    dup2(fd, 1);
    b->array = a->array2;
    b->next = a;
    *v = loopfork(b, &env, 10000, *v);
    dup2(stdoutCopy, 1);
    close(fd);
    free(b);
    free(filename);
    free_tabs(a->array2);
    return 1;
}

char **d_right_red2(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 0; str[j] && str[j] != '>'; j++)
        newarray[0][j] = str[j];
    newarray[0][j] = '\0';
    newarray[1] = NULL;
    free(str);
    free_tabs(array);
    return newarray;
}

char *d_right_red3(char **array, int i, int *fd, char *filename)
{
    struct stat s;
    int size;
    char *file = NULL;

    if (!access(filename, 0)) {
        stat(filename, &s);
        file = malloc(s.st_size + 1);
        *fd = open(filename, O_RDWR);
        size = read(*fd, file, s.st_size);
        file[size] = '\0';
    } else
        *fd = open(filename, O_RDWR | O_CREAT, S_IRWXO | S_IRWXU);
    return file;
}

static void free_struct(struct a *b, char *file, struct a *a)
{
    free(b);
    free(file);
    free_tabs(a->array2);
}

int d_right_red(struct a *a, int i, int *v, char **env)
{
    char *filename;
    char *file;
    int fd;
    int stdoutCopy = dup(1);
    struct a *b = malloc(sizeof(struct a));

    if (error_right_red(a, i, b, v))
        return 1;
    filename = my_strcat((a->array2)[i + 1], "");
    a->array2 = d_right_red2(a->array2, i, v, env);
    file = d_right_red3(a->array2, i, &fd, filename);
    dup2(fd, 1);
    b->array = a->array2;
    b->next = a;
    *v = loopfork(b, &env, 10000, *v);
    dup2(stdoutCopy, 1);
    free_struct(b, file, a);
    free(filename);
    close(fd);
    return 1;
}
