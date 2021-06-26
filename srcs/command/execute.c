#include "../../includes/command.h"

extern t_state	g_state;

// static int	arg_cnt(char **args)
// {
// 	int		i;

// 	i = 0;
// 	while (args[i])
// 		i++;
// 	return (i);
// }

/*
** executable -> excute
*/

void		execute(t_dlist *cmd)
{
	t_dlist		*tmp;
	t_program	*com;
	int			in;
	int			out;

	tmp = cmd;
	if (!cmd)
		return ;
	else
	{
		com = ((t_program *)(cmd->content));
		while (tmp)
		{
			pipe(com->pip);
			// com->argc = arg_cnt(com->args);
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
	if (builtin(info))
		return ;
	else if (find_command(cmd))
		path_execute(info);
	else if (cmd->args[0][0] == '.' || cmd->args[0][0] == '/')
	{
		if (find_simple_command(cmd, &type))
			path_execute(info);
		else
			execute_error(cmd->args[0], type);
	}
	else
		execute_error(cmd->command, NOTF);
}

void		path_execute(t_dlist *info)
{
	t_program	*pro;
	pid_t		pid;
	int			status;
	char		**envp;
	int			i;

	pro = info->content;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		set_pipe(info);
		if (pro->fd[0] != 0)
			dup2(pro->fd[0], 0);
		if (pro->fd[1] != 1)
			dup2(pro->fd[1], 1);
		envp = make_envp();
		if (execve(pro->args[0], pro->args, envp) < 0)
		{
			i = 0;
			ft_strdel(envp);
			execute_error(pro->command, 1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		g_state.ret = status;
	}
}
