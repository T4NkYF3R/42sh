/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <glob.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <curses.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#ifndef SHELL_H
    #define SHELL_H

struct pipe_needs {
    int i;
    char **array;
    int copystdin;
    int pipefd[2];
};

struct a {
    int i;
    char **array;
    char **array2;
    char *buffer;
    struct a *next;
};

struct auto_var {
    int c;
    int i;
    int v;
    int j;
    int max;
    int arrow;
    char *buffer;
    char **args;
};

struct env_var {
    int x;
    char **env;
    char *var_name;
};

int env_size(char **env);

int find_red(char **array);

char *up_key(int *i, int *j, char **args);

int complete(struct auto_var *autol, char **input, char **env);

char *down_key(int *i, int *j, char **args);

int is_arg2(char **array);

int is_arg(char *input);

char *get_word(char **input);

int replace_word(char *word, char **input, struct auto_var *autol);

char *find_var(char *word, char **env);

int get_cursor_position(int *row, int *col);

int get_input3(struct auto_var *autol, char **input);

int get_input4(struct auto_var *autol, char **input);

int get_input5(struct auto_var *autol, char **input);

int get_input2(struct auto_var *autol, char **input);

int my_strlen(char *str);

int pipe_red7(struct pipe_needs *pipe_needs, int *v, char **env, struct a *a);

char **check_env(char **env);

char *array_to_str(char **array);

int auto_complete(char **env, char **input, int v);

int array_len(char **array);

char **pipe_red6(char **array, int i, int pipefd[2], int *v);

char **pipe_red4(char **array, int i);

int d_right_red(struct a *a, int i, int *v, char **env);

int left_red(struct a *a, int i, int *v, char **env);

int parse_cmd(struct a *a, int *v, char **env);

int parse_cmd2(char *cmd, int *v, char **env, char **array);

char **parse_spaces(char *cmd);

int pipe_red(struct a *a, int i, int *v, char **env);

int right_red(struct a *a, int i, int *v, char **env);

char **test_args(char **args, int *a, char **env);

char **my_setenv2(char **env, int *j, char **args, int *a);

void my_prompt(int v);

int is_alphanum(char a);

int sfnb_word(char *str);

int sflen_word(char *str);

int free_tabs(char **tab);

char **stwa(char *str);

char **stwac(char *str);

char **stwas(char *str);

int flen_word(char *str);

char *my_strcat(char *dest, char *src);

int my_strcmp(char const *s1, char const *s2);

void my_cd_error(char *arg, char *dir);

int print_history(char *array, int *v);

char *set_b(char *str);

int check_size(int size);

char **strtow(char *buffer);

void stock_array(char *array);

void redirect_stdin(void);

char **parse_input(char *buffer);

void my_exec_error(char *arg, char **args, int p);

char **parse_flags(char **array);

char **setenv3(char **env, int *a, char **args);

int my_strcmp2(char const *s1, char const *s2);

char *my_getenv(char **env, char *str, int *i);

char **my_setenv(char **env, char **args, int *v);

void print_env(char **args, char **env);

char **my_unsetenv(char **env, char **args, char *arg);

int parse_binary(struct a *a, int *v, char **env);

int double_pipe(struct a *a, int i, int *v, char **env);

int double_and(struct a *a, int i, int *v, char **env);

int my_env(char *buffer, char ***env, int *v);

char *my_cd2(char *arg, char **env, int i, char *dir);

char **my_cd(char **env, char *arg, int *v);

char **reset_env(int i, char **env);

void put_env(char **env);

char *env_var(char *buffer, char **env, int *v);

int check_eq(char *arg);

int set_cd(char *buffer, char ***env, int *v);

int my_seg(int status);

char **my_exec(struct a *a, char **env);

char **my_fork(struct a *a, char **env, int *v);

int my_read(int ac, char ***env, int v);

int loopfork2(struct a *a, char ***env, int v);

int loopfork(struct a *a, char ***env, int size, int v);

char *get_path(char **args, char **env);

char **copyenv(char **env, int j);

int my_getnbr(char const *str);

int lenargs(char **args);

char *stars_search(char *str);

int find_stars(char *str);

int find_interogation(char *str);

char *inter_point(char *str);

char *my_strcat_spe(char *str1, char *str2);

int strncomp(char *str1, char *str2, int n);

char *read_history2(void);

char *history_point(char *str);

char *get_number(char **argv);

char *get_string(char **argv);

void print_nums(char c, int line, int last, char *str);

int my_set(char *buffer, char ***env, int *v);

int crocus(char **argv, int *v);

int my_arrlen(char **array);

char *local_var(char *buffer, char **env, int *v);

char *cat_char(char *str, char c);

char *get_var(char **array, int *x);

void zero(int line, char c, int last);

void one(int line, char c, int last);

void two(int line, char c, int last);

void three(int line, char c, int last);

void four(int line, char c, int last);

void five(int line, char c, int last);

void six(int line, char c, int last);

void seven(int line, char c, int last);

void height(int line, char c, int last);

void nine(int line, char c, int last);

int my_getnbr2(char const *str);

char *repeat(char *buffer);

void display_alias(void);

void display_com_alias(char *a);

char *get_alias(void);

int alias(char *str, int *v);

void set_alias(char **commande);

int if_unalias(char **commande, int len, int *v);

void write_line(int fd, char **line);

char *com_is_alias(char *str);

char *no_quote(char *str, char ***env, int v);

int fg_bg(char **args, char **env);

char *miss_quote(char ***env, int v);

int is_glob(char *str);

char *get_command(char *array);

char *get_args(char *array);

char **tab_glob(char *args, char *command);

char **my_fork_glob(char **g_tab, char **env, int *v, struct a *a);

char **my_exec_glob(char **g_tab, char **env, struct a *a);

int check_parenthese(char *str);

char **tab_backticks(char *str);

char *backticks(char *str, int *v);

bool check_for_one_arr(char **args, int word, FILE *fptr);

void check_for_one_arr2(int res, FILE *fptr, char *first_var, char *var_value);

void display_file_content(char *filename);
#endif /* SHELL_H */
