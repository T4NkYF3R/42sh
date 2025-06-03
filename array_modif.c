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
#include <fcntl.h>
#include <string.h>

int array_len(char **array)
{
    int i = 0;

    for (i = 0; array[i]; i++);
    return i;
}

char *array_to_str(char **array)
{
    char *str = NULL;
    int i = 0;
    int j = 0;
    int size = 0;
    int x = 0;

    for (i = 0; array[i]; i++)
        for (j = 0; array[i][j]; j++)
            size++;
    str = malloc(sizeof(char) * (array_len(array) + (size * 2)));
    for (i = 0; array[i]; i++) {
        for (j = 0; array[i][j]; j++) {
            str[x] = array[i][j];
            x++;
        }
        str[x] = ' ';
        x++;
    }
    str[x] = '\0';
    return str;
}
