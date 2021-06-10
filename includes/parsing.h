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

# define KEY_UP 4283163
# define KEY_DOWN 4348699
# define KEY_BACKSPACE 127
# define KEY_EOF 4

# define ODD_NUM 1
# define EVEN_NUM 0

# include <stdio.h>
// # include <termios.h>
// # include <term.h>

# include "error.h"
# include "data.h"
# include "utils.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

/*
** parse.c
*/

int						save_cmd(t_command **new, t_list **tmp);
int						save_args(t_command **new, t_list **tmp, t_list **parse, int count);
int						save_parse(t_list **info, t_list **parse);
int						parse(t_list **info);

/*
** parse_utils.c
*/

int						cut_line(char *str, t_list **save_lst, int start, int end);
int						del_quote(t_list **parse);

/*
** parse_semicolon.c
*/
int						parse_semicolon(t_list **substr, int *start, int *end);
int						parse_line_first(int *is_sq_c, int *is_dq_c, t_list **substr);

/*
** parse_blank.c
*/
int						parse_blank(char *curstr, t_list **substr, int *start, int *end);
int						parse_line_second(int *is_sq_c, int *is_dq_c, char *curstr, t_list **parse);

/*
** parse_input.c
*/

int						save_input(t_list **history);
int						del_last_char(void);
void					save_key(int c);
int						process_key(int c, t_list **history);

/*
** parse_history.c
*/

void					save_history(t_list **history);
void					history_up(t_list **history);
void					history_down(t_list **history);

/*
** parse_quote.c
*/

void					count_quote(int *double_quote, int *single_quote, int i);
int						check_quote_closed(void);
int						check_quote(void);

#endif