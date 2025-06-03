/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static int check_cursor_left(void)
{
    struct winsize ws;
    int col;
    int row;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    if (get_cursor_position(&row, &col) != 0)
        return 0;
    if (col <= 1)
        return 1;
    return 0;
}

static int check_cursor_right(void)
{
    struct winsize ws;
    int col;
    int row;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    if (get_cursor_position(&row, &col) != 0)
        return 0;
    if (col >= ws.ws_col)
        return 1;
    return 0;
}

int get_cursor_position(int *row, int *col)
{
    struct termios original_termios;
    struct termios temporary_termios;
    char buf[32];
    int size;

    isatty(STDOUT_FILENO);
    tcgetattr(STDOUT_FILENO, &original_termios);
    temporary_termios = original_termios;
    temporary_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &temporary_termios);
    printf("\033[6n");
    fflush(stdout);
    size = read(STDOUT_FILENO, buf, sizeof(buf));
    buf[size] = '\0';
    if (sscanf(buf, "\033[%d;%dR", row, col) != 2)
        return -1;
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &original_termios);
    return 0;
}

int get_input2(struct auto_var *autol, char **input)
{
    if (autol->arrow && (autol->c == 'C' || autol->c == 'D' ||
        (autol->c == 'A' && autol->j <= 0) ||
        (autol->c == 'B' && autol->j <= 0)))
        return 1;
    if (autol->c == 'A' && autol->arrow) {
        if (autol->j <= 0)
            return 1;
        free(*input);
        while (autol->i > 1) {
            write(1, "\b \b", 3);
            (autol->i)--;
        }
        *input = up_key(&(autol->i), &(autol->j), autol->args);
        (autol->j)--;
        if (autol->i)
            (autol->i)++;
        return 1;
    }
    return 0;
}

int get_input3(struct auto_var *autol, char **input)
{
    if (autol->arrow && autol->c != 'A' && autol->c != 'B')
        autol->arrow = 0;
    if (autol->c == 'B' && autol->arrow) {
        if (autol->j >= lenargs(autol->args))
            return 1;
        free(*input);
        while (autol->i > 1) {
            write(1, "\b", 1);
            write(1, " ", 1);
            write(1, "\b", 1);
            (autol->i)--;
        }
        *input = down_key(&(autol->i), &(autol->j), autol->args);
        (autol->j)++;
        if (autol->i)
            (autol->i)++;
        return 1;
    }
    return 0;
}

int get_input4(struct auto_var *autol, char **input)
{
    if (check_cursor_left()) {
        (*input)[autol->i - 2] = '\0';
        write(1, "\033[F\033[K\033[A\f", 4);
        while (check_cursor_right())
            write(1, "\033[C", 1);
        my_prompt(autol->v);
        write(1, *input, my_strlen(*input));
        write(1, " ", 1);
    } else {
        write(1, "\b", 1);
        write(1, " ", 1);
        write(1, "\b", 1);
    }
    return 0;
}

int get_input5(struct auto_var *autol, char **input)
{
    if (autol->c == 127 && autol->i > 1) {
        get_input4(autol, input);
        (autol->i)--;
        (*input)[autol->i - 1] = '\0';
        return 1;
    } else if (isprint(autol->c)) {
        write(1, &(autol->c), 1);
        autol->i = autol->i ? autol->i : autol->i + 1;
        (*input)[autol->i - 1] = autol->c;
        (autol->i)++;
        (*input)[autol->i - 1] = '\0';
    }
    return 0;
}
