/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static int stream_makeraw(FILE *const stream, struct termios *const state)
{
    struct termios old;
    struct termios raw;
    int fd = 0;

    setvbuf(stream, NULL, _IONBF, 0);
    fd = fileno(stream);
    tcgetattr(fd, &old);
    *state = old;
    raw = old;
    raw.c_lflag &= ~ECHO;
    raw.c_lflag &= ~ICANON;
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(fd, TCSAFLUSH, &raw);
    return 0;
}

static int stream_restore(FILE *const stream,
    const struct termios *const state)
{
    int fd;

    fflush(stream);
    fd = fileno(stream);
    tcflush(fd, TCIOFLUSH);
    tcsetattr(fd, TCSAFLUSH, state);
    return 0;
}

char **parse_input(char *buffer)
{
    char **array;

    array = stwac(buffer);
    return array;
}

int env_size(char **env)
{
    int i = 0;

    for (i = 0; env[i]; i++);
    return i;
}

int the_main_while(char *buffer, struct a *a, int v, char **newenv)
{
    size_t n = 0;

    while (getline(&buffer, &n, stdin) != -1) {
        a->buffer = buffer;
        a->array = parse_input(buffer);
        v = loopfork2(a, &newenv, v);
        free_tabs(a->array);
    }
    free(buffer);
    return v;
}

int main(int ac, char **av, char **env)
{
    int v = 0;
    struct a *a = malloc(sizeof(struct a));
    struct termios saved;
    char *buffer = NULL;
    char **newenv = copyenv(env, env_size(env));

    a->next = NULL;
    newenv = check_env(newenv);
    if (isatty(STDIN_FILENO)) {
        stream_makeraw(stdin, &saved);
        free(a);
        v = my_read(ac, &newenv, v);
        stream_restore(stdin, &saved);
    }
    if (!isatty(STDIN_FILENO)) {
        v = the_main_while(buffer, a, v, newenv);
        free(a);
    }
    free_tabs(newenv);
    return v;
}
