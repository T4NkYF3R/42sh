/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main of hashtable
*/

#include "my.h"

char *get_number(char **argv)
{
    for (int i = 0; argv[i]; ++i) {
        if (argv[i][0] == '-' && argv[i][1] == 'n')
            return argv[i + 1];
    }
    return NULL;
}

char *get_string(char **argv)
{
    for (int i = 0; argv[i]; ++i) {
        if (argv[i][0] == '-' && argv[i][1] == 's')
            return argv[i + 1];
    }
    return NULL;
}

char model(char *str, char c)
{
    int len;
    int index;

    if (str == NULL)
        return '0';
    len = strlen(str);
    index = (c - 48) % len;
    return str[index];
}

void print_nums(char c, int line, int last, char *str)
{
    if (c == '0')
        zero(line, model(str, c), last);
    if (c == '1')
        one(line, model(str, c), last);
    if (c == '2')
        two(line, model(str, c), last);
    if (c == '3')
        three(line, model(str, c), last);
    if (c == '4')
        four(line, model(str, c), last);
    if (c == '5')
        five(line, model(str, c), last);
    if (c == '6')
        six(line, model(str, c), last);
    if (c == '7')
        seven(line, model(str, c), last);
    if (c == '8')
        height(line, model(str, c), last);
    if (c == '9')
        nine(line, model(str, c), last);
}
