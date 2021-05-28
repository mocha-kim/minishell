#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

int		minishell(t_parse **info)
{
	char	*line;
	// int		command;
	int		nread;

	while (1)
	{
		// prompt
		prompt();
		// gnl
		if ((nread = get_next_line(0, &line)) < 0)
			continue;
		// parsing
		// history save
		parse(line, info);
		// excute
		printf("execute\n");
	}
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_parse *info;

	(void)argc;
	(void)argv;
	(void)envp;

	// signal
	// minishell
	info = 0;
	minishell(&info);
	return (0);
}