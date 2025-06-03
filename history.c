/*
** EPITECH PROJECT, 2024
** history
** File description:
** 42sh
*/

#include "my.h"
#include <fcntl.h>

void stock_array(char *array)
{
    int fd = open(".history", O_CREAT | O_RDWR | O_APPEND, 0777);

    write(fd, array, strlen(array));
    write(fd, "\n", 1);
}

char *read_history2(void)
{
    int file = open(".history", O_RDONLY);
    int size;
    char *buff;
    struct stat s;

    if (file == -1)
        return NULL;
    stat(".history", &s);
    size = s.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    size = read(file, buff, size);
    if (size < 1)
        return NULL;
    buff[size] = '\0';
    close(file);
    return buff;
}

static void delete_history(void)
{
    open(".history", O_RDWR | O_TRUNC, 0777);
}

static int history_c(char **array, int fd)
{
    if (!strcmp(array[0], "history") && array[1] &&
        !strcmp(array[1], "-c")) {
        free_tabs(array);
        close(fd);
        delete_history();
        return 1;
    }
    return 0;
}

static int history_d_display(char **array, char **args, int p, int fd)
{
    for (int i = p; args[i]; i++)
        printf("%d   %s\n", i, args[i]);
    free_tabs(array);
    free_tabs(args);
    close(fd);
    return 1;
}

static char **init_history_d(char *buffer)
{
    char **args;

    buffer = read_history2();
    args = stwa(buffer);
    free(buffer);
    return args;
}

int history_d(char **array, int fd, int *v)
{
    int p = 0;
    char **args;
    char *buffer;

    if (lenargs(array) > 2 && !strcmp(array[0], "history") &&
    !strcmp(array[1], "-d") && array[2]) {
        p = my_getnbr(array[2]);
        args = init_history_d(buffer);
        if (lenargs(args) < p) {
            printf("Usage: history [-chrSLMT] [# number of events].\n");
            *v = 1;
            free_tabs(array);
            free_tabs(args);
            close(fd);
            return 1;
        }
        if (history_d_display(array, args, p, fd) == 1)
            return 1;
    }
    return 0;
}

int print_history2(char **array, char *buffer, int fd)
{
    char **args;

    if (!strcmp(array[0], "history") || !strcmp(array[0], "!!") && !array[1]) {
        buffer = read_history2();
        args = stwa(buffer);
        free(buffer);
        for (int i = 0; args[i]; i++)
            printf("%d   %s\n", i + 1, args[i]);
        free_tabs(args);
        free_tabs(array);
        close(fd);
        return 1;
    }
    return 0;
}

int print_history(char *str, int *v)
{
    char *buffer = NULL;
    char **array = parse_spaces(str);
    int fd = open(".history", O_CREAT | O_RDWR | O_APPEND, 0777);

    if (history_c(array, fd) == 1)
        return 1;
    if (history_d(array, fd, v) == 1)
        return 1;
    if (print_history2(array, buffer, fd) == 1)
        return 1;
    if (!strcmp(array[0], "history")) {
        printf("Usage: history [-chrSLMT] [# number of events].\n");
        free_tabs(array);
        close(fd);
        return 1;
    }
    free_tabs(array);
    close(fd);
    return 0;
}
