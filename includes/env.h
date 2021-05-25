#ifndef ENV_H
# define ENV_H


typedef struct		s_env
{
	struct s_env	*next;
	char			*name;
	char			*content;
}					t_env;

#endif