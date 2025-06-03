/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main of hashtable
*/

#include "my.h"

void zero(int line, char c, int last)
{
    if (line == 1 || line == 5)
        printf(" %c%c%c ", c, c, c);
    if (line == 2 || line == 3 || line == 4)
        printf("%c   %c", c, c);
    if (last == 0)
        printf(" ");
}

void one(int line, char c, int last)
{
    if (line == 1)
        printf(" %c%c%c ", c, c, c);
    if (line == 2)
        printf("%c %c%c ", c, c, c);
    if (line == 3)
        printf("  %c%c ", c, c);
    if (line == 4)
        printf("  %c%c ", c, c);
    if (line == 5)
        printf(" %c%c%c%c", c, c, c, c);
    if (last == 0)
        printf(" ");
}

void two(int line, char c, int last)
{
    if (line == 1)
        printf(" %c%c%c ", c, c, c);
    if (line == 2)
        printf("%c   %c", c, c);
    if (line == 3)
        printf("   %c ", c);
    if (line == 4)
        printf(" %c   ", c);
    if (line == 5)
        printf("%c%c%c%c%c", c, c, c, c, c);
    if (last == 0)
        printf(" ");
}

void three(int line, char c, int last)
{
    if (line == 1)
        printf("%c%c%c%c ", c, c, c, c);
    if (line == 2)
        printf("    %c", c);
    if (line == 3)
        printf(" %c%c%c ", c, c, c);
    if (line == 4)
        printf("    %c", c);
    if (line == 5)
        printf("%c%c%c%c ", c, c, c, c);
    if (last == 0)
        printf(" ");
}

void four(int line, char c, int last)
{
    if (line == 1)
        printf("  %c%c ", c, c);
    if (line == 2)
        printf(" %c %c ", c, c);
    if (line == 3)
        printf("%c  %c ", c, c);
    if (line == 4)
        printf("%c%c%c%c%c", c, c, c, c, c);
    if (line == 5)
        printf("   %c ", c);
    if (last == 0)
        printf(" ");
}
