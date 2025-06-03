/*
** EPITECH PROJECT, 2024
** find
** File description:
** 42ss
*/

#include "my.h"

int find_stars(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*')
            return 1;
    }
    return 0;
}

int find_interogation(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '?')
            return 1;
    }
    return 0;
}
