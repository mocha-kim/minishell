#include "../../includes/command.h"

extern t_state	g_state;

int		builtin(t_dlist *info)
{
	t_program	*cmd;

	cmd = info->content;
	printf("builtin\n");
	if (!ft_strcmp("echo", cmd->command) || !ft_strcmp("pwd", cmd->command)
	|| !ft_strcmp("env", cmd->command))
	{
		printf("%s\n", cmd->command);
		set_fork_builtin(info);
		return (1);
	}
	else if (!ft_strcmp("exit", cmd->command) && cmd->flag == F_PIPE)
	{
		g_state.ret = 0;
		return (1);
	}
	else if (!ft_strcmp("exit", cmd->command) || !ft_strcmp("cd", cmd->command)
	|| !ft_strcmp("unset", cmd->command) || !ft_strcmp("export", cmd->command))
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

int		builtin_execute(t_dlist *info)
{
	t_program	*cmd;

	cmd = (t_program*)info->content;
	printf("=====builtin=====\n");
	set_pipe(info);
	if (cmd->command == 0)
		return (0);
	if (!ft_strcmp("echo", cmd->command))
		ft_echo(cmd);
	if (!ft_strcmp("cd", cmd->command))
		ft_cd(cmd);
	if (!ft_strcmp("pwd", cmd->command))
		ft_pwd();
	if (!ft_strcmp("export", cmd->command))
		ft_export(cmd);
	if (!ft_strcmp("unset", cmd->command))
		ft_unset(*cmd);
	if (!ft_strcmp("env", cmd->command))
		ft_env();
	if (!ft_strcmp("exit", cmd->command))
		ft_exit(cmd);
	// printf("cmd.command: %s\n", cmd.command);
	printf("=============\n");
	return (0);
}

void	set_fork_builtin(t_dlist *info)
{
	pid_t		pid;
	int			status;
	t_program	*cmd;

	printf("set_fork_builtin\n");
	cmd = info->content;
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
		waitpid(pid, &status, 0);
		g_state.ret = status;
	}
}
