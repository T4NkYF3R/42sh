/*
** EPITECH PROJECT, 2023
** amogud
** File description:
** zzz
*/

#include "my.h"

int get_variables(struct auto_var *autol, char **input, char **env)
{
    char *word = get_word(input);
    int size = my_strlen(*input);

    word++;
    word = find_var(word, env);
    if (!word)
        return 0;
    for (int i = 0; i < size; i++) {
        write(1, "\b", 1);
        write(1, " ", 1);
        write(1, "\b", 1);
    }
    word = my_strcat("$", word);
    replace_word(word, input, autol);
    free(word);
    return 1;
}

int bad_arg(int ac, int size, int *j)
{
    int i = 0;

    if (ac != 1)
        return 0;
    for (i = 0; i < size; i++) {
        write(1, "\b", 1);
        write(1, " ", 1);
        write(1, "\b", 1);
    }
    *j = i;
    return 1;
}

glob_t cmd_complete4(char **input, char *path)
{
    char *word = get_word(input);
    char *word2;
    char *word3;
    glob_t glob_st;

    word2 = my_strcat(word, "*");
    free(word);
    word = my_strcat(path, "/");
    word3 = my_strcat(word, word2);
    free(word2);
    glob(word3, 0, NULL, &glob_st);
    free(word);
    free(word3);
    return glob_st;
}

static int cmd_complete2(struct auto_var *autol,
    char **input, char **env, char *path)
{
    glob_t glob_st;
    int size = my_strlen(*input);
    int i = 0;
    char *word;

    glob_st = cmd_complete4(input, path);
    if (!bad_arg(glob_st.gl_pathc, size, &i)) {
        globfree(&glob_st);
        return 0;
    }
    for (i = my_strlen(glob_st.gl_pathv[0]); i > 0 &&
        glob_st.gl_pathv[0][i] != '/'; i--);
    word = glob_st.gl_pathv[0] + i + 1;
    replace_word(word, input, autol);
    globfree(&glob_st);
    return 1;
}

static int cmd_complete3(struct auto_var *autol, char **input,
    char **env, char *path)
{
    char *path2 = NULL;

    path = strtok(path, ":");
    while (path) {
        if (path[my_strlen(path) - 1] != '/')
            path2 = my_strcat(path, "/");
        free(path2);
        if (cmd_complete2(autol, input, env, path))
            return 0;
        path = strtok(NULL, ":");
    }
    return 0;
}

static int cmd_complete(struct auto_var *autol, char **input, char **env)
{
    int i = 0;
    char *path = my_getenv(env, "PATH", &i);
    char *path2 = NULL;

    path = my_strcat(path, "");
    if (!path)
        return 1;
    path2 = my_strcat(path, "");
    free(path);
    cmd_complete3(autol, input, env, path2);
    free(path2);
    return 0;
}

static int arg_complete(struct auto_var *autol, char **input, char **env)
{
    char *word2 = get_word(input);
    char *word;
    glob_t glob_st;
    int size = my_strlen(*input);
    int i = 0;

    word = my_strcat(word2, "*");
    free(word2);
    glob(word, 0, NULL, &glob_st);
    free(word);
    if (!bad_arg(glob_st.gl_pathc, size, &i))
        return 0;
    for (i = my_strlen(glob_st.gl_pathv[0]); i > 0 &&
        glob_st.gl_pathv[0][i] != '\t' && glob_st.gl_pathv[0][i] != ' ' &&
        glob_st.gl_pathv[0][i] != '\n'; i--);
    word = glob_st.gl_pathv[0] + i;
    replace_word(word, input, autol);
    globfree(&glob_st);
    return 1;
}

static int is_var(char *input)
{
    char *word = get_word(&input);

    if (word[0] == '$')
        return 1;
    free(word);
    return 0;
}

int complete(struct auto_var *autol, char **input, char **env)
{
    if (autol->i <= 1 || !input || !(*input) || !((*input)[0]))
        return 0;
    if (is_var(*input)) {
        get_variables(autol, input, env);
    } else if (!is_arg(*input)) {
        cmd_complete(autol, input, env);
    } else {
        arg_complete(autol, input, env);
    }
    return 0;
}
