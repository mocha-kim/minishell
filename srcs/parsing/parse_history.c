#include "../../includes/parsing.h"

/*
** save hitory list
*/
void	save_history(t_list **history, char *processed_line)
{
	if (!processed_line)
	{
		ft_lstadd_front(history, ft_lstnew(ft_strdup(processed_line)));
		free(processed_line);
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