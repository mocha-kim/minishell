/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:42 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:35:44 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

extern t_state	g_state;

/*
** env_line_parse
** Parsing a line by '='
** return: '=' address index
*/

static int	env_line_parse(char *envp)
{
	int		i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	return (i);
}

/*
** env_parse : environment variable parsing
** Parses environment variables and stores them
** in (state->)"env" variables in list format
** return : fail: 0, success: 1
*/

int			env_parse(char *envp[])
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (envp[i])
	{
		if (!(tmp = env_new(envp[i])))
			return (0);
		env_add(&(g_state.env), tmp);
		i++;
	}
	if (!(tmp = malloc(sizeof(t_env))))
		return (0);
	tmp->content = ft_itoa(g_state.ret);
	tmp->name = ft_strdup("?");
	tmp->next = 0;
	env_add(&(g_state.env), tmp);
	return (1);
}

/*
** env_new
** return: 0: malloc | parsing fail, parsing success: new node pointer
*/

t_env		*env_new(char *envp)
{
	t_env	*result;
	int		i;

	if (!(result = malloc(sizeof(t_env))))
		return (0);
	i = env_line_parse(envp);
	result->next = 0;
	result->content = 0;
	if (envp[i] != '=')
	{
		result->name = ft_substr(envp, 0, i);
		return (result);
	}
	result->name = ft_substr(envp, 0, i);
	result->content = ft_substr(envp + i + 1, 0, ft_strlen(envp + i + 1));
	return (result);
}

/*
** env_add
** Add a new node to the last "env" in the form of a list
*/

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

/*
** env_search
** Returns the contents of an environment variable named "name"
** in the environment variable list
** return : (name=) content, not exist => NULL
*/

char		*env_search(char *name)
{
	t_env	*tmp;

	tmp = g_state.env;
	if (!ft_strcmp("?", name))
	{
		while (tmp)
		{
			if (!ft_strcmp("?", tmp->name))
			{
				free(tmp->content);
				tmp->content = ft_itoa(g_state.ret);
				return (tmp->content);
			}
			tmp = tmp->next;
		}
	}
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
