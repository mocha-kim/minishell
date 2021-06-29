#ifndef PARSING_H
# define PARSING_H

# define TRUE 1
# define FALSE 0

# define CMD_ECHO 1
# define CMD_CD 2
# define CMD_PWD 3
# define CMD_EXPORT 4
# define CMD_UNSET 5
# define CMD_ENV 6
# define CMD_EXIT 7

# define KEY_ARROW_UP 4283163
# define KEY_ARROW_DOWN 4348699
# define KEY_BSPACE 127
# define KEY_EOF 4

# define ODD_NUM 1
# define EVEN_NUM 0

# include <stdio.h>

# include "error.h"
# include "data.h"
# include "utils.h"
# include "env.h"
# include "../libft/libft.h"

/*
** parse.c
*/

int						init_program(t_program **new, t_dlist **tmp);
int						save_args(t_program **new, t_dlist **tmp, t_dlist **parse, int count);
void					save_flag(t_dlist **programs);
int						save_parse(t_dlist **programs, t_dlist **parse);
int						parse(t_dlist **program, char *line);

/*
** parse_env.c
*/

int						find_env_symbol(char *line, int i);
int						find_next_env(char *line, int *start, int *end);
int						replace_env(char **line, int start, int end, char *content);
int						parse_env(char **line);

/*
** parse_utils.c
*/

int						cut_line(const char *str, t_dlist **save_lst, int start, int end);
int						del_quote(t_dlist **parse);
int						free_before_exit(t_dlist **dlist, int errn);

/*
** parse_first.c
*/
int						parse_semicolon(const char *line, t_dlist **substr, int *start, int *end);
int						parse_line1(int *is_sq_c, int *is_dq_c, const char *line, t_dlist **substr);

/*
** parse_flags.c
*/

int						is_flag(char c);
int						parse_pipe(const char *line, t_dlist **substr, int *start, int *end);
int						parse_redir(const char *curstr, t_dlist **parse, int *start, int *end);
int						parse_lab(const char *curstr, int *end, t_dlist **parse);
int						parse_rab(const char *curstr, int *end, t_dlist **parse);

/*
** parse_second.c
*/
int						parse_blank(const char *curstr, t_dlist **substr, int *start, int *end);
int						parse_line2(int *sq, int *dq, const char *curstr, t_dlist **parse);

/*
** parse_input.c
*/

int						save_input(void);
int						del_last_char(void);
void					save_key(int c);
void					process_key(int c);

/*
** parse_history.c
*/

void					set_history(t_history **history);
void					save_history(t_history **history);
void					history_up(void);
void					history_down(void);

/*
** parse_quote.c
*/

void					count_quote(char *line, int *double_quote, int *single_quote, int i);
int						check_quote_closed(char *line);
int						check_quote(char *line);

#endif