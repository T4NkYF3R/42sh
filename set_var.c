/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

char **get_local_content_array(char *filename)
{
    struct stat s;
    int fd = open(filename, O_RDONLY);
    char *map;
    int err;
    char **tabs;

    stat(filename, &s);
    map = malloc(sizeof(char) * s.st_size + 1);
    err = read(fd, map, s.st_size);
    map[err] = '\0';
    tabs = stwa(map);
    free(map);
    return tabs;
}

char *get_local_value(char *line, char *buffer)
{
    int i = 1;

    for (; line[i - 1] != '\t'; ++i);
    if (line[i] == '\0') {
        return my_strcat("", "\n");
    } else
        buffer = cat_char("", line[i]);
    ++i;
    for (; line[i]; ++i)
        buffer = cat_char(buffer, line[i]);
    return buffer;
}

char *my_getlocalenv(char *var_name, char *buffer)
{
    char **local = get_local_content_array("local_environement.txt");

    if (local == NULL) {
        free_tabs(local);
        return buffer;
    }
    for (int i = 0; local[i]; ++i)
        if (!strncmp(var_name, local[i], strlen(var_name) - 1) &&
            local[i][strlen(var_name)] == '\t') {
                buffer = get_local_value(local[i], buffer);
                break;
        }
    free_tabs(local);
    return buffer;
}

char *local_var(char *buffer, char **env, int *v)
{
    char **ar = parse_spaces(buffer);
    struct env_var *var = malloc(sizeof(struct env_var));
    int x = 0;
    char *var_name = NULL;

    var->env = env;
    var_name = get_var(ar, &x);
    var->x = x;
    if (!var_name) {
        free_tabs(ar);
        free(var);
        free(var_name);
        return buffer;
    }
    free_tabs(ar);
    free(var);
    return my_getlocalenv(var_name, buffer);
}
