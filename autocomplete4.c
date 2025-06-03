/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static struct auto_var *set_auto_var(struct auto_var *autol, int v)
{
    autol->c = 0;
    autol->i = 1;
    autol->v = v;
    autol->j = 0;
    autol->max = 0;
    autol->arrow = 0;
    autol->buffer = read_history2();
    autol->args = stwa(autol->buffer);
    if (!(autol->args))
        return autol;
    for (autol->j = 0; (autol->args)[autol->j]; (autol->j)++);
    return autol;
}

static int get_input1(struct auto_var *autol, int *var,
    char **input, char **env)
{
    autol->c = getchar();
    *var = 0;
    *input = realloc(*input, sizeof(char) * (autol->i + 1000));
    if (autol->c == 3 || autol->c == 4) {
        free(*input);
        *input = my_strcat("exit\n", "");
        *var = 2;
        return 2;
    }
    if (autol->c == 127 && autol->i == 0)
        return 1;
    if (autol->c == 91) {
        autol->arrow = 1;
        return 1;
    }
    if (autol->c == 9) {
        complete(autol, input, env);
        return 1;
    }
    return 0;
}

static int input_null(struct auto_var *autol, char **input)
{
    write(1, "\n", 1);
    if (autol->i <= 1) {
        free_tabs(autol->args);
        free(autol);
        free(*input);
        return 1;
    }
    free_tabs(autol->args);
    free(autol);
    return 0;
}

int auto_complete(char **env, char **input, int v)
{
    struct auto_var *autol = malloc(sizeof(struct auto_var));
    int var = 0;

    autol = set_auto_var(autol, v);
    free(autol->buffer);
    do {
        if (get_input1(autol, &var, input, env) == 1)
            continue;
        if (var == 2) {
            free_tabs(autol->args);
            free(autol);
            return 2;
        }
        if (get_input2(autol, input) || get_input3(autol, input) ||
            get_input5(autol, input))
            continue;
    } while (autol->c != 10);
    if (input_null(autol, input))
        return 0;
    return 1;
}
