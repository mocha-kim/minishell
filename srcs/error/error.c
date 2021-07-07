/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:14:44 by sunhkim           #+#    #+#             */
/*   Updated: 2021/07/07 18:12:30 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"

extern t_state	g_state;

/*
** syntax error print
** return 0:failed 127:succeed(exit)
*/

int		print_syntax_error(int errn)
{
	g_state.ret = 258;
	if (errn == ERR_QUOTE)
		ft_putstr_fd("bash: syntax error quote not closed\n", STD_ERR);
	else if (errn == ERR_SEMICOLONE)
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", STD_ERR);
	else if (errn == ERR_SEMICOLONE2)
		ft_putstr_fd("bash: syntax error near unexpected token `;;'\n"
					, STD_ERR);
	else if (errn == ERR_PIPE)
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n"
					, STD_ERR);
	else if (errn == ERR_PIPE2)
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n"
					, STD_ERR);
	else if (errn == ERR_NEWLINE)
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n"
					, STD_ERR);
	else if (errn == ERR_LAB)
		ft_putstr_fd("bash: syntax error near unexpected token `<'\n", STD_ERR);
	else if (errn == ERR_RAB)
		ft_putstr_fd("bash: syntax error near unexpected token `>'\n", STD_ERR);
	else if (errn == ERR_RAB2)
		ft_putstr_fd("bash: syntax error near unexpected token `>>'\n"
					, STD_ERR);
	return (EXIT_CODE);
}

int		print_memory_error(int errn)
{
	g_state.ret = 1;
	if (errn == ERR_MALLOC)
	{
		ft_putstr_fd("bash: failed to allocate memory.\n", STD_ERR);
		exit(1);
	}
	else if (errn == ERR_IO)
	{
		ft_putstr_fd("bash: IO Error.\n", STD_ERR);
		exit(1);
	}
	else
		return (0);
	return (EXIT_CODE);
}

int		print_exit_error(char *str, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("bash: exit: ", STD_ERR);
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": numeric argument required\n", STD_ERR);
		g_state.ret = 255;
	}
	else
		ft_putstr_fd(str, STD_ERR);
	return (1);
}

void	error_export(char *str)
{
	ft_putstr_fd("bash: export: `", STD_ERR);
	ft_putstr_fd(str, STD_ERR);
	ft_putstr_fd("': not a valid identifier\n", STD_ERR);
	g_state.ret = 1;
}

void	execute_error(char *cmd, int type)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (type == 1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		exit(EXIT_CODE);
	}
	else if (type == IS_DIR)
	{
		if (type == IS_DIR)
			ft_putstr_fd("is a directory\n", 2);
		g_state.ret = 126;
	}
	else if (type == NSFD || type == NOTF)
	{
		g_state.ret = EXIT_CODE;
		if (type == NOTF)
			ft_putstr_fd("command not found\n", STD_ERR);
		else if (type == NSFD)
			ft_putstr_fd("No such file or directory\n", 2);
	}
}
