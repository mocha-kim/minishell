#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** cut line, similar to ft_substtr, save to 
** return 1:succeed 127:exit
*/

int		cut_line(char *str, t_list **save_lst, int start, int end)
{
	char	*tmp;

	if (start != end)
	{
		tmp = ft_substr(str, start, end - start);
		if (!tmp)
			return(print_memory_error(ERR_MALLOC));
		ft_lstadd_back(save_lst, ft_lstnew(tmp));
	}
	return (1);
}

/*
** delete outer quotes
** return 1:succeed 127:exit
*/

int		del_quote(t_list **parse)
{
	t_list	*tmp;
	char	*str;

	tmp = *parse;
	while (tmp)
	{
		if (((char *)(tmp->content))[0] == '\'' || ((char *)(tmp->content))[0] == '\"')
		{
			str = ft_substr(tmp->content, 1, ft_strlen(tmp->content) - 2);
			if (!str)
				return (print_memory_error(ERR_MALLOC));
			free(tmp->content);
			tmp->content = str;
		}
		tmp = tmp->next;
	}
	return (1);
}