/*
** EPITECH PROJECT, 2024
** strtow
** File description:
** amazed
*/

#include "my.h"

int static coutntw(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
    return count;
}

int static lenw(char *str)
{
    int len = 0;

    for (; str[len] != '\0' && str[len] != ' ' && str[len] != '\n'; len++);
    return len;
}

int static spaces(char *str)
{
    int i = 0;

    for (i = 0; str[i] == ' '; i++);
    return i;
}

static char *tabs(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

char **strtow(char *buffer)
{
    char *str = tabs(buffer) + spaces(tabs(buffer));
    int i = 0;
    int j = 0;
    int len = lenw(str);
    int count = coutntw(str);
    char **map = malloc(sizeof(char *) * (count + 1));

    for (i = 0; i < count; i++) {
        map[i] = malloc(sizeof(char) * (len + 1));
        for (j = 0; j < len; j++)
            map[i][j] = str[j];
        map[i][j] = '\0';
        str += spaces(str + len) + len;
        len = lenw(str);
    }
    map[i] = NULL;
    return map;
}
