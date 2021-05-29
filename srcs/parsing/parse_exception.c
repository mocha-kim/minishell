#include "../../includes/parsing.h"
#include <stdio.h>

int		count_backslash(char *line)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (line[ft_strlen(line) - i] == '\\')
	{
		count++;
		i++;
	}
	return (count);
}

void	convert_backslash(char **line)
{
	int		len;

	len = ft_strlen(*line);
	if (*line[len - 1] == '\\')
	{
		if (*line[len - 2] != '\\')
			*line[len - 1] = '\0';
	}
}

int		process_backslash(char **line, char **processed)
{
	char	*s1;
	char	*s2;

	if (*processed == NULL)
	{
		free(*processed);
		*processed = ft_strdup(*line);
	}
	else
	{
		s1 = ft_strdup(*line);
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