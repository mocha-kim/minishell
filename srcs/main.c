#include "../includes/minishell.h"

int		prompt()
{
	return (1);
}

int		minishell(t_command *info)
{
	char	*line;
	int		command;

	while (1)
	{
		// prompt
		prompt();
		// gnl
		// parsing
		parse(line, info);
		// excute
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	t_command info;

	// signal
	// minishell
	minishell(&info);
	return (0);
}