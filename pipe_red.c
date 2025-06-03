/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int pipe_red2(struct a *a, int i, int *v)
{
    if (!(a->array2)[i + 1]) {
        free_tabs(a->array2);
        write(2, "Invalid null command.\n", 22);
        *v = 1;
        return 1;
    }
    return 0;
}

char **pipe_red3(char **array, int i)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 0; str[j] && str[j] != '|'; j++)
        newarray[0][j] = str[j];
    newarray[0][j] = '\0';
    newarray[1] = NULL;
    free(str);
    return newarray;
}

char **pipe_red4(char **array, int i)
{
    char **newarray = malloc(sizeof(char *) * 2);
    char *str = array_to_str(array);
    int j = 0;
    int x = 0;

    newarray[0] = malloc(sizeof(char) * my_strlen(str) + 1);
    for (j = 0; str[j] && str[j] != '|'; j++);
    for (j = j + 1; str[j]; j++) {
        newarray[0][x] = str[j];
        x++;
    }
    newarray[0][x] = '\0';
    newarray[1] = NULL;
    free(str);
    return newarray;
}

int pipe_red5(char **array, char **env, int pipefd[2], int *v)
{
    struct a *b = malloc(sizeof(struct a));

    dup2(pipefd[1], 1);
    b->array = array;
    b->next = NULL;
    *v = loopfork(b, &env, 10000, *v);
    close(pipefd[0]);
    close(pipefd[1]);
    free(b);
    free_tabs(array);
    free_tabs(env);
    _exit(*v);
}

static void while_for_free(struct a *a, struct a *b)
{
    free_tabs(a->array2);
    while (a) {
        free_tabs(a->array);
        free(a->buffer);
        b = a;
        a = a->next;
        free(b);
    }
}

static void fill_struct_pipe(struct pipe_needs *pipe_needs,
    char **newarray, int i)
{
    pipe_needs->i = i;
    pipe_needs->array = newarray;
}

int pipe_red(struct a *a, int i, int *v, char **env)
{
    char **newarray = NULL;
    pid_t cpid;
    struct pipe_needs pipe_needs;
    struct a *b;

    pipe_needs.copystdin = dup(0);
    if (pipe_red2(a, i, v))
        return 1;
    pipe(pipe_needs.pipefd);
    cpid = fork();
    newarray = pipe_red3(a->array2, i);
    if (cpid == 0) {
        while_for_free(a, b);
        pipe_red5(newarray, env, pipe_needs.pipefd, v);
    } else {
        free_tabs(newarray);
        newarray = pipe_red6(a->array2, i, pipe_needs.pipefd, v);
        fill_struct_pipe(&pipe_needs, newarray, i);
        return pipe_red7(&pipe_needs, v, env, a);
    }
}
