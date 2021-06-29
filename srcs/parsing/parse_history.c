/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:13:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/06/29 21:12:18 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** make new history node(content: null)
*/

void		set_history(t_history **history)
{
	g_state.cur = ft_historynew(NULL);
	g_state.ptr = g_state.cur;
	ft_historyadd_front(history, g_state.cur);
}

static void	clear_tmp_history(t_history **history)
{
	t_history *tmp;

	tmp = *history;
	while (tmp)
	{
		if (tmp->tmp)
		{
			free(tmp->tmp);
			tmp->tmp = NULL;
		}
		tmp = tmp->next;
	}
}

int			save_history(t_history **history)
{
	int		ret;

	ret = 1;
	g_state.cur->save = ft_strdup(g_state.ptr->tmp);
	if (!(g_state.cur->save) || g_state.cur->save[0] == '\0')
	{
		*history = g_state.cur->next;
		if (g_state.cur->prev)
			g_state.cur->prev->next = g_state.cur->next;
		if (g_state.cur->next)
			g_state.cur->next->prev = g_state.cur->prev;
		free(g_state.cur->save);
		g_state.cur->save = NULL;
		free(g_state.cur->tmp);
		g_state.cur->tmp = NULL;
		free(g_state.cur);
		g_state.cur = NULL;
		ret = 0;
	}
	clear_tmp_history(history);
	return (ret);
}

void		history_up(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->next))
		return ;
	if (g_state.ptr->tmp)
	{
		ptrlen = ft_strlen(g_state.ptr->tmp);
		while (ptrlen)
		{
			ft_putchar_fd('\b', STD_OUT);
			ft_putstr_fd(" \b", STD_OUT);
			ptrlen--;
		}
	}
	g_state.ptr = g_state.ptr->next;
	if (!(g_state.ptr->tmp))
		g_state.ptr->tmp = ft_strdup(g_state.ptr->save);
	ft_putstr_fd(g_state.ptr->tmp, STD_OUT);
}

void		history_down(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->prev))
		return ;
	if (g_state.ptr->tmp)
	{
		ptrlen = ft_strlen(g_state.ptr->tmp);
		while (ptrlen)
		{
			ft_putchar_fd('\b', STD_OUT);
			ft_putstr_fd(" \b", STD_OUT);
			ptrlen--;
		}
	}
	g_state.ptr = g_state.ptr->prev;
	ft_putstr_fd(g_state.ptr->tmp, STD_OUT);
}
