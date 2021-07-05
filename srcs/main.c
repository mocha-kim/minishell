/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:27:01 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/05 16:07:49 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_state	g_state;

void	prompt(void)
{
	ft_putstr_fd("minishell-", STD_OUT);
	ft_putstr_fd(VERSION, STD_OUT);
	ft_putstr_fd("$ ", STD_OUT);
}

void	handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_state.is_fork == FALSE)
		{
			g_state.sig = 1;
			if (g_state.ptr->tmp)
				ft_strdel(&(g_state.ptr->tmp));
			g_state.ret = 1;
			ft_putstr_fd("\n", STD_OUT);
			prompt();
		}
		else
		{
			g_state.ret = 130;
			write(1, "\n", 1);
		}
	}
	else if (signo == SIGQUIT)
	{
		if (g_state.is_fork == TRUE)
		{
			g_state.ret = 131;
			ft_putstr_fd("Quit: 3\n", STD_OUT);
		}
	}
}

/*
** return 0:success -1:failed 127:exit
*/

int		minishell(t_dlist **programs, t_history **history, char **envp)
{
	// t_history	*tmp;
	char		*line;

	(void)envp;
	line = NULL;
	while (1)
	{
		prompt();
		init_term();
		set_history(history);
		if (save_input() != 1)
			continue ;
		if (save_history(history)!= 1)
			continue ;
		// tmp = *history;
		// printf("============history============\n");
		// while (tmp)
		// {
		// 	printf("save : %s tmp : %s\n", tmp->save, tmp->tmp);
		// 	tmp = tmp->next;
		// }
		// printf("===============================\n");
		line = ft_strdup(g_state.cur->save);
		if (check_quote(line) != 1)
			continue ;
		// printf(">> line %s\n", line);
		restore_term();
		if (run_program(programs, line) != 1)
			continue ;
		free(line);
		free_info(programs);
	}
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_dlist		*programs;
	t_history	*history;

	(void)argc;
	(void)argv;
	programs = NULL;
	history = NULL;
	g_state.sig = 1;
	g_state.cur = NULL;
	g_state.ptr = NULL;
	g_state.env = NULL;
	g_state.is_fork = FALSE;
	g_state.pid = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	env_parse(envp);
	minishell(&programs, &history, envp);
	ft_historyclear(&history, free);
	ft_dlstclear(&programs, free);
	return (g_state.ret);
}
