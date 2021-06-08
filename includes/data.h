#ifndef DATA_H
# define DATA_H

/*
** flag: pipe / (>, <, >>)redirect
*/
typedef struct			s_command
{
	char				*command;
	int					flag;
	char				*option;
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
*/
typedef struct 		s_state
{
	int				sig;
	char			*line;
	t_env			*env;
}					t_state;


#endif