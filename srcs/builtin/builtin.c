#include "../../includes/builtin.h"

/*
** cmd is builtin check
** return 0:builtin 아님 1:builtin execute
*/
int			builtin(t_command cmd)
{
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
	printf("cmd.command: %s\n", cmd.command);
	printf("=============\n");
	return (0);
}