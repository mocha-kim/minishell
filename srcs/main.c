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
	ft_putstr_fd("\b\b", STD_ERR);
	if (signo == SIGINT)
	{
		g_state.sig = 1;
		if (g_state.line)
			ft_strdel(&g_state.line);
		ft_putstr_fd("  \n", STD_ERR);
	}
	else if (signo == SIGQUIT)
	{
		g_state.sig = 0;
		ft_putstr_fd("  \b\b", STD_ERR);
	}
	if (g_state.sig)
		prompt();
}

/*
** return 0:success -1:failed 127:exit
*/
int		minishell(t_dlist **programs, t_dlist **history)
{
	int		input;
	t_dlist	*tmp;

	input = 1;
	while (1)
	{
		prompt();
		if (save_input() != 1)
			continue ;
		printf("> complete si\n");
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
		if (parse_env() != 1)
			continue ;
		if (check_quote() != 1)
			continue ;
		printf("> complete cq\n");
		if (parse(programs) != 1)
			continue ;
		printf("> complete pl\n");
		if (((t_program *)((*programs)->content))->command)
			execute(*programs);
		printf("> complete ec\n");
		input = 1;
		ft_strdel(&g_state.line);
		free_info(programs);
	}
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_dlist	*programs;
	t_dlist	*history;

	(void)argc;
	(void)argv;
	(void)envp;
	programs = NULL;
	history = NULL;
	g_state.sig = 1;

	// signal
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	// minishell
	env_parse(envp);
	minishell(&programs, &history);
	ft_dlstclear(&history, free);
	ft_dlstclear(&programs, free);
	return (g_state.ret);
}