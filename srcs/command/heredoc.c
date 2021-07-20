#include "../../includes/command.h"

extern t_state	g_state;

void	find_env(char **line)
{
	int		i;
	int		j;
	char	*env;

	i = -1;
	write(1, *line, ft_strlen(*line));
	write(1, "\n", 1);
	printf("strlen: %zu\n", ft_strlen(*line));
	while (++i < (int)ft_strlen(*line))
	{
		write(1, "1\n", 2);
		if ((*line)[i] == '$')
		{
			j = i + 1;
			while (j < (int)ft_strlen(*line) && (*line)[j] != ' ' && (*line)[j] != '$'
			&& (*line)[j] != ';' && (*line)[j] != '\"' && (*line)[j] != '\'')
				j++;
			fflush(stdout);
			if (j == i + 1)
				continue ;
			env = ft_substr(*line, i + 1, j - i - 1);
			replace_env(line, i, j - 1, env_search(env));
			free(env);
			i = j - 1;
		}
	}
}

void		read_line(int fd, char *eof)
{
	char	*line;
	pid_t	pid;
	int		status;
	char	*prompt;

	g_state.is_fork = TRUE;
	pid = fork();
	if (pid == 0)
	{
		prompt = ft_strdup("> ");
		while (1)
		{
			// write(1, "> ", 2);
			if (!(line = readline(prompt)))
				break ;
			write(1, "\n|", 2);
			write(1, line, ft_strlen(line));
			write(1, "|\n", 2);
			if (!ft_strcmp(line, eof))
			{
				ft_strdel(&line);
				break ;
			}
			find_env(&line);
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
			line = 0;
		}
		close(fd);
		free(prompt);
		exit(g_state.ret);
	}
	else
	{
		close(fd);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_state.ret = WEXITSTATUS(status);
		g_state.is_fork = FALSE;
	}
}

// static void	input_key(int c, int fd)
// {
// 	if (c == KEY_EOF)
// 	{
// 		exit(g_state.ret);
// 	}
// 	else if (c == KEY_BSPACE)
// 		del_last_char();
// 	else if (ft_isprint((char)c))
// 		ft_putchar_fd(c, STD_OUT);
// }

// static int	heredoc_input(void)
// {
// 	int		c;
// 	int		nread;

// 	c = 0;
// 	nread = 1;
// 	while ((nread = read(STD_IN, &c, sizeof(c))) > 0)
// 	{
// 		if (c == '\n')
// 		{
// 			ft_putchar_fd('\n', STD_OUT);
// 			break ;
// 		}
// 		else
// 			input_key(c);
// 		c = 0;
// 	}
// 	if (nread < 0)
// 		return (print_memory_error(ERR_IO));
// 	return (1);
// }