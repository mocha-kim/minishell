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

# define ODD_NUM 1
# define EVEN_NUM 0

# include <stdio.h>

# include "../libft/libft.h"

typedef struct			s_command
{
	char				*command;
	int					flag;
	char				*option;
	char				**args;
	int					pip[2];
}						t_command;

typedef struct			s_parse
{
	struct s_parse		*next;
	t_command			cmd;
}						t_parse;

/*
** history.c
*/

void					save_history(char *line, t_list **history);

/*
** parse.c
*/

int						parse(char *line, t_parse **info);

/*
** parse_exception.c
*/

int						syntax_check(t_list **lst, char *line);

/*
** parse_backslash.c
*/


int						count_backslash(char *line);
void					convert_backslash(char **line);
int						process_backslash(char **line, char **processed);

/*
** parse_quote.c
*/

int						check_quote_close(char *line);

#endif