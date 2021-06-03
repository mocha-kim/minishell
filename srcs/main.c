#include "../includes/minishell.h"

t_state	g_state;

void	prompt()
{
	ft_putstr_fd("minishell-", STD_OUT);
	ft_putstr_fd(VERSION, STD_OUT);
	ft_putstr_fd("$ ", STD_OUT);
}

void	handler(int signo)
{
	ft_putstr_fd("\b\b", STD_OUT);
	if (signo == SIGQUIT)
	{
		ft_putstr_fd("exit\n", STD_OUT);
		exit(0);
	}
	else if (signo == SIGINT)
		ft_putstr_fd("\n", STD_OUT);
	if (g_state.sig)
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
	g_state.sig = 1;

	// signal
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	// minishell
	minishell(&info, &history);
	return (0);
}