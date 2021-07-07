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
	// tmp = cmd;
	if (!cmd)
		return ;
	else
	{
		com = ((t_program *)(tmp->content));
		while (tmp)
		{
			printf("%s: flag: %d\n", com->args[0], com->flag);
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
	else if (find_command(cmd))
		path_execute(info);
	else if (!ft_strncmp("./", cmd->args[0], 2) ||
	!ft_strncmp("../", cmd->args[0], 3) || cmd->args[0][0] == '/')
	{
		if (find_simple_command(cmd, &type))
			path_execute(info);
		else
			execute_error(cmd->args[0], type);
	}
	else
		execute_error(cmd->command, NOTF);
	g_state.is_fork = FALSE;
}

void		path_execute(t_dlist *info)
{
	t_program	*pro;
	pid_t		pid;
	int			status;
	char		**envp;

	pro = info->content;
	g_state.is_fork = TRUE;
	// restore_term();
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		set_pipe(info);
		set_redirect(pro);
		envp = make_envp();
		if (execve(pro->args[0], pro->args, envp) < 0)
		{
			ft_strdel2(envp);
			execute_error(pro->command, 1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_state.ret = WEXITSTATUS(status);
	}
}
