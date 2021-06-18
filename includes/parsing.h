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
# include "../gnl/get_next_line.h"

/*
** parse.c
*/

int						save_cmd(t_program **new, t_dlist **tmp);
int						save_args(t_program **new, t_dlist **tmp, t_dlist **parse, int count);
int						save_parse(t_dlist **programs, t_dlist **parse);
int						parse(t_dlist **program);

/*
** parse_env.c
*/

int						find_env_symbol(int i);
int						find_next_env(int *start, int *end);
int						replace_env(int	start, int end, char *content);
int						parse_env(void);

/*
** parse_utils.c
*/

int						cut_line(char *str, t_dlist **save_lst, int start, int end);
int						del_quote(t_dlist **parse);

/*
** parse_semicolon.c
*/
int						parse_semicolon(t_dlist **substr, int *start, int *end);
int						parse_line_first(int *is_sq_c, int *is_dq_c, t_dlist **substr);

/*
** parse_blank.c
*/
int						parse_blank(char *curstr, t_dlist **substr, int *start, int *end);
int						parse_line_second(int *is_sq_c, int *is_dq_c, char *curstr, t_dlist **parse);

/*
** parse_input.c
*/

int						save_input(void);
int						del_last_char(void);
void					save_key(int c);
int						process_key(int c);

/*
** parse_history.c
*/

void					save_history(t_dlist **history);
void					history_up(void);
void					history_down(void);

/*
** parse_quote.c
*/

void					count_quote(int *double_quote, int *single_quote, int i);
int						check_quote_closed(void);
int						check_quote(void);

#endif