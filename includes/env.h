#ifndef ENV_H
# define ENV_H

# include "data.h"
# include "../libft/libft.h"

/*
** env_parse.c
*/
int			env_parse(t_state *state, char *envp[]);
t_env		*env_new(char *envp);
void		env_add(t_env **lst, t_env *new);
char		*env_search(t_env *env, char *name);
/*
** env.c
*/
int			env_change(t_env *env, char *name, char *content);

#endif