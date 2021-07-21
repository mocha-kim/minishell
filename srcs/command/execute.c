/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:19 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/21 22:42:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

extern t_state	g_state;

/*
** executable -> excute
*/

void		execute(t_dlist *cmd)
{
	t_dlist		*tmp;
	t_program	*com;
	int			in;
	int			out;

	tmp = ft_dlstlast(cmd);
	if (!cmd)
		return ;
	else
	{
		com = ((t_program *)(tmp->content));
		while (tmp)
		{
			pipe(com->pip);
			in = dup(0);
			out = dup(1);
			execute_cmd(tmp);
			close_fd(tmp, in, out);
			tmp = tmp->next;
			if (tmp)
				com = tmp->content;
		}
	}
	g_state.is_here = FALSE;
}

static void	excute_command(t_dlist *info, t_program *cmd)
{
	if (!ft_strcmp(cmd->args[0], "/bin/cat")
		|| !ft_strcmp(cmd->args[0], "/usr/bin/wc"))
		g_state.need_nl = 1;
	path_execute(info);
}

void		execute_cmd(t_dlist *info)
{
	t_program	*cmd;
	int			type;

	cmd = info->content;
	if (!check_redirection(info))
		return ;
	if (((t_program*)info->content)->argc == 0)
		return ;
	if (builtin(info))
		return ;
	else if (!ft_strncmp("./", cmd->args[0], 2) ||
	!ft_strncmp("../", cmd->args[0], 3) || cmd->args[0][0] == '/')
	{
		if (find_simple_command(cmd, &type))
			path_execute(info);
		else
			execute_error(cmd->args[0], type);
	}
	else if (find_command(cmd))
		excute_command(info, cmd);
	else
		execute_error(cmd->command, NOTF);
	g_state.is_fork = FALSE;
}

void		path_execute(t_dlist *info)
{
	pid_t		pid;
	int			status;
	char		**envp;

	g_state.is_fork = TRUE;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		set_fd(info);
		envp = make_envp();
		if (execve(((t_program*)info->content)->args[0],
		((t_program*)info->content)->args, envp) < 0)
		{
			ft_strdel2(envp);
			execute_error(((t_program*)info->content)->command, 1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_state.ret = WEXITSTATUS(status);
	}
}

void		set_fd(t_dlist *info)
{
	set_pipe(info);
	set_redirect(info->content);
}
