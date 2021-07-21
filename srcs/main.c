/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:27:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/21 22:59:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_state	g_state;

static void	print_minishell(void)
{
	printf("\033[38;5;226m=========================================\033[m");
	printf("\033[38;5;226m=========================================\033[m\n");
	printf("\033[38;5;226m.___  ___.  __  .__   __.  __       _____\033[m");
	printf("\033[38;5;226m__. __    __   _______  __       __\033[m\n");
	printf("\033[38;5;227m|   \\/   | |  | |  \\ |  | |  |     /   \033[m");
	printf("\033[38;5;227m    ||  |  |  | |   ____||  |     |  |\033[m\n");
	printf("\033[38;5;228m|  \\  /  | |  | |   \\|  | |  |    |   (\033[m");
	printf("\033[38;5;228m----`|  |__|  | |  |__   |  |     |  |     \033[m\n");
	printf("\033[38;5;229m|  |\\/|  | |  | |  . `  | |  |     \\   \033[m");
	printf("\033[38;5;229m\\    |   __   | |   __|  |  |     |  |\033[m\n");
	printf("\033[38;5;230m|  |  |  | |  | |  |\\   | |  | .----)   \033[m");
	printf("\033[38;5;230m|   |  |  |  | |  |____ |  `----.|  `----.\033[m\n");
	printf("\033[38;5;231m|__|  |__| |__| |__| \\__| |__| |_______/  \033[m");
	printf("\033[38;5;231m  |__|  |__| |_______||_______||_______|\033[m\n\n");
	printf("\033[38;5;231m==================================yoahn s\033[m");
	printf("\033[38;5;231munhkim===================================\033[m\n");
}

static void	prompt(void)
{
	write(STD_OUT, "minishell-1.0$ ", 16);
}

static void	handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_state.is_fork == FALSE)
		{
			if (g_state.is_here)
			{
				write(1, "\n", 1);
				exit(1);
			}
			write(STD_OUT, "\nminishell-1.0$ ", 17);
			if (g_state.ptr->tmp)
				ft_strdel(&(g_state.ptr->tmp));
			g_state.ret = 1;
		}
		else
		{
			if (g_state.need_nl)
				write(1, "\n", 1);
			g_state.ret = 130;
		}
	}
	else if (signo == SIGQUIT)
	{
		if (g_state.is_fork == TRUE)
		{
			g_state.ret = 131;
			if (!g_state.is_here)
				ft_putstr_fd("Quit: 3\n", STD_OUT);
		}
	}
}

/*
** return 0:success -1:failed 127:exit
*/

int			minishell(t_dlist **programs, t_history **history, char **envp)
{
	char		*line;

	(void)envp;
	line = NULL;
	init_term();
	while (1)
	{
		prompt();
		tcsetattr(STDIN_FILENO, TCSANOW, &g_state.term);
		g_state.need_nl = FALSE;
		set_history(history);
		if (save_input() != 1)
			continue ;
		if (save_history(history) != 1)
			continue ;
		line = ft_strdup(g_state.cur->save);
		if (check_quote(&line) != 1)
			continue ;
		restore_term();
		run_program(programs, line);
		ft_strdel(&line);
		free_program(programs);
	}
	return (0);
}

int			main(int argc, char *argv[], char *envp[])
{
	t_dlist		*programs;
	t_history	*history;

	(void)argc;
	(void)argv;
	programs = NULL;
	history = NULL;
	init_state();
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	env_parse(envp);
	print_minishell();
	minishell(&programs, &history, envp);
	free_state();
	ft_dlstclear(&programs, free);
	ft_historyclear(&history, free);
	return (g_state.ret);
}
