#include "../../includes/command.h"

extern t_state	g_state;

int			builtin(t_dlist *info)
{
	t_program	*cmd;

	cmd = info->content;
	if (!ft_strcmp("echo", cmd->args[0]) || !ft_strcmp("pwd", cmd->args[0])
	|| !ft_strcmp("env", cmd->args[0]))
	{
		set_fork_builtin(info);
		return (1);
	}
	else if (!ft_strcmp("exit", cmd->args[0]) && (cmd->flag == F_PIPE
	|| (info->prev && ((t_program*)info->prev->content)->flag == F_PIPE)))
	{
		g_state.ret = 0;
		return (1);
	}
	else if (!ft_strcmp("exit", cmd->args[0]) || !ft_strcmp("cd", cmd->args[0])
	|| !ft_strcmp("unset", cmd->args[0]) || !ft_strcmp("export", cmd->args[0]))
	{
		builtin_execute(info);
		return (1);
	}
	return (0);
}

/*
** cmd is builtin check
** return 0:builtin 아님 1:builtin execute
*/

int			builtin_execute(t_dlist *info)
{
	t_program	*cmd;

	cmd = (t_program*)info->content;
	set_pipe(info);
	set_redirect(cmd);
	if (cmd->args[0] == 0)
		return (0);
	if (!ft_strcmp("echo", cmd->args[0]))
		ft_echo(cmd);
	if (!ft_strcmp("cd", cmd->args[0]))
		ft_cd(cmd);
	if (!ft_strcmp("pwd", cmd->args[0]))
		ft_pwd();
	if (!ft_strcmp("export", cmd->args[0]))
		ft_export(cmd);
	if (!ft_strcmp("unset", cmd->args[0]))
		ft_unset(*cmd);
	if (!ft_strcmp("env", cmd->args[0]))
		ft_env();
	if (!ft_strcmp("exit", cmd->args[0]))
		ft_exit(cmd);
	return (0);
}

void		handler_p(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT)
	{
		if (g_state.is_fork == TRUE)
			return ;
	}
}

void		set_fork_builtin(t_dlist *info)
{
	pid_t		pid;
	int			status;
	t_program	*cmd;

	cmd = info->content;
	g_state.is_fork = TRUE;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		builtin_execute(info);
		exit(g_state.ret);
	}
	else
	{	
		// signal(SIGINT, handler_p);
		// signal(SIGQUIT, handler_p);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_state.ret = WEXITSTATUS(status);
	}
}
