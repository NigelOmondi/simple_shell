#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


/* preprocessor directives for read, write and flush symbolic links */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* preprocessor directives for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* preprocessor directives for function convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * constants to be used to control use of getline and strtok functions
 * set to 1 if using system getline function
 */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* macro definition for command history */
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;


/**
 * struct liststructure - a singly linked list
 * @num: an integer containing the number field
 * @str: a pointer string
 * @next: points to the next node of type list_s
 */
typedef struct liststructure
{
	int num;
	char *str;
	struct liststr *next;
} list_s;

/**
 * struct storedata -  stores the information and data relevant
 *    to our shell program,such as command line arguments,
 *    environment variables, and command history.
 * @arg: a pointer to a string; used to store a single command argument
 * @argv: a pointer to a string array;
 *    used to store multiple command arguments
 * @path: a pointer to a string; used to store the path of a file or directory
 * @argc: an integer used to store the number of command arguments in argv
 * @line_count: an unsigned integer used to store the number
 *  of lines in a file or output
 * @err_num: an integer used to store an error code
 * @linecount_flag: an integer used as a flag to indicate
 *    whether to count lines or not
 * @fname: a pointer to a string; used to store the name of a file
 * @env: a pointer to a linked list (local copy of environ);
 *  used to store environment variables
 * @environ: a pointer to string array used to store environment variables;
 *   custom modified copy of environ from LL env
 * @history: the history node,a pointer to a linked list,
 *   used to store command history
 * @alias: the alias node,a pointer to a linked list,
 * used to store command aliases
 * @env_changed:  an integer used as a flag to indicate whether the environment
 *  variables have been modified; on if environ was changed
 * @status: an integer, the return status of the last exec'd command
 * @cmd_buf: a pointer to a string array, which may be used to store
 *    a sequence of commands separated by command operators
 *   (such as ";" or "&&") - address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: an integer, which may be used to indicate
 * the type of command operator used to separate the commands
 * in cmd_buf; CMD_type ||, &&,
 * @readfd:  an integer used to store the file descriptor of a read pipe
 * @histcount: an integer used to store the history
 *line number count .i.e number of commands in the history list
 */
typedef struct storedata
{
	char *fname;
	list_s *env;
	list_s *history;
	list_s *alias;
	char **environ;
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} data_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: a pointer to a character string ,the builtin command flag
 * @func: a pointer to a function that takes a pointer to a data_t
 * struct as a parameter and returns an integer
 */
typedef struct builtin
{
	char *type;
	int (*func)(data_t *);
} builtin_table;


/* shloop.c functions prototypes */
int hsh(data_t *, char **);
int find_builtin(data_t *);
void find_cmd(data_t *);
void fork_cmd(data_t *);

/* parser.c functions prototypes */
int is_cmd(data_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(data_t *, char *, char *);

/* loophsh.c functions prototypes */
int loophsh(char **);

/* errors.c functions prototypes */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string.c functions prototypes */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c functions prototypes */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exits.c functions prototypes */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* tokenizer.c functions prototypes */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* realloc.c functions prototypes */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory.c functions prototypes */
int bfree(void **);

/* _atoi.c functions prototypes */
int interactive(data_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors1.c functions prototypes */
int _erratoi(char *);
void print_error(data_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin.c functions prototypes */
int _myexit(data_t *);
int _mycd(data_t *);
int _myhelp(data_t *);

/* builtin1.c functions prototypes */
int _myhistory(data_t *);
int _myalias(data_t *);

/* getline.c functions prototypes */
ssize_t get_input(data_t *);
int _getline(data_t *, char **, size_t *);
void sigintHandler(int);

/* getinfo.c functions prototypes */
void clear_info(data_t *);
void set_info(data_t *, char **);
void free_info(data_t *, int);

/* environ.c functions prototypes */
char *_getenv(data_t *, const char *);
int _myenv(data_t *);
int _mysetenv(data_t *);
int _myunsetenv(data_t *);
int populate_env_list(data_t *);

/* getenv.c functions prototypes */
char **get_environ(data_t *);
int _unsetenv(data_t *, char *);
int _setenv(data_t *, char *, char *);

/* history.c functions prototypes */
char *get_history_file(data_t *info);
int write_history(data_t *info);
int read_history(data_t *info);
int build_history_list(data_t *info, char *buf, int linecount);
int renumber_history(data_t *info);

/* lists.c functions prototypes */
list_s *add_node(list_s **, const char *, int);
list_s *add_node_end(list_s **, const char *, int);
size_t print_list_str(const list_s *);
int delete_node_at_index(list_s **, unsigned int);
void free_list(list_s **);

/* lists1.c functions prototypes */
size_t list_len(const list_s *);
char **list_to_strings(list_s *);
size_t print_list(const list_s *);
list_s *node_starts_with(list_s *, char *, char);
ssize_t get_node_index(list_s *, list_s *);

/* vars.c functions prototypes */
int is_chain(data_t *, char *, size_t *);
void check_chain(data_t *, char *, size_t *, size_t, size_t);
int replace_alias(data_t *);
int replace_vars(data_t *);
int replace_string(char **, char *);

#endif
