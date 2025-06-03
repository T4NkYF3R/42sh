/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int count_spacec(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0' && (str[i] == ' ' || str[i] == ';'); i++);
    return i;
}

int calc_nb_wordc(char *str)
{
    int nb_word = 1;
    int i = 0;
    int quote = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '"' && quote == 0) {
            quote = 1;
            continue;
        }
        if (((str[i] != ';' && str[i + 1] == ';') ||
            (str[i] != ';' && str[i + 1] == '\0')) && !quote)
            nb_word++;
        if (str[i] == '"' && quote == 1)
            quote = 0;
    }
    return nb_word;
}

int calc_len_wordc(char *str)
{
    int quote = 0;
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == '"' && quote == 0) {
            quote = 1;
            continue;
        }
        if (str[i] == ';' && quote == 0) {
            str[i] = ' ';
            break;
        }
        if (str[i] == '"' && quote == 1)
            quote = 0;
    }
    return i;
}

int stwa2c(char *str, char **tab, int i, int j)
{
    int pass = 0;

    tab[i][j] = str[j];
    return pass;
}

char **stwac(char *str)
{
    int nb_word = calc_nb_wordc(str + count_spacec(str));
    int len_word = calc_len_wordc(str + count_spacec(str));
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    str += count_spacec(str);
    for (i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * (len_word + 1));
        for (j = 0; j < len_word; j++)
            str += stwa2c(str, tab, i, j);
        tab[i][j] = '\0';
        if (str[j] == ';')
            str++;
        str += len_word;
        len_word = calc_len_wordc(str);
    }
    tab[i] = NULL;
    return tab;
}
