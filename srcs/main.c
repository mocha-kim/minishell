#include "../includes/minishell.h"

int		g_signal = 1;

void	prompt()
{
	ft_putstr_fd("minishell-", STD_OUT);
	ft_putstr_fd(VERSION, STD_OUT);
	ft_putstr_fd("$ ", STD_OUT);
}

void	handler(int signo)
{
	ft_putstr_fd("\b\b", STD_ERR);
	if (signo == SIGTERM)
	{
		ft_putstr_fd("exit\n", STD_ERR);
		exit(0);
	}
	else
		ft_putstr_fd("\n", STD_ERR);
	if (g_signal)
		prompt();
}

/*
** return 0:success -1:failed 127:exit
*/
int		minishell(t_parse **info, t_list **history)
{
	char	*processed_line;

	while (1)
	{
		prompt();
		if (save_input(&processed_line) != 1)
			continue ;
		save_history(history, processed_line);
		if (check_quote(processed_line) != 1)
			continue ;
		if (!parse(processed_line, info))
			continue ;
		if ((*info)->cmd.command)
			execute(*info);
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
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	signal(SIGTERM, handler);
	// minishell
	minishell(&info, &history);
	return (0);
}