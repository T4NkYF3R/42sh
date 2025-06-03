/*
** EPITECH PROJECT, 2024
** B-PSU-200-MAR-2-1-42sh-taissey.normand-kondo
** File description:
** globbing
*/

#include "my.h"

static char **tab_glob2(char **tab, glob_t *glob_st, char **array, int *i)
{
    for (int x = 0; x < glob_st->gl_pathc; x++) {
        tab[*i] = my_strcat(glob_st->gl_pathv[x], "");
        (*i)++;
    }
    return tab;
}

static int free_el(char *command, char *args, char **array, glob_t *glob_st)
{
    if (array[0])
        globfree(glob_st);
    free_tabs(array);
    free(command);
    free(args);
    return 0;
}

char **tab_glob(char *command, char *args)
{
    glob_t glob_st;
    char **tab = malloc(sizeof(char *) * 2);
    int size = 3;
    int i = 1;
    char **array = parse_spaces(args);

    tab[0] = my_strcat(command, "");
    for (int j = 0; array[j]; j++) {
        glob(array[j], 0, NULL, &glob_st);
        size = glob_st.gl_pathc + size;
        tab = realloc(tab, sizeof(char *) * size);
        if (!glob_st.gl_pathc) {
            tab[i] = my_strcat(array[j], "");
            ++i;
        }
        tab = tab_glob2(tab, &glob_st, array, &i);
    }
    tab[i] = NULL;
    free_el(command, args, array, &glob_st);
    return tab;
}

char *get_command(char *array)
{
    char *tmp = my_strcat(array, "");
    char *ar = tmp;
    int i = 0;
    char *str = NULL;

    for (i = 0; ar[i] == ' ' && ar[i] != '\0'; i++);
    ar += i;
    for (i = 0; ar[i] != ' ' && ar[i] != '\0'; i++);
    ar[i] = '\0';
    str = my_strcat(ar, "");
    free(tmp);
    return str;
}

char *get_args(char *array)
{
    char *tmp = my_strcat(array, "");
    char *ar = tmp;
    int i = 0;
    char *str = NULL;

    for (i = 0; ar[i] == ' ' && ar[i] != '\0'; i++);
    for (; ar[i] != ' ' && ar[i] != '\0'; i++);
    if (ar[i])
        ar += i + 1;
    else
        ar += i;
    str = my_strcat(ar, "");
    free(tmp);
    return str;
}

int is_glob(char *str)
{
    int globing = 0;
    int crochet = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '?' || str[i] == '*')
            globing++;
        if (str[i] == '[' || str[i] == ']')
            crochet++;
    }
    if ((crochet % 2 == 0 && crochet != 0) || globing > 0)
        return 1;
    return 0;
}
