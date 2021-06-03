#include "../../includes/parsing.h"

extern t_state	g_state;

/*
** count number of backslashs(\)
** return number of backslashs at the end of the line
*/
int				count_backslash(char **line)
{
	int		i;
	int		count;
	int		len;

	i = 1;
	count = 0;
	if (*line)
	{
		len = ft_strlen(*line);
		while (*line[len - i] == '\\')
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}

/*
** if line has only 1 backslash at the end of the line,
** delete the backslash to save history
*/
void			convert_backslash(char **line)
{
	int		len;

	len = ft_strlen(*line);
	if (*line[len - 1] == '\\')
	{
		if (*line[len - 2] != '\\')
			*line[len - 1] = '\0';
	}
}

/*
** join the new line and saved line
** return 0:failed 1:succeed 
*/
int				process_backslash(char **processed)
{
	char	*s1;
	char	*s2;

	printf("bok\n");
	if (*processed == NULL)
	{
		free(*processed);
		*processed = ft_strdup(g_state.line);
	}
	else
	{
		s1 = ft_strdup(g_state.line);
		s2 = ft_strdup(*processed);
		if (s1 == NULL || s2 == NULL)
			return (0);
		free(*processed);
		*processed = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
	}
	printf("bok\n");
	if (*processed == NULL)
		return (0);
	printf("bok\n");
	convert_backslash(processed);
	printf("bok\n");
	return (1);
}