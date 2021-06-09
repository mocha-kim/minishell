#ifndef ENV_H
# define ENV_H

# include "data.h"
# include "../libft/libft.h"

/*
** env_parse.c
*/
int			env_parse(char *envp[]);
t_env		*env_new(char *envp);
void		env_add(t_env **lst, t_env *new);
char		*env_search(char *name);
/*
** env_change.c
*/
int			env_change(char *name, char *content);
int			env_change2(char *line);
int			env_delone(char *name);

#endif