/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** replace_alias.c
*/

#include "my.h"

static int lent(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == ' ' && str[i + 1] != ' ')
            return i + 1;
    return 0;
}

char *check_com(char *str, char **alias_lst)
{
    char **line;
    int len;
    char *tmp = my_strcat(str, "");

    free(str);
    for (int i = 0; alias_lst[i]; i++) {
        line = strtow(alias_lst[i]);
        len = lent(alias_lst[i]);
        if (!strcmp(tmp, line[0])) {
            free_tabs(line);
            free(tmp);
            return my_strcat((alias_lst[i]) + len, "");
        }
        free_tabs(line);
    }
    return tmp;
}

static void free_all(char *buf, char **alias_lst, char **commande)
{
    free(buf);
    free_tabs(commande);
    free_tabs(alias_lst);
}

char *set_new_com(char **commande)
{
    char *new_com;
    int len = lenargs(commande);

    for (int i = 0; commande[i]; i++)
        len += strlen(commande[i]);
    new_com = malloc(sizeof(char) * (len + 1));
    new_com[0] = '\0';
    for (int i = 0; commande[i]; i++) {
        strcat(new_com, commande[i]);
        if (commande[i + 1])
            strcat(new_com, " ");
    }
    new_com[len - 1] = '\n';
    new_com[len] = '\0';
    return new_com;
}

char *com_is_alias(char *str)
{
    char *buf = get_alias();
    char **alias_lst = stwa(buf);
    char **commande = parse_spaces(str);
    char *new_com;
    char *tmp;

    if (!strcmp(commande[0], "alias") ||
        !strcmp(commande[0], "unalias") || !buf) {
        free_all(buf, alias_lst, commande);
        return str;
    }
    free(str);
    for (int i = 0; commande[i]; i++) {
        tmp = check_com(commande[i], alias_lst);
        commande[i] = my_strcat(tmp, "");
        free(tmp);
    }
    new_com = set_new_com(commande);
    free_all(buf, alias_lst, commande);
    return new_com;
}
