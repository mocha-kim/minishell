/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:30 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/21 22:41:24 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

extern t_state	g_state;

int			renewal(t_program *cmd)
{
	int		i;
	int		cnt;
	char	**tmp;

	i = 0;
	cnt = 0;
	while (i < cmd->argc)
	{
		if (cmd->args[i][0] == '<' || cmd->args[i][0] == '>')
			cnt += 2;
		i++;
	}
	if (cnt == 0)
		return (1);
	cnt = cmd->argc - cnt;
	tmp = 0;
	tmp = new_args(cmd, tmp, cnt);
	ft_strdel2(cmd->args);
	cmd->args = tmp;
	cmd->argc = cnt;
	return (1);
}

static void	file_open(t_program *cmd, int i)
{
	if (cmd->args[i][0] == '<')
	{
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->args[i][1] == 0)
		{
			g_state.is_here = FALSE;
			cmd->fd[0] = open(cmd->args[i + 1], O_RDONLY);
		}
		else if (cmd->args[i][1] == '<')
			g_state.is_here = i + 1;
	}
	else if (cmd->args[i][0] == '>')
	{
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		if (cmd->args[i][1] == 0)
			cmd->fd[1] = open(cmd->args[i + 1],
							O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else if (cmd->args[i][1] == '>')
			cmd->fd[1] = open(cmd->args[i + 1],
							O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
}

int			check_redirection(t_dlist *info)
{
	t_program	*cmd;
	int			i;

	i = 0;
	cmd = info->content;
	cmd->fd[0] = 0;
	cmd->fd[1] = 1;
	while (cmd->args[i])
	{
		file_open(cmd, i);
		if (cmd->fd[0] == -1 || cmd->fd[1] == -1)
		{
			execute_error(cmd->args[i + 1], NSFD);
			return (0);
		}
		i++;
	}
	if (g_state.is_here)
	{
		pipe(cmd->heredoc);
		read_line(cmd->heredoc[1], cmd->args[g_state.is_here]);
		cmd->fd[0] = cmd->heredoc[0];
	}
	return (renewal(cmd));
}

char		**new_args(t_program *cmd, char **tmp, int cnt)
{
	int		i;
	int		j;

	if (!(tmp = malloc(sizeof(char*) * (cnt + 1))))
		return (0);
	i = 0;
	j = 0;
	while (j < cnt && cmd->args[i] != 0)
	{
		if (cmd->args[i][0] != '<' && cmd->args[i][0] != '>')
			tmp[j++] = ft_strdup(cmd->args[i]);
		if (cmd->args[i][0] == '<' || cmd->args[i][0] == '>')
			i++;
		i++;
	}
	tmp[j] = 0;
	return (tmp);
}

void		set_redirect(t_program *pro)
{
	if (pro->fd[0] != 0)
	{
		close(0);
		dup2(pro->fd[0], 0);
	}
	if (pro->fd[1] != 1)
	{
		close(1);
		dup2(pro->fd[1], 1);
	}
}
