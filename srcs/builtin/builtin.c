#include "../../includes/builtin.h"

/*
** cmd is builtin check
** return 0:builtin 아님 1:builtin execute
*/
int			builtin(t_command cmd)
{
	if (cmd.command == 0)
		return (0);
	if (!ft_strcmp("echo", cmd.command))
		ft_echo(&cmd);
	if (!ft_strcmp("cd", cmd.command)
	|| !ft_strcmp("pwd", cmd.command) || !ft_strcmp("export", cmd.command)
	|| !ft_strcmp("unset", cmd.command) || !ft_strcmp("env", cmd.command)
	|| !ft_strcmp("exit", cmd.command))
		return (1);
	return (0);
}