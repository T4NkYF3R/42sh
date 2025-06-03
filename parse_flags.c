/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

char **move_flags(char **array, char *flag, int x)
{
    int i = 0;

    for (i = x; i > 0; i--) {
        if (isalpha(array[i][0]))
            break;
    }
    if (!i)
        return array;
    for (; x >= i; x--)
        array[x] = array[x - 1];
    array[x] = flag;
    return array;
}

char **parse_flags(char **array)
{
    if (!find_red(array))
        return array;
    for (int i = 0; (array)[i]; i++) {
        if ((array)[i][0] == '-')
            array = move_flags(array, array[i], i);
    }
    return array;
}
