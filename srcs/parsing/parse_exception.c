#include "../../includes/parsing.h"
#include <stdio.h>

int		process_quote(char *line, char **processed)
{
	char	*s1;
	char	*s2;

	if (*processed == NULL)
	{
		free(*processed);
		*processed = ft_strdup(line);
	}
	else
	{
		s1 = ft_strdup(line);
		s2 = ft_strdup(*processed);
		if (s1 == NULL || s2 == NULL)
			return (0);
		*processed = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
	}
	if (*processed == NULL)
		return (0);
	return (1);
}

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