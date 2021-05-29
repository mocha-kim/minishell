#include "minishell.h"

/*
** cmd is builtin check
*/
int         builtin(t_command cmd)
{
    if (cmd.command == 0)
        return (0);
    if (!ft_strcmp("echo", cmd.command))
        ft_echo(cmd);
    if (!ft_strcmp("cd", cmd.command)
    || !ft_strcmp("pwd", cmd.command) || !ft_strcmp("export", cmd.command)
    || !ft_strcmp("unset", cmd.command) || !ft_strcmp("env", cmd.command)
    || !ft_strcmp("exit", cmd.command))
        return (1);
}