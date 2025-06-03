/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int my_strlen(char *str)
{
    return str && *str ? my_strlen(str + 1) + 1 : 0;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int a = 0;
    char *r = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest && dest[i] != '\0'; i++)
        r[i] = dest[i];
    for (a = 0; src && src[a] != '\0'; a++) {
        r[i] = src[a];
        i++;
    }
    r[i] = '\0';
    return r;
}

int my_strcmp(char const *s1, char const *s2)
{
    int a;

    if (!s1 || !s2)
        return 1;
    for (a = 0; s1[a] && s2[a]; a++) {
        if (s1[a] != s2[a])
            return s1[a] - s2[a];
    }
    if (s1[a] || s2[a])
        return 1;
    return 0;
}

int my_strcmp2(char const *s1, char const *s2)
{
    int a;

    for (a = 0; s1[a] != '\0' && s1[a] != '=' &&
        s2[a] != '\0' && s1[a] != '='; a++) {
        if (s1[a] != s2[a])
            return s1[a] - s2[a];
    }
    if (s1[a] == '=' && !s2[a])
        return 0;
    return 1;
}

int is_alphanum(char a)
{
    if (a <= 'z' && a >= 'a')
        return 1;
    if (a <= 'Z' && a >= 'A')
        return 1;
    if (a >= '0' && a <= '9')
        return 1;
    if (a == '!')
        return 1;
    return 0;
}
