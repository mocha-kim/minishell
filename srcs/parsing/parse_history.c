#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** save hitory list
*/
void	save_history(t_dlist **history)
{
	if (g_state.line)
	{
		// if ((*history)->content != g_state.line)
		ft_dlstadd_front(history, ft_dlstnew(ft_strdup(g_state.line)));
		g_state.cur = *history;
	}
}

/*
**
*/
void		history_up()
{
	// int		curlen;

	ft_putstr_fd("\b\b\b\b", STD_OUT);
	ft_dlstadd_front(history, ft_dlstnew(g_state.line))
	// printf("asdf");
	// if (g_state.line)
	// {
	// 	printf("asdf");
	// 	curlen = ft_strlen(g_state.line);
	// 	while (curlen)
	// 	{
	// 		ft_putstr_fd("\b", STD_OUT);
	// 		curlen--;
	// 	}
	// }
	// printf("asdf");
	if (g_state.cur->next)
		g_state.cur = g_state.cur->next;
	ft_putstr_fd(g_state.cur->content, STD_OUT);
}

/*
**
*/
void		history_down()
{
	int		curlen;

	curlen = ft_strlen(g_state.line);
	while (curlen)
	{
		ft_putstr_fd("\b", STD_OUT);
		curlen--;
	}
	g_state.cur = g_state.cur->prev;
	ft_putstr_fd(g_state.cur->content, STD_OUT);
}