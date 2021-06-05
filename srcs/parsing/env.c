#include "../../includes/env.h"

/*
** env_change
** Change environment variable values
** env: linked list, name: change target, content: Value to be changed
** return : 1: success change, 0: not exist env value
*/
int		env_change(t_env *env, char *name, char *content)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = content;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}