/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-42sh-taissey.normand-kondo
** File description:
** miss_quote
*/

#include "my.h"

char *cat_char(char *str, char c)
{
    int i = 0;
    char *str2 = malloc(strlen(str) + 2);

    for (i = 0; str[i] != '\0'; i++)
        str2[i] = str[i];
    str2[i] = c;
    str2[i + 1] = '\0';
    return str2;
}

char *miss_quote2(char *input, char *buffer)
{
    char *tmp;

    tmp = my_strcat(input, buffer);
    free(input);
    free(buffer);
    return tmp;
}

char *miss_quote(char ***env, int v)
{
    char c;
    int count = 0;
    char *buffer = NULL;
    char *input = malloc(1);

    input[0] = '\0';
    while (1) {
        buffer = malloc(sizeof(char) * 2);
        write(1, "> ", 2);
        if (!auto_complete(*env, &buffer, v))
            continue;
        for (int i = 0; buffer[i]; i++)
            count += buffer[i] == '"' ? 1 : 0;
        input = miss_quote2(input, buffer);
        if (count % 2 != 0)
            break;
    }
    return input;
}

char *no_quote(char *str, char ***env, int v)
{
    int quote = 0;
    char *tmp = NULL;
    char *tmp2 = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            quote++;
    }
    if (quote % 2 != 0) {
        tmp2 = miss_quote(env, v);
        tmp = my_strcat(str, tmp2);
        free(tmp2);
        free(str);
        str = tmp;
    }
    return str;
}
