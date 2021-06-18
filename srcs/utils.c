#include "../includes/utils.h"
#include <stdio.h>

int		custom_putchar(int c)
{
	return (write(STD_OUT, &c, 1));
}

void	skip_whitespace(char *str, int *i)
{
	while (str[*i] != 0 && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
				|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == '\v'))
				(*i)++;
}

void	free_info(t_dlist **programs)
{
	int		i;
	t_dlist	*tmp;

	while (*programs)
	{
		if (((t_program *)((*programs)->content))->command)
			free(((t_program *)((*programs)->content))->command);
		if (((t_program *)((*programs)->content))->args)
		{
			i = 0;
			while (i < ((t_program *)((*programs)->content))->argc + 1)
			{
				free(((t_program *)((*programs)->content))->args[i]);
				i++;
			}
			free(((t_program *)((*programs)->content))->args);
		}
		if ((*programs)->content)
			free((*programs)->content);
		tmp = *programs;
		(*programs) = (*programs)->next;
		free(tmp);
	}
	*programs = NULL;
}

char	*ft_strjoin_null(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}