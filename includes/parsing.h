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
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

/*
** parse.c
*/

void					cut_line(t_list **substr, int start, int end);
int						parse_line(t_parse **info);

/*
** parse_exception.c
*/

int						syntax_check(t_list **lst);

/*
** parse_gnl.c
*/

int						save_input(t_list **history);

/*
** parse_backslash.c
*/

int						count_backslash(char **line);
void					convert_backslash(char **line);
int						process_backslash(char **processed);

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

/*
**
*/

int						del_last_char(void);
void					save_key(int c);
int						process_key(int c, t_list **history);

/*
** parse_utils.c
*/

int						custom_putchar(int c);
void					skip_whitespace(char *str, int *i);

#endif