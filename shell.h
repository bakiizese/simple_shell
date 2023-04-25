#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



#define RB_SIZE 1024
#define WB_SIZE 1024
#define BUFSH -1
#define H_F	".shell_hist"
#define H_M	4096
#define NORM	0
#define OR		1
#define AND		2
#define CHAIN	3
#define USE_GETLINE 0
#define USE_STRTOK 0
#define CONV_LOW	1
#define CONV_UNSIGN	2





extern char **environ;


/**
 * struct lists - entry
 * @n: var
 * @str: var
 * @next: var
 */
typedef struct lists
{
	int n;
	char *str;
	struct lists *next;
} lists_t;
/**
 * struct psinf - entry
 * @arg: var
 * @argv: var
 * @path: var
 * @argc: var
 * @lcount: var
 * @err_n: var
 * @lcount_f:var
 * @fn: var
 * @env: var
 * @hist: var
 * @alias: var
 * @environ: var
 * @env_ch: var
 * @stat: var
 * @cmdb: var
 * @cmdb_type: var
 * @readfd: var
 * @hcount: var
 */
typedef struct psinf
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int lcount;
	int err_n;
	int lcount_f;
	char *fn;
	lists_t *env;
	lists_t *hist;
	lists_t *alias;
	char **environ;
	int env_ch;
	int stat;

	char **cmdb;
	int cmdb_type;
	int readfd;
	int hcount;
} inf_o;

#define INF_IN \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - entry
 * @type: var
 * @func: var
 */
typedef struct builtin
{
	char *type;
	int (*func)(inf_o *);
} builtin_t;

/*getline*/
ssize_t get_input(inf_o *);
int _getline(inf_o *, char **, size_t *);
void sinthand(int);

/*strtok*/
char **strtok1(char *, char *);
char **strtok2(char *, char);

int loophsh(char **);

/*env1*/
char *genv(inf_o *, const char *);
int menv(inf_o *);
int msetenv(inf_o *);
int munsetenv(inf_o *);
int penv_list(inf_o *);

/*env2*/
char **genvn(inf_o *);
int _unsetenv(inf_o *, char *);
int stenv(inf_o *, char *, char *);

/*args*/
void cls_inf(inf_o *);
void st_inf(inf_o *, char **);
void fr_inf(inf_o *, int);
int bfr(void **);

/*builtin1*/
int mhist(inf_o *);
int malias(inf_o *);

/*builtin2*/
int mexit(inf_o *);
int mcd(inf_o *);
int mhp(inf_o *);

/*erprint1*/
int _eatoi(char *);
void p_err(inf_o *, char *);
int p_d(int, int);
char *conv_n(long int, int, int);
void r_comm(char *);

/*erprint2*/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int f);
int _putsfd(char *s, int f);

/*str*/
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*history*/
char *ghist_file(inf_o *inf);
int w_hist(inf_o *inf);
int r_hist(inf_o *inf);
int b_hist_list(inf_o *inf, char *b, int lc);
int re_hist(inf_o *inf);

/*mem*/
char *_memset(char *, char, unsigned int);
void ffr(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*var*/
int ischain(inf_o *, char *, size_t *);
void chchain(inf_o *, char *, size_t *, size_t, size_t);
int re_alias(inf_o *);
int re_vars(inf_o *);
int re_string(char **, char *);

/*list*/
lists_t *add_node(lists_t **, const char *, int);
lists_t *add_node_end(lists_t **, const char *, int);
size_t p_list_str(const lists_t *);
int delete_node_at_i(lists_t **, unsigned int);
void fr_list(lists_t **);

/*list2*/
size_t l_len(const lists_t *);
char **l_to_s(lists_t *);
size_t p_list(const lists_t *);
lists_t *node_starts_with(lists_t *, char *, char);
ssize_t get_node_i(lists_t *, lists_t *);

/*args_per*/
int iscmd(inf_o *, char *);
char *char_cp(char *, int, int);
char *fd_p(inf_o *, char *, char *);

/*loop*/
int arg_loop(inf_o *, char **);
int f_built(inf_o *);
void f_cmd(inf_o *);
void fr_cmd(inf_o *);

/*utils*/
int interactive(inf_o *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/*func1*/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/*func2*/
int _strlen(char *);
int _strcmp(char *, char *);
char *st_wi(const char *, const char *);
char *_strcat(char *, char *);

#endif /*SHELL_H*/
