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
		free(tmp->tmp);
		tmp->tmp = NULL;
		tmp = tmp->next;
	}
}

void		save_history(t_history **history)
{
	g_state.cur->save = ft_strdup(g_state.ptr->tmp);
	clear_tmp_history(history);
}

/*
**
*/
void		history_up(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->next))
		return ;
	if (g_state.ptr->tmp)
	{
		ptrlen = ft_strlen(g_state.ptr->tmp);
		// printf("\nup %s(%d) save(%s)\n", g_state.ptr->tmp, ptrlen, g_state.ptr->save);
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

/*
**
*/
void		history_down(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->prev))
		return ;
	if (g_state.ptr->tmp)
	{
		ptrlen = ft_strlen(g_state.ptr->tmp);
		// printf("\ndown %s(%d) save(%s)\n", g_state.ptr->tmp, ptrlen, g_state.ptr->save);
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