/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** alias_set.c
*/

#include "my.h"
#include <stdbool.h>
#include <fcntl.h>

void modif_line(char **commande, int fd)
{
    write(fd, commande[1], strlen(commande[1]));
    write(fd, "\t", 1);
    for (int i = 2; commande[i]; i++) {
        write(fd, commande[i], strlen(commande[i]));
        if (commande[i + 1])
            write(fd, " ", 1);
        else
            write(fd, "\n", 1);
    }
}

void write_line(int fd, char **line)
{
    write(fd, line[0], strlen(line[0]));
    write(fd, "\t", 1);
    for (int i = 1; line[i]; i++) {
        write(fd, line[i], strlen(line[i]));
        if (line[i + 1])
            write(fd, " ", 1);
        else
            write(fd, "\n", 1);
    }
}

bool for_set_alias(char **file, char **commande, int fd)
{
    char **ligne;
    bool modif = false;

    for (int i = 0; file && file[i]; i++) {
        ligne = strtow(file[i]);
        if (!ligne[0])
            return false;
        if (!strcmp(ligne[0], commande[1])) {
            modif_line(commande, fd);
            modif = true;
        } else
            write_line(fd, ligne);
        free_tabs(ligne);
    }
    return modif;
}

static int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void tri_tab_print(int fd, char **file)
{
    int numstr = lenargs(file);
    char **line;

    qsort(file, numstr, sizeof(char *), compare);
    for (int i = 0; file[i]; i++) {
        line = strtow(file[i]);
        write_line(fd, line);
        free_tabs(line);
    }
}

void set_alias(char **commande)
{
    char *buf = get_alias();
    char **file = stwa(buf);
    int fd = open(".alias", O_CREAT | O_RDWR | O_TRUNC, 0777);
    bool modif = for_set_alias(file, commande, fd);

    if (!modif) {
        modif_line(commande, fd);
        close(fd);
        free(buf);
        free_tabs(file);
        buf = get_alias();
        file = stwa(buf);
        fd = open(".alias", O_CREAT | O_RDWR | O_TRUNC, 0777);
        tri_tab_print(fd, file);
    }
    close(fd);
    free(buf);
    free_tabs(file);
}
