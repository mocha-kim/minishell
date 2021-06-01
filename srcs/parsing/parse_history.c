#include "../../includes/parsing.h"

/*
** save hitory list
*/
void	save_history(t_list **history, char *processed_line)
{
	ft_lstadd_front(history, ft_lstnew(ft_strdup(processed_line)));
	free(processed_line);
}