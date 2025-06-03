/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static void the_while(struct a *a)
{
    struct a *b = NULL;

    while (a) {
        if (a->i == -1)
            free_tabs(a->array2);
        free_tabs(a->array);
        free(a->buffer);
        b = a;
        a = a->next;
        free(b);
    }
}

char **my_exec(struct a *a, char **env)
{
    char **args = parse_spaces(a->array[a->i]);
    char *arg = args[0];
    int p = 0;

    the_while(a);
    if (!args[0])
        return env;
    print_env(args, env);
    if (access(args[0], 0)) {
        p = 1;
        arg = get_path(args, env);
    }
    if (arg)
        execve(arg, args, env);
    free_tabs(env);
    my_exec_error(arg, args, p);
    free_tabs(args);
    perror(arg);
    _exit(1);
}

char **my_fork(struct a *a, char **env, int *v)
{
    pid_t p = fork();
    int status = 0;

    if (p < 0) {
        perror("fork fail");
        _exit(errno);
    } else if (p == 0) {
        return my_exec(a, env);
    } else
        wait(&status);
    if (WIFEXITED(status))
        *v = WEXITSTATUS(status);
    else
        *v = my_seg(status);
    return env;
}

static void my_prompt2(FILE *file)
{
    char *buffer = NULL;
    size_t n = 0;

    if (!file)
        return;
    if (getline(&buffer, &n, file) != -1) {
        if (buffer && buffer[0]) {
            write(1, "\033[34m", 6);
            write(1, " git:(", 6);
            write(1, "\033[91m", 6);
            buffer[my_strlen(buffer) - 1] = '\0';
            write(1, buffer, my_strlen(buffer));
            write(1, "\033[34m", 6);
            write(1, ")", 1);
        }
        free(buffer);
    }
}

void my_prompt(int v)
{
    char cwd[1024];
    char *cmd = "git branch --show-current 2> /dev/null";
    FILE *file = popen(cmd, "r");

    getcwd(cwd, sizeof(cwd));
    if (v)
        write(1, "\033[91m", 6);
    else
        write(1, "\033[92m", 6);
    write(1, "➜ ", 4);
    write(1, "\033[1;36m", 7);
    write(1, cwd, my_strlen(cwd));
    my_prompt2(file);
    write(1, "\033[1;33m", 7);
    write(1, " ✗ ", 5);
    write(1, "\033[0m", 4);
    if (file)
        pclose(file);
    fflush(stdout);
}

char **my_fork_glob(char **g_tab, char **env, int *v, struct a *a)
{
    pid_t p = fork();
    int status = 0;

    if (p < 0) {
        perror("fork fail");
        _exit(errno);
    } else if (p == 0) {
        return my_exec_glob(g_tab, env, a);
    } else
        wait(&status);
    if (WIFEXITED(status))
        *v = WEXITSTATUS(status);
    else
        *v = my_seg(status);
    return env;
}

char **my_exec_glob(char **g_tab, char **env, struct a *a)
{
    char *arg = g_tab[0];
    char **args = g_tab;
    int p = 0;

    the_while(a);
    if (!args[0])
        return env;
    print_env(args, env);
    if (access(args[0], 0)) {
        p = 1;
        arg = get_path(args, env);
    }
    if (arg)
        execve(arg, args, env);
    free_tabs(env);
    my_exec_error(arg, args, p);
    perror(arg);
    _exit(1);
}
