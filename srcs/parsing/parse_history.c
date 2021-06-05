#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** save hitory list
*/
void	save_history(t_list **history)
{
	if (g_state.line)
	{
		ft_lstadd_front(history, ft_lstnew(ft_strdup(g_state.line)));
	}
}

/*
**
*/
void	history_up(t_list **history)
{
	(void)history;
}

/*
**
*/
void	history_down(t_list **history)
{
	(void)history;
}