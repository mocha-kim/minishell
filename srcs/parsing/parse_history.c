#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** make new history node(content: null)
*/
void	set_history(t_history **history)
{
	g_state.line = NULL;
	g_state.cur = ft_historynew(g_state.line);
	g_state.ptr = g_state.cur;
	ft_historyadd_front(history, g_state.cur);
}

void	save_history(void)
{
	printf("> save %s\n", g_state.line);
	g_state.cur->save = g_state.line;
}

/*
**
*/
void		history_up(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->next))
		return ;
	if (g_state.line)
	{
		ptrlen = ft_strlen(g_state.line);
		while (ptrlen)
		{
			ft_putchar_fd('\b', STD_OUT);
			ft_putstr_fd(" \b", STD_OUT);
			ptrlen--;
		}
	}
	g_state.ptr = g_state.ptr->next;
	ft_strdel(&(g_state.line));
	g_state.line = ft_strdup(g_state.ptr->tmp);
	ft_putstr_fd(g_state.line, STD_OUT);
}

/*
**
*/
void		history_down(void)
{
	int		ptrlen;

	if (!g_state.ptr || !(g_state.ptr->prev))
		return ;
	if (g_state.line)
	{
		ptrlen = ft_strlen(g_state.line);
		while (ptrlen)
		{
			ft_putchar_fd('\b', STD_OUT);
			ft_putstr_fd(" \b", STD_OUT);
			ptrlen--;
		}
	}
	g_state.ptr = g_state.ptr->prev;
	ft_strdel(&(g_state.line));
	if (g_state.ptr->tmp)
		g_state.line = ft_strdup(g_state.ptr->tmp);
	else
		g_state.line = NULL;
	ft_putstr_fd(g_state.line, STD_OUT);
}