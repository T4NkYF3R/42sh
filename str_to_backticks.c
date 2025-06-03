/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** str_to_backticks.c
*/

#include "my.h"

static int nb_words(char *str)
{
    int len = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '`' || (str[i] != '`' && str[i + 1] == '\0'))
            len++;
    return len;
}

static int len(char *str)
{
    int len = 0;
    int n = 0;

    if (!str)
        return 0;
    if (str[0] != '`') {
        for (int i = 0; str[i] && str[i] != '`'; i++)
            len++;
        return len;
    }
    for (int i = 0; str[i] && n != 2; i++)
        if (str[i] == '`') {
            n++;
            len++;
        } else
            len++;
    return len;
}

char **tab_backticks(char *str)
{
    int nb_word = nb_words(str);
    int len_word = len(str);
    int j = 0;
    int i = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    for (i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * (len_word + 1));
        for (j = 0; j < len_word; j++) {
            tab[i][j] = *str;
            str++;
        }
        tab[i][j] = '\0';
        len_word = len(str);
    }
    tab[i] = NULL;
    return tab;
}
