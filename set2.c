/*
** EPITECH PROJECT, 2023
** amongus ????
** File description:
** do set just like tcsh
*/

#include "my.h"

void display_file_content(char *filename)
{
    struct stat s;
    int fd = open(filename, O_RDONLY);
    char *map;
    int err;

    stat(filename, &s);
    if (s.st_size == 0)
        return;
    map = malloc(sizeof(char) * s.st_size);
    err = read(fd, map, s.st_size);
    map[err] = '\0';
    printf("%s", map);
    free(map);
}

int my_arrlen(char **array)
{
    int i = 0;

    for (; array[i]; ++i);
    return i;
}

void check_for_one_arr2(int res, FILE *fptr, char *first_var, char *var_value)
{
    if (res)
        fprintf(fptr, "%s\t%s\n", first_var, var_value);
}
