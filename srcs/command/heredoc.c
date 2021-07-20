#include "../../includes/command.h"

extern t_state	g_state;

void	find_env(char **line)
{
	int		i;
	int		j;
	char	*env;

	i = -1;
	while (++i < ft_strlen(*line))
	{
		if (*line[i] == '$')
		{
			if (*line[i + 1] == '\0')
				return ;
			j = i + 1;
			while (*line[j] && *line[j] != ' ' && *line[j] != '$'
			&& *line[j] != ';' && *line[j] != '\"' && *line[j] != '\'')
				j++;
			if (j == i + 1)
				continue ;
			env = ft_substr(*line, i + 1, j - i);
			printf("env: |%s|\n", env);
			replace_env(line, i - 1, j, env_search(env));
			free(env);
			printf("line: |%s|\n", *line);
			i = j - 1;
		}
	}
}

void	gnl(int fd, char *eof)
{
	char *line;

	line = 0;
	while (1)
	{
		write(1, "> ", 2);
		if (get_next_line(0, &line) == 0)
			break ;
		if (ft_strcmp(line, eof) == 0)
			break ;
		find_env(&line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_strdel(&line);
	}
	close(fd);
}