/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:47 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/09 15:59:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

extern t_state	g_state;

static char	*envp_join(char *name, char *cont)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(name, "=");
	tmp = ft_strjoin(str, cont);
	free(str);
	return (tmp);
}

char		**make_envp(void)
{
	char	**res;
	int		i;
	int		len;
	t_env	*env;

	i = 0;
	len = env_cnt();
	if (!(res = malloc(sizeof(char *) * (len + 1))))
		return (0);
	env = g_state.env;
	while (i < len)
	{
		if (!ft_strcmp("?", env->name))
		{
			env = env->next;
			continue ;
		}
		res[i] = envp_join(env->name, env->content);
		env = env->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

int			env_cnt(void)
{
	int		i;
	t_env	*tmp;

	tmp = g_state.env;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp("?", tmp->name))
		{
			tmp = tmp->next;
			continue ;
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
** env_delone
** argument: name: delete target name
** return: success: 1, fail: 0
*/

int			env_delone(char *name)
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

void		env_clear(t_env **env)
{
	t_env *tmp;

	while (*env)
	{
		tmp = (*env)->next;
		if ((*env)->content)
			free((*env)->content);
		if ((*env)->name)
			free((*env)->name);
		free(*env);
		(*env) = tmp;
	}
	*env = NULL;
}
