/*
** EPITECH PROJECT, 2024
** 42ss
** File description:
** main
*/

#include "my.h"

char *error_var(char *tmp, int *v, char *buffer, char **ar)
{
    fprintf(stderr, "%s: Undefined variable.\n", tmp);
    *v = 1;
    return buffer;
}

char *get_var2(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '$')
            return str + i + 1;
    }
    return NULL;
}

char *get_var(char **array, int *x)
{
    char *var;

    for (int i = 0; array[i]; i++) {
        var = get_var2(array[i]);
        if (var) {
            *x = i;
            return var;
        }
    }
    return NULL;
}

char *env_var2(char **ar, char *buffer, int *v, struct env_var *var)
{
    char *tmp2 = NULL;
    char *tmp = NULL;
    char *env_val = NULL;
    int a = 0;

    tmp2 = my_getenv(var->env, var->var_name, &a);
    if (!tmp2)
        return error_var(var->var_name, v, buffer, ar);
    env_val = my_strcat(tmp2, "");
    tmp = strtok(ar[var->x], "$");
    if (strcmp(var->var_name, tmp)) {
        tmp2 = my_strcat(tmp, env_val);
        free(env_val);
        env_val = tmp2;
    }
    free(ar[var->x]);
    free(buffer);
    ar[var->x] = my_strcat(env_val, "");
    free(env_val);
    return array_to_str(ar);
}

char *env_var(char *buffer, char **env, int *v)
{
    char **ar = parse_spaces(buffer);
    struct env_var *var = malloc(sizeof(struct env_var));
    int x = 0;
    char *var_name = NULL;

    var->env = env;
    for (var_name = get_var(ar, &x); var_name; var_name = get_var(ar, &x)) {
        var->x = x;
        var->var_name = var_name;
        buffer = env_var2(ar, buffer, v, var);
        if (*v)
            break;
    }
    free_tabs(ar);
    free(var);
    return buffer;
}
