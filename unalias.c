/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** unalias.c
*/

#include "my.h"
#include <fcntl.h>

void for_unalias(char **file, char *a, int fd)
{
    char **ligne;

    for (int i = 0; file[i]; i++) {
        ligne = strtow(file[i]);
        if (!ligne[0])
            return;
        if (strcmp(ligne[0], a))
            write_line(fd, ligne);
        free_tabs(ligne);
    }
}

void unalias(char *a)
{
    char *buf = get_alias();
    char **file = stwa(buf);
    int fd = open(".alias", O_CREAT | O_RDWR | O_TRUNC, 0777);

    if (!buf) {
        free(buf);
        free_tabs(file);
        return;
    }
    for_unalias(file, a, fd);
    close(fd);
    free(buf);
    free_tabs(file);
}

int if_unalias(char **commande, int len, int *v)
{
    if (len == 1) {
        write(2, "unalias: Too few arguments.\n", 28);
        *v = 1;
        return 1;
    }
    if (len >= 2) {
        for (int i = 1; commande[i]; i++)
            unalias(commande[i]);
        return 1;
    }
    return 0;
}
