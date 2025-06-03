/*
** EPITECH PROJECT, 2024
** parentheses
** File description:
** 42ss
*/

#include "my.h"

char *the_mstr(char *main_str)
{
    for (int j = 0; main_str[j]; j++) {
        if (main_str[j] == '(' || main_str[j] == ')')
            main_str[j] = ' ';
        if (main_str[j] == '\n') {
            main_str[j] = ' ';
        }
    }
    return main_str;
}

char *parenthese2(char *main_str, char *stock_first_str, int j)
{
    char *new = malloc(sizeof(char) * (strlen(main_str) +
        strlen(stock_first_str) + 4));

    new = strcpy(new, main_str);
    if (j > 0)
        new = strcat(new, "; ");
    if (j > 0)
        new = strcat(new, "\n");
    new = strcat(new, "");
    return new;
}

char *parenthese(char *str)
{
    char *stock_str;
    char *tmp;
    char *main_str;
    int i = 0;
    int j = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '(')
            break;
    main_str = malloc(sizeof(char) * (strlen(&str[i]) + 1));
    strcpy(main_str, &str[i]);
    main_str[strlen(&str[i])] = '\0';
    stock_str = malloc(sizeof(char) * strlen(main_str));
    for (j = 0; main_str[j] != ')'; j++)
        stock_str[j] = main_str[j];
    stock_str = realloc(stock_str, sizeof(char) * (j + 1));
    stock_str[j] = '\0';
    stock_str = the_mstr(stock_str);
    free(main_str);
    return stock_str;
}

int find_par(char *str)
{
    int par1 = 0;
    int par2 = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(')
            par1++;
        if (str[i] == ')' && par1)
            par2++;
    }
    if (par1 && par2 && par2 == par1)
        return 1;
    return 0;
}

int check_parenthese(char *str)
{
    int count = 0;
    char *cmd;
    char *word;
    int i = 0;

    if (str && str[0])
        stock_array(str);
    if (find_par(str)) {
        word = parenthese(str);
        cmd = malloc(sizeof(char) * strlen(str) + 18);
        strcpy(cmd, "echo \"");
        cmd = strcat(cmd, word);
        cmd = strcat(cmd, "\" | ./42sh");
        free(word);
        free(str);
        system(cmd);
        free(cmd);
        return 1;
    }
    return 0;
}
