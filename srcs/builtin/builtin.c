#include "../../includes/builtin.h"

extern t_state	g_state;

int		builtin(t_program cmd)
{
	if (!ft_strcmp("echo", cmd.command) || !ft_strcmp("pwd", cmd.command)
	|| !ft_strcmp("env", cmd.command))
	{
		set_fork_builtin(cmd);
		return (1);
	}
	else if (!ft_strcmp("exit", cmd.command) && cmd.flag == PIPE)
	{
		g_state.ret = 0;
		return (1);
	}
	else if (!ft_strcmp("exit", cmd.command) || !ft_strcmp("cd", cmd.command)
	|| !ft_strcmp("unset", cmd.command) || !ft_strcmp("export", cmd.command))
	{
		builtin_execute(cmd);
		return (1);
	}
	return (0);
}

/*
** cmd is builtin check
** return 0:builtin 아님 1:builtin execute
*/

int		builtin_execute(t_program cmd)
{
	// set_pipe();
	printf("=====builtin=====\n");
	if (cmd.command == 0)
		return (0);
	if (!ft_strcmp("echo", cmd.command))
		ft_echo(&cmd);
	if (!ft_strcmp("cd", cmd.command))
		ft_cd(&cmd);
	if (!ft_strcmp("pwd", cmd.command))
		ft_pwd();
	if (!ft_strcmp("export", cmd.command))
		ft_export(&cmd);
	if (!ft_strcmp("unset", cmd.command))
		ft_unset(cmd);
	if (!ft_strcmp("env", cmd.command))
		ft_env();
	if (!ft_strcmp("exit", cmd.command))
		ft_exit(&cmd);
	// printf("cmd.command: %s\n", cmd.command);
	printf("=============\n");
	return (0);
}

void	set_fork_builtin(t_program cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		builtin_execute(cmd);
		exit(g_state.ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		g_state.ret = status;
	}
}