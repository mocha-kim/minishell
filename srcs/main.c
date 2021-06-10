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
	if (signo == SIGINT)
	{
		if (g_state.line)
			ft_strdel(&g_state.line);
		ft_putstr_fd("\n", STD_OUT);
	}
	else if (signo == SIGQUIT)
		g_state.sig = 0;
	if (g_state.sig)
		prompt();
}

/*
** return 0:success -1:failed 127:exit
*/
int		minishell(t_list **info, t_list **history)
{
	int		input;
	t_list	*tmp;

	input = 1;
	while (1)
	{
		prompt();
		if (save_input(history) != 1)
			continue ;
		// tputs(g_state.line, 1, custom_putchar);
		save_history(history);
		tmp = *history;
		printf("============history============\n");
		while (tmp)
		{
			printf("%s\n", (char *)(tmp->content));
			tmp = tmp->next;
		}
		printf("===============================\n");
		if (check_quote() != 1)
			continue ;
		printf("cq\n");
		if (parse(info) != 1)
			continue ;
		printf("pl\n");
		// printf("main cmd: %s\n", ((t_command *)((*info)->content))->command);
		if (((t_command *)((*info)->content))->command)
			execute(*info);
		printf("ec\n");
		input = 1;
		ft_strdel(&g_state.line);
	}
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_list	*info;
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
	env_parse(envp);
	minishell(&info, &history);
	ft_lstclear(&history, free);
	free_info(&info);
	return (0);
}