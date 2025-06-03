/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static char **double_pipe2(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 1; str[j] && str[j - 1] != '|' && str[j] != '|'; j++)
        newarray[0][j - 1] = str[j - 1];
    newarray[0][j - 1] = '\0';
    newarray[1] = NULL;
    free(str);
    return newarray;
}

static char **double_pipe3(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;
    int x = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 1; str[j] && str[j - 1] != '|' && str[j] != '|'; j++);
    for (j += 2; str[j]; j++) {
        newarray[0][x] = str[j];
        x++;
    }
    newarray[0][x] = '\0';
    newarray[1] = NULL;
    free(str);
    free_tabs(array);
    return newarray;
}

static int error_double_pipe(struct a *a, struct a *b, int i, int *v)
{
    if (!(a->array2)[i + 1] || !i) {
        write(2, "Invalid null command.\n", 22);
        free_tabs(a->array2);
        free(b);
        *v = 1;
        return 1;
    }
    return 0;
}

int double_pipe(struct a *a, int i, int *v, char **env)
{
    struct a *b = malloc(sizeof(struct a));

    if (error_double_pipe(a, b, i, v) == 1)
        return 1;
    *v = 0;
    b->array = double_pipe2(a->array2, i, v, env);
    b->next = a;
    *v = loopfork(b, &env, 10000, *v);
    free_tabs(b->array);
    b->array = double_pipe3(a->array2, i, v, env);
    if (*v)
        *v = loopfork(b, &env, 10000, *v);
    free_tabs(b->array);
    free(b);
    return 1;
}

static char **double_and2(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 1; str[j] && str[j - 1] != '&' && str[j] != '&'; j++)
        newarray[0][j - 1] = str[j - 1];
    newarray[0][j - 1] = '\0';
    newarray[1] = NULL;
    free(str);
    return newarray;
}

static char **double_and3(char **array, int i, int *v, char **env)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;
    int x = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 1; str[j] && str[j - 1] != '&' && str[j] != '&'; j++);
    for (j += 2; str[j]; j++) {
        newarray[0][x] = str[j];
        x++;
    }
    newarray[0][x] = '\0';
    newarray[1] = NULL;
    free(str);
    return newarray;
}

int double_and(struct a *a, int i, int *v, char **env)
{
    struct a *b = malloc(sizeof(struct a));

    if (error_double_pipe(a, b, i, v) == 1)
        return 1;
    *v = 0;
    b->array = double_and2(a->array2, i, v, env);
    b->next = a;
    a->i = -1;
    *v = loopfork(b, &env, 10000, *v);
    free_tabs(b->array);
    b->array = double_and3(a->array2, i, v, env);
    if (!(*v))
        *v = loopfork(b, &env, 10000, *v);
    free_tabs(b->array);
    free_tabs(a->array2);
    free(b);
    return 1;
}
