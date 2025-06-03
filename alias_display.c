/*
** EPITECH PROJECT, 2023
** Project_Semestre2 (Workspace)
** File description:
** alias_display.c
*/

#include "my.h"
#include <fcntl.h>

static void print_full_alias(char **ligne)
{
    printf("%s\t", ligne[0]);
    for (int j = 1; ligne[j]; j++) {
        printf("%s", ligne[j]);
        if (ligne[j + 1])
            printf(" ");
        else
            printf("\n");
    }
}

static void freefunction(char **file, char *buf)
{
    free_tabs(file);
    free(buf);
}

void display_alias(void)
{
    char *buf = get_alias();
    char **file = stwa(buf);
    char **ligne;

    if (!buf)
        return freefunction(file, buf);
    for (int i = 0; file[i]; i++) {
        ligne = strtow(file[i]);
        if (!ligne[0]) {
            free_tabs(ligne);
            break;
        }
        print_full_alias(ligne);
        free_tabs(ligne);
    }
    freefunction(file, buf);
}

static void print_com_alias(char **ligne)
{
    if (!ligne[0])
        return;
    for (int i = 1; ligne[i]; i++) {
        printf("%s", ligne[i]);
        if (ligne[i + 1])
            printf(" ");
        else
            printf("\n");
    }
    free_tabs(ligne);
}

void display_com_alias(char *a)
{
    char *buf = get_alias();
    char **file = stwa(buf);
    char **ligne;

    if (!buf)
        return freefunction(file, buf);
    for (int i = 0; file[i]; i++) {
        ligne = strtow(file[i]);
        if (!ligne[0]) {
            break;
        }
        if (!strcmp(ligne[0], a)) {
            print_com_alias(ligne);
            break;
        } else
            free_tabs(ligne);
    }
    freefunction(file, buf);
}
