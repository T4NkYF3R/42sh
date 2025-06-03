/*
** EPITECH PROJECT, 2024
** libc
** File description:
** 42sh
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            a = 1;
            nb = (nb * 10) + (str[i] - '0');
        }
        if (str[i] < 48 || str[i] > 57)
            break;
    }
    if (a == 0)
        return -1;
    return nb;
}

int my_getnbr2(char const *str)
{
    int nb = 0;
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            a = 1;
            nb = (nb * 10) + (str[i] - '0');
        }
        if ((str[i] < 48 || str[i] > 57) && i > 0) {
            break;
        }
    }
    if (a == 0)
        return -1;
    return nb;
}

int lenargs(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    return i;
}

char *my_strcat_spe(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *str3 = malloc(sizeof(char) * len + 1);

    if (!str1 || !str2) {
        free(str3);
        return str1;
    }
    for (int i = 0; str1[i] != '\0'; i++)
        str3[i] = str1[i];
    for (int i = 0; str2[i] != '\0'; i++)
        str3[i + my_strlen(str1)] = str2[i];
    str3[len] = '\0';
    return str3;
}

int strncomp(char *str1, char *str2, int n)
{
    int i = 0;

    for (i = 0; i < n && str1[i] != '\0' &&
        str1[i] != '\0' && str1[i] == str2[i]; i++);
    return str1[i] - str2[i];
}
