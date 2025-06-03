/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int is_arg2(char **array)
{
    int r = 0;
    int a = 0;

    for (int i = 0; array[i]; i++) {
        if (a == 1)
            r = 1;
        a = 1;
        if (array[i][0] == '|' || array[i][0] == '>') {
            r = 0;
            a = 0;
        }
    }
    return r;
}

int is_arg(char *input)
{
    char **array = parse_input(input);
    char **array2;
    int r = 0;

    for (int i = 0; array[i] && array[i][0]; i++) {
        array2 = parse_spaces(array[i]);
        r = is_arg2(array2);
        free_tabs(array2);
    }
    free_tabs(array);
    return r;
}

char *get_word(char **input)
{
    char **array = parse_input(*input);
    char **array2;
    char *word = malloc(1);
    int j = 0;

    for (int i = 0; array[i] && array[i][0]; i++) {
        array2 = parse_spaces(array[i]);
        for (j = 0; array2[j]; j++);
        if (!array2[j]) {
            free(word);
            word = my_strcat(array2[j - 1], "");
        }
        free_tabs(array2);
    }
    free_tabs(array);
    return word;
}

static int replace_word2(char *word, char **input, struct auto_var *autol)
{
    int i = 0;
    int j = 0;

    for (i = 0; (*input)[i]; i++);
    i--;
    for (j = i; j > 0; j--) {
        if ((*input)[j] == ' ') {
            j++;
            break;
        }
    }
    return j;
}

int replace_word(char *word, char **input, struct auto_var *autol)
{
    int i = 0;
    int x = 0;
    int j = 0;

    j = replace_word2(word, input, autol);
    *input = realloc(*input, sizeof(char) * (my_strlen(*input) +
        my_strlen(word) + 2));
    for (i = j; word[x]; i++) {
        (*input)[i] = word[x];
        x++;
    }
    (*input)[i] = '\0';
    autol->i = i + 1;
    printf("%s", *input);
    return 0;
}

char *find_var(char *word, char **env)
{
    int a = 0;

    for (int i = 0; env[i]; i++) {
        if (!strncmp(word, env[i], my_strlen(word))) {
            word = my_strcat(strtok(my_strcat(env[i], ""), "="), "");
            a++;
        }
    }
    if (a > 1)
        return NULL;
    return word;
}
