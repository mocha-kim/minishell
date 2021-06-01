#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

/*
** return 0:success -1:failed 127:exit
*/
int		minishell(t_parse **info, t_list **history)
{
	char	*processed_line;

	while (1)
	{
		// prompt
		prompt();
		// gnl
		if (save_input(&processed_line) != 1)
			continue ;
		save_history(history, processed_line);
		if (check_quote(processed_line) != 1)
			continue ;
		if (!parse(processed_line, info))
			continue ;
		// excute
		printf("execute\n");
	}
	ft_lstclear(history, free);
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_parse	*info;
	t_list	*history;

	(void)argc;
	(void)argv;
	(void)envp;
	info = NULL;
	history = NULL;

	// signal
	// minishell
	minishell(&info, &history);
	return (0);
}