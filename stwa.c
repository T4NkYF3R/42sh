/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int fnb_word(char *str)
{
    int len = 1;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++) {
        if (str[i] == '\n' || (str[i] != '\n' && str[i + 1] == '\0'))
            len++;
    }
    return len;
}

int flen_word(char *str)
{
    int len = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] && str[i] != '\n'; i++)
        len++;
    return len;
}

char **rm_tab(char **tab)
{
    free(tab);
    return NULL;
}

char **stwa(char *str)
{
    int nb_word = fnb_word(str);
    int len_word = flen_word(str);
    int j = 0;
    int i = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    if (!str || !str[0])
        return rm_tab(tab);
    for (i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * (len_word + 1));
        for (j = 0; j < len_word; j++) {
            tab[i][j] = *str;
            str++;
        }
        tab[i][j] = '\0';
        str++;
        len_word = flen_word(str);
    }
    tab[i] = NULL;
    return tab;
}
