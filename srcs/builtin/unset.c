/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:36:29 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:36:30 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

extern t_state	g_state;

void		ft_unset(t_program cmd)
{
	int		i;

	i = 1;
	g_state.ret = 0;
	while (cmd.args[i])
	{
		env_delone(cmd.args[i]);
		i++;
	}
}
