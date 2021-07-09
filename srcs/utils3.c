/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:41:21 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/09 15:59:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

extern t_state	g_state;

void	init_state()
{
	g_state.sig = 1;
	g_state.cur = NULL;
	g_state.ptr = NULL;
	g_state.env = NULL;
	g_state.is_fork = 0;
}

void	free_state()
{
	env_clear(&(g_state.env));
	g_state.cur = NULL;
	g_state.ptr = NULL;
}