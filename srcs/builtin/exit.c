#include "../../includes/builtin.h"
#include <stdlib.h>

void	ft_exit(t_parse *lst, int code)
{
	t_parse *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	exit(code);
}