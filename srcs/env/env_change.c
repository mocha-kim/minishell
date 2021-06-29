#include "../../includes/env.h"

extern t_state	g_state;

/*
** env_change
** Change environment variable values
** env: linked list, name: change target, content: Value to be changed
** return : 1: success change, 0: not exist env value
*/
int		env_change(char *name, char *content)
{
	t_env	*tmp;

	tmp = g_state.env;
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

/*
** env_delone
** argument: name: delete target name
** return: success: 1, fail: 0
*/
int		env_delone(char *name)
{
	t_env	*tmp;
	t_env	*prev;

	prev = g_state.env;
	tmp = g_state.env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			free(tmp->name);
			if (tmp->content)
				free(tmp->content);
			if (prev != tmp)
				prev->next = tmp->next;
			else
				g_state.env = tmp->next;
			free(tmp);
			return (1);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}

static int	find_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int		env_change2(char *line)
{
	t_env	*tmp;
	int		i;
	char	*cont;
	char	*name;

	tmp = g_state.env;
	i = find_char(line);
	name = ft_strdup(line);
	name[i] = 0;
	cont = ft_substr(line + i + 1, 0, ft_strlen(line + i + 1));
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = cont;
			free(name);
			return (1);
		}
		tmp = tmp->next;
	}
	free(cont);
	free(name);
	return (0);
}
