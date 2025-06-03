/*
** EPITECH PROJECT, 2023
** amongus ????
** File description:
** do set just like tcsh
*/

#include "my.h"

bool check_for_one_arr(char **args, int word, FILE *fptr)
{
    char first_var[4096] = {0};
    char var_value[4096] = {0};
    int value = 0;
    int res = false;

    for (int i = 0; args[word][i]; ++i) {
        if (args[word][i] == '=') {
            res = true;
            continue;
        }
        if (res) {
            var_value[value] = args[word][i];
            ++value;
        } else {
            first_var[i] = args[word][i];
            first_var[i + 1] = '\0';
        }
    }
    check_for_one_arr2(res, fptr, first_var, var_value);
    return res;
}

void add_local_value(char **args, FILE *fptr)
{
    for (int i = 1; args[i]; ++i) {
        if ((args[i][0] == '=' && strlen(args[i]) == 1)
        || check_for_one_arr(args, i, fptr))
            continue;
        fprintf(fptr, "%s\t", args[i]);
        if (i + 1 == my_arrlen(args)) {
            fprintf(fptr, "\n");
            break;
        }
        if (args[i + 1][0] == '=' && strlen(args[i + 1]) == 1
        && i + 2 != my_arrlen(args)) {
            i += 2;
            fprintf(fptr, "%s\n", args[i]);
            continue;
        }
        fprintf(fptr, "\n");
    }
}

int error_message_return_1(char *str, int *v)
{
    fprintf(stderr, "%s\n", str);
    *v = 1;
    return 1;
}

int check_errors(char **args, int *v)
{
    int i = 1;
    int j = 0;
    char err1[] = "set: Variable name must begin with a letter.";
    char err2[] = "set: Variable name must contain alphanumeric characters.";

    if (isalpha(args[1][0]) == 0)
        return error_message_return_1(err1, v);
    for (; args[i]; ++j) {
        if (j == strlen(args[i])) {
            j = -1;
            ++i;
            continue;
        }
        if (!isalnum(args[i][j]) && args[i][j] != '=')
            return error_message_return_1(err2, v);
    }
    return 0;
}

int my_set(char *buffer, char ***env, int *v)
{
    char **args = parse_spaces(buffer);
    FILE *fptr;

    if (my_strcmp(buffer, "set") == 0) {
        display_file_content("local_environement.txt");
        free_tabs(args);
        return 1;
    }
    if (my_strcmp(args[0], "set") == 0) {
        if (check_errors(args, v))
            return 1;
        fptr = fopen("local_environement.txt", "a");
        add_local_value(args, fptr);
        fclose(fptr);
        free_tabs(args);
        return 1;
    }
    free_tabs(args);
    return 0;
}
