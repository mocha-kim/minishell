/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:33:43 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:33:44 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

extern t_state	g_state;

int		ft_env(void)
{
	t_env	*env;

	env = g_state.env;
	while (env)
	{
		if (!ft_strcmp(env->name, "?") || !env->content)
		{
			env = env->next;
			continue;
		}
		printf("%s=%s\n", env->name, env->content);
		env = env->next;
	}
	g_state.ret = 0;
	return (0);
}
