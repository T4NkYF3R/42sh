/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

char *replace_line(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 3));
    int x = 0;
    int i = 0;

    for (i = 0; str[i] && str[i + 1]; i++) {
        if (str[i] == '\n' || (str[i] == ' ' && str[i + 1] == ' '))
            continue;
        new[x] = str[i];
        x++;
    }
    if (!(str[i] == '\n' || (str[i] == ' ' && str[i + 1] == ' '))) {
        new[x] = str[i];
        new[x + 1] = '\0';
    } else {
        new[x] = '\0';
    }
    return new;
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

char **parse_spaces(char *cmd)
{
    char *str = replace_line(cmd);
    char **array = NULL;

    str = tabs(str);
    array = stwas(str);
    free(str);
    for (int i = 0; array[i]; i++) {
        if (!array[i][0]) {
            free(array[i + 1]);
            array[i + 1] = NULL;
            free(array[i]);
            array[i] = NULL;
        }
    }
    return array;
}

int free_tabs(char **tab)
{
    int i = 0;

    if (!tab) {
        free(tab);
        return 0;
    }
    for (i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab[i]);
    free(tab);
    return 0;
}
