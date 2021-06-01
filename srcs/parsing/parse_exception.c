#include "../../includes/parsing.h"

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
			write(2, "bash: syntax error near unexpected token `;", 43);
			if (line[j + 1] == ';')
				write(2, ";", 1);
			write(2, "'\n", 2);
			return (-1);
		}
		new = ft_lstnew((void*)ft_substr(line, i, j - i + 1));
		ft_lstadd_back(lst, new);
		i += j;
		i++;
	}
	return (1);
}