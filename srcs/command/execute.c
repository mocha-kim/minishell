#include "../../includes/command.h"
#include <stdio.h>

static int	arg_cnt(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
/*
** executable -> excute
*/
void		execute(t_parse *cmd)
{
	t_parse *tmp;

	if (!cmd)
		return ;
	else
	{
		printf("cmd : %s\n", cmd->cmd.command);
		while (cmd)
		{
			// pipe(cmd->cmd.pip);
			cmd->cmd.argc = arg_cnt(cmd->cmd.args);
			execute_cmd(cmd->cmd);
			tmp = cmd;
			cmd = cmd->next;
			free(tmp);
		}
	}
}

void		execute_cmd(t_command cmd)
{
	if (cmd.command == 0)
		return ;
	else if (builtin(cmd))
		return ;
}