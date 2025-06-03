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

char **test_args(char **args, int *a, char **env)
{
    int z = 0;

    env = setenv3(env, a, args);
    if (*a)
        return env;
    while (args[1][z]) {
        if (!is_alphanum(args[1][z])) {
            (*a)++;
            write(2, "setenv: Variable name must contain alphanumeric", 47);
            write(2, " characters.\n", 13);
            return env;
        }
        z++;
    }
    return env;
}

int my_seg(int status)
{
    if (WTERMSIG(status) == SIGSEGV && WCOREDUMP(status))
        write(2, "Segmentation fault (core dumped)\n", 33);
    if (WTERMSIG(status) == SIGSEGV && !WCOREDUMP(status))
        write(2, "Segmentation fault\n", 19);
    if (WTERMSIG(status) == SIGFPE && WCOREDUMP(status))
        write(2, "Floating exception (core dumped)\n", 33);
    if (WTERMSIG(status) == SIGFPE && !WCOREDUMP(status))
        write(2, "Floating exception\n", 19);
    if (status == 134) {
        write(2, "Abort (core dumped)\n", 21);
        return status;
    }
    return WTERMSIG(status) + 128;
}

int exit_free(int v, char **args)
{
    free_tabs(args);
    _exit(1);
}

void my_exec_error(char *arg, char **args, int p)
{
    struct stat s;

    if (p)
        free(arg);
    if (access(args[0], 0)) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        exit_free(1, args);
    }
    if (errno == 8) {
        write(2, arg, my_strlen(arg));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
        exit_free(1, args);
    }
    stat(args[0], &s);
    if (S_ISDIR(s.st_mode)) {
        write(2, arg, my_strlen(arg));
        write(2, ": Permission denied.\n", 21);
        exit_free(1, args);
    }
}
