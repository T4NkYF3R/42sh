/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** backticks.c
*/

#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *rm_backticks(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) - 1));
    int a = 0;

    for (int i = 1; str[i] != '`'; i++) {
        new_str[a] = str[i];
        a++;
    }
    new_str[a] = '\0';
    free(str);
    return new_str;
}

static char *cat_tab(char **args)
{
    char *str;
    int len = 0;

    for (int i = 0; args[i]; i++)
        len += strlen(args[i]);
    str = malloc(sizeof(char) * (len + 1));
    str[0] = '\0';
    for (int i = 0; args[i]; i++)
        strcat(str, args[i]);
    return str;
}

char *exec_backticks(char *str)
{
    FILE *fp;
    char buffer[1024];
    char *res_com = NULL;
    size_t output_size = 0;

    str = rm_backticks(str);
    fp = popen(str, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        res_com = realloc(res_com, output_size + strlen(buffer) + 1);
        strcpy(res_com + output_size, buffer);
        output_size += strlen(buffer);
    }
    pclose(fp);
    free(str);
    return res_com;
}

char *check_str(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n' && str[i + 1] == '\0')
            str[i] = '\0';
    return str;
}

static char *error(char *str, int *v)
{
    free(str);
    write(2, "Unmatched '`'.\n", 15);
    *v = 1;
    str = my_strcat("", "");
    return str;
}

char *backticks(char *str, int *v)
{
    char **args;
    int yes = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '`')
            yes++;
    if (yes == 0)
        return str;
    if (yes % 2 != 0)
        return error(str, v);
    args = tab_backticks(str);
    free(str);
    for (int i = 0; args[i]; i++) {
        if (args[i][0] == '`' && args[i][strlen(args[i]) - 1] == '`')
            args[i] = exec_backticks(args[i]);
        args[i] = check_str(args[i]);
    }
    str = cat_tab(args);
    free_tabs(args);
    return str;
}
