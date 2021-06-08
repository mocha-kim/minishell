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