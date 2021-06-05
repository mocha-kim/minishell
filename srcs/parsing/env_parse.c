#include "../../includes/env.h"

static int	env_line_parse(char *envp)
{
	int		i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	return (i);
}

int			env_parse(t_state state, char *envp[])
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (envp[i])
	{
		if (!(tmp = env_new(envp[i])))
			return (0);
		env_add(&(state.env), tmp);
		i++;
	}
	return (1);
}

t_env		*env_new(char *envp)
{
	t_env	*result;
	int		i;

	if (!(result = malloc(sizeof(t_env))))
		return (0);
	i = env_line_parse(envp);
	result->name = ft_substr(envp, 0, i);
	result->content = ft_substr(envp, i + 1, ft_strlen(envp) - (i + 1));
	result->next = 0;
	return (result);
}

void		env_add(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}