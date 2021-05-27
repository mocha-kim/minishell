#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

int		minishell(t_command *info)
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
			// error
		// parsing
		// history save
		parse(line, info);
		// excute
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	t_command info;

	(void)argc;
	(void)argv;
	(void)envp;

	// signal
	// minishell
	minishell(&info);
	return (0);
}