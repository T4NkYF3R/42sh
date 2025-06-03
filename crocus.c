/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main of hashtable
*/

#include "my.h"

void parse_number(char *nums, int line, char *str)
{
    int last = 0;

    for (int i = 0; nums[i]; ++i) {
        if (i + 1 == strlen(nums)) {
            last = 1;
        }
        print_nums(nums[i], line, last, str);
    }
}

int is_num(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] >= 48 && str[i] <= 57)
            continue;
        return 0;
    }
    return 1;
}

void err_h2(int argc, char **argv, int *v)
{
    if (argc == 5 && argv[1][1] == 'n') {
        if (!is_num(argv[2]))
            *v = 1;
    }
    if (argc == 5 && argv[3][1] == 'n') {
        if (!is_num(argv[4]))
            *v = 1;
    }
}

void err_h(int argc, char **argv, int *v)
{
    if (argc != 3 && argc != 5)
        *v = 1;
    if (argc == 3) {
        if (strlen(argv[1]) != 2)
            *v = 1;
        if (argv[1][0] != '-' || argv[1][1] != 'n')
            *v = 1;
        if (!is_num(argv[2]))
            *v = 1;
    }
    if (argc == 5) {
        if (strlen(argv[1]) != 2 || strlen(argv[3]) != 2)
            *v = 1;
        if (argv[1][0] != '-' || (argv[1][1] != 'n' && argv[1][1] != 's'))
            *v = 1;
        if (argv[3][0] != '-' || (argv[3][1] != 'n' && argv[3][1] != 's'))
            *v = 1;
    }
    err_h2(argc, argv, v);
}

int crocus(char **argv, int *v)
{
    int argc = my_arrlen(argv);

    if (strcmp(argv[0], "crocus") != 0)
        return 0;
    err_h(argc, argv, v);
    if (*v == 1) {
        free_tabs(argv);
        return 1;
    }
    for (int line = 0; line < 7; ++line) {
        if (line == 0 || line == 6) {
            continue;
        }
        parse_number(get_number(argv), line, get_string(argv));
        printf("\n");
    }
    free_tabs(argv);
    return 1;
}
