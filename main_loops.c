/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

static int is_void(char *str)
{
    if (!str[0])
        return 1;
    for (int i = 0; str[i]; i++) {
        if (is_alphanum(str[i])) {
            return 0;
        }
    }
    return 1;
}

static int free_bs(char *buffer, struct a *a)
{
    free(a);
    free(buffer);
    return 0;
}

int builtins(char *array, char ***env, int *v)
{
    if (my_env(array, env, v))
        return 1;
    if (set_cd(array, env, v))
        return 1;
    if (print_history(array, v))
        return 1;
    if (alias(array, v))
        return 1;
    if (my_set(array, env, v))
        return 1;
    if (crocus(parse_spaces(array), v))
        return 1;
    return 0;
}

static int loopfork2_bis(struct a *a, char ***env, int *v, char **g_tab)
{
    (a->array)[a->i] = com_is_alias((a->array)[a->i]);
    (a->array)[a->i] = backticks((a->array)[a->i], v);
    if ((a->array)[a->i][0] != '\0') {
        if (parse_binary(a, v, *env))
            return g_tab ? 0 : free_tabs(g_tab);
        if (parse_cmd(a, v, *env))
            return g_tab ? 0 : free_tabs(g_tab);
        if (g_tab)
            *env = my_fork_glob(g_tab, *env, v, a);
        if (!builtins((a->array)[a->i], env, v) && !g_tab)
            *env = my_fork(a, *env, v);
    }
    if (g_tab && g_tab[0])
        free_tabs(g_tab);
    return 0;
}

static char *loopfork3(struct a *a, char ***env, int *v, int *i)
{
    *v = 0;
    a->i = *i;
    (a->array)[*i] = local_var((a->array[*i]), *env, v);
    (a->array)[*i] = env_var((a->array[*i]), *env, v);
    (a->array)[*i] = history_point((a->array)[*i]);
    return (a->array)[*i];
}

int loopfork2(struct a *a, char ***env, int v)
{
    char **g_tab = NULL;

    for (int i = 0; (a->array)[i] && (a->array)[i][0]; i++) {
        if (is_void((a->array)[i]))
            continue;
        (a->array)[i] = loopfork3(a, env, &v, &i);
        if ((a->array)[i] == NULL || v) {
            v = 1;
            continue;
        }
        a->array[i] = no_quote(a->array[i], env, v);
        if (is_glob(a->array[i]))
            g_tab = tab_glob(get_command(a->array[i]), get_args(a->array[i]));
        loopfork2_bis(a, env, &v, g_tab);
        g_tab = NULL;
    }
    return v;
}

int loopfork(struct a *a, char ***env, int size, int v)
{
    a->buffer = malloc(sizeof(char) * size);
    for (int i = 0; (a->array)[i]; i++) {
        v = 0;
        a->i = i;
        if ((a->array)[i][0] == '\n')
            continue;
        if (parse_cmd(a, &v, *env))
            continue;
        if (parse_binary(a, &v, *env))
            continue;
        if (!builtins((a->array)[i], env, &v))
            *env = my_fork(a, *env, &v);
    }
    free(a->buffer);
    return v;
}

static int check_array(struct a *a, char ***env, int *v, char *buffer)
{
    if (!a->array)
        return 1;
    *v = loopfork2(a, env, *v);
    free_tabs(a->array);
    free(buffer);
    return 0;
}

int my_read(int ac, char ***env, int v)
{
    char *buffer;
    struct a *a = malloc(sizeof(struct a));

    a->next = NULL;
    while (1) {
        buffer = malloc(sizeof(char) * 2);
        my_prompt(v);
        if (!auto_complete(*env, &buffer, v))
            continue;
        if (check_parenthese(buffer))
            continue;
        buffer = repeat(buffer);
        if (!my_strcmp(buffer, "exit\n") || !my_strcmp(buffer, "exit")) {
            free_bs(buffer, a);
            return v;
        }
        a->buffer = buffer;
        a->array = parse_input(buffer);
        check_array(a, env, &v, buffer);
    }
}
