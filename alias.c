/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** alias.c
*/

#include "my.h"
#include <fcntl.h>

char *get_alias(void)
{
    int fd = open(".alias", O_RDWR | O_CREAT, 0777);
    struct stat s;
    char *buf;

    if (fd == -1)
        return NULL;
    stat(".alias", &s);
    if (s.st_size < 1)
        return NULL;
    buf = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buf, s.st_size);
    buf[s.st_size] = '\0';
    close(fd);
    return buf;
}

int if_alias(char **commande, int len)
{
    if (len == 1) {
        display_alias();
        return 1;
    }
    if (len == 2) {
        display_com_alias(commande[1]);
        return 1;
    }
    set_alias(commande);
    return 1;
}

int alias(char *str, int *v)
{
    char **commande = parse_spaces(str);
    int len = lenargs(commande);
    int i = 0;

    if (strcmp(commande[0], "alias") && strcmp(commande[0], "unalias")) {
        free_tabs(commande);
        return 0;
    }
    if (!strcmp(commande[0], "alias"))
        i = if_alias(commande, len);
    else if (!strcmp(commande[0], "unalias"))
        i = if_unalias(commande, len, v);
    free_tabs(commande);
    return i;
}
