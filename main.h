#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct builtin - associates a command name with a handler function
 * @name: function name
 * @func: fucntion handler
 */

struct builtin {
    char *name;
    void (*func)(char **args);
};

/**
 * builtin builtins - array of built in commands. 
 */

struct builtin builtins[] = {
    {"help", sssh_help},
    {"exit", sssh_exit},
    {"cd", sssh_cd},
};

void sssh_cd(char **args);
void sssh_exit(char **args);
void sssh_exec(char **args);
int sssh_num_builtins();
void sssh_help(char **args);
char* read_line();
char** sssh_split_line(char *line);
void sssh_exec(**args);
int sssh_num_builtins();


#endif