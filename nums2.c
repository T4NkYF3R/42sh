/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main of hashtable
*/

#include "my.h"

void five(int line, char c, int last)
{
    if (line == 1)
        printf("%c%c%c%c%c", c, c, c, c, c);
    if (line == 2)
        printf("%c    ", c);
    if (line == 3)
        printf("%c%c%c%c ", c, c, c, c);
    if (line == 4)
        printf("    %c", c);
    if (line == 5)
        printf("%c%c%c%c ", c, c, c, c);
    if (last == 0)
        printf(" ");
}

void six(int line, char c, int last)
{
    if (line == 1)
        printf(" %c%c%c ", c, c, c);
    if (line == 2)
        printf("%c    ", c);
    if (line == 3)
        printf("%c%c%c%c ", c, c, c, c);
    if (line == 4)
        printf("%c   %c", c, c);
    if (line == 5)
        printf(" %c%c%c ", c, c, c);
    if (last == 0)
        printf(" ");
}

void seven(int line, char c, int last)
{
    if (line == 1)
        printf("%c%c%c%c%c", c, c, c, c, c);
    if (line == 2)
        printf("    %c", c);
    if (line == 3)
        printf("   %c ", c);
    if (line == 4)
        printf("  %c  ", c);
    if (line == 5)
        printf(" %c   ", c);
    if (last == 0)
        printf(" ");
}

void height(int line, char c, int last)
{
    if (line == 1)
        printf(" %c%c%c ", c, c, c);
    if (line == 2)
        printf("%c   %c", c, c);
    if (line == 3)
        printf(" %c%c%c ", c, c, c);
    if (line == 4)
        printf("%c   %c", c, c);
    if (line == 5)
        printf(" %c%c%c ", c, c, c);
    if (last == 0)
        printf(" ");
}

void nine(int line, char c, int last)
{
    if (line == 1)
        printf(" %c%c%c ", c, c, c);
    if (line == 2)
        printf("%c   %c", c, c);
    if (line == 3)
        printf(" %c%c%c%c", c, c, c, c);
    if (line == 4)
        printf("    %c", c);
    if (line == 5)
        printf(" %c%c%c ", c, c, c);
    if (last == 0)
        printf(" ");
}
