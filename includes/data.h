#ifndef DATA_H
# define DATA_H

#include "../libft/libft.h"

/*
** flag: pipe / (>, <, >>)redirect
*/
typedef struct			s_command
{
	char				*command;
	int					flag;
	int					argc;
	char				**args;
	int					pip[2];
}						t_command;

/*
** input info
*/

typedef struct			s_parse
{
	struct s_parse		*next;
	t_command			cmd;
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
	t_dlist			*cur;
	char			*line;
	t_env			*env;
}					t_state;

#endif