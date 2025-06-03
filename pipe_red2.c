/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

char **pipe_red6(char **array, int i, int pipefd[2], int *v)
{
    char **newarray = pipe_red4(array, i);

    *v = 0;
    free_tabs(array);
    close(pipefd[1]);
    return newarray;
}

void free_struct(struct a *b, struct pipe_needs *pipe_needs)
{
    free_tabs(pipe_needs->array);
    free(b);
}

int pipe_red7(struct pipe_needs *pipe_needs, int *v, char **env, struct a *a)
{
    int status;
    struct a *b = malloc(sizeof(struct a));

    b->array = pipe_needs->array;
    b->next = a;
    dup2(pipe_needs->pipefd[0], 0);
    *v = 0;
    *v = loopfork(b, &env, 10000, *v);
    close(pipe_needs->pipefd[0]);
    dup2(pipe_needs->copystdin, 0);
    wait(&status);
    *v = WEXITSTATUS(status);
    free_struct(b, pipe_needs);
    return 1;
}
