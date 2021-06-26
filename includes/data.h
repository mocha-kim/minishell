#ifndef DATA_H
# define DATA_H

# define REDIR_IN	1
# define REDIR_OUT	2
# define REDIR_APP	3
# define F_PIPE		4

# define NOTF		2
# define IS_DIR		3
/*
** no such file or directory = NSFD
*/
# define NSFD		4

#include <term.h>
#include "../libft/libft.h"

/*
** flag: pipe / (>, <, >>)redirect
*/

typedef struct			s_program
{
	char				*command;
	int					flag;
	int					argc;
	char				**args;
	char				*cmd_loc;
	int					pip[2];
	int					fd[2];
}						t_program;

/*
** input info
*/

typedef struct			s_parse
{
	struct s_parse		*next;
	t_program			cmd;
}						t_parse;

/*
** environment variable
*/

typedef struct		s_env
{
	struct s_env	*next;
	char			*name;
	char			*content;
}					t_env;

/*
** global state
** ret: exit status code
*/

typedef struct 		s_state
{
	int				ret;
	int				sig;
	char			*line;
	t_dlist			*cur;
	t_dlist			*ptr;
	t_env			*env;
	struct termios	term;
}					t_state;

#endif