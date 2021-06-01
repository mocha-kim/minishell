#include "../../includes/parsing.h"

/*
**
** return 0:failed 1:succeed 
*/
int		syntax_check(t_list **lst, char *line)
{
	int		i;
	int		j;
	int		size;
	t_list	*new;
	int		k;

	i = 0;
	
	size = ft_strlen(line);
	while (i < size)
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (j < size && line[j] != ';')
		{
			if (line[j] == '\'' || line[j] == '\"')
			{
				k = j++;
				while (j < size && line[k] != line[j])
					j++;
			}
			j++;
		}
		if (i == j || (j + 1 < size && line[j + 1] == ';'))
		{
			ft_lstclear(lst, free);
			lst = 0;
			print_syntax_error(ERR_SEMICOLONE2);
			return (-1);
		}
		new = ft_lstnew((void*)ft_substr(line, i, j - i + 1));
		ft_lstadd_back(lst, new);
		i += j;
		i++;
	}
	return (1);
}