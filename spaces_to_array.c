/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int count_spaces(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (i = 0; str[i] != '\0' && str[i] == ' '; i++);
    return i;
}

static int calc_nb_words2(char *str, int nb_word, int quote, int save)
{
    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++) {
        if (str[i] == '"' && quote) {
            i++;
            quote = 0;
        }
        if (str[i] == '"' && !quote) {
            nb_word++;
            i++;
            quote = 1;
        }
        if (((str[i] != ' ' && str[i + 1] == ' ')
        || (str[i] != ' ' && str[i + 1] == '\0')) && !quote) {
            nb_word++;
            save = i;
        }
        if (str[save + count_spaces(&str[save + 1]) + 1] == '\0')
            nb_word--;
    }
    return nb_word;
}

int calc_nb_words(char *str)
{
    int nb_word = 1;
    int quote = 0;
    int save = 0;

    if (!str)
        return 0;
    nb_word = calc_nb_words2(str, nb_word, quote, save);
    return nb_word;
}

int calc_len_words(char *str)
{
    int len = 0;

    if (!str)
        return 0;
    if (str[0] == '"') {
        str++;
        for (int i = 0; str[i] != '\0' && str[i] != '"'; i++)
            len++;
    } else {
        for (int i = 0; str[i] != '\0' && str[i] != ' '; i++)
            len++;
    }
    return len;
}

int stwa2s(char *str, char **tab, int i, int j)
{
    int pass = 0;

    if (*str == '"') {
        str++;
        pass++;
    }
    tab[i][j] = str[j];
    return pass;
}

char **stwas(char *str)
{
    int nb_word = calc_nb_words(str + count_spaces(str));
    int len_word = calc_len_words(str + count_spaces(str));
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    str += count_spaces(str);
    for (i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * (len_word + 1));
        for (j = 0; j < len_word; j++)
            str += stwa2s(str, tab, i, j);
        tab[i][j] = '\0';
        if (str[j] == '"')
            str++;
        str += count_spaces(str + len_word) + len_word;
        len_word = calc_len_words(str);
    }
    tab[i] = NULL;
    return tab;
}
