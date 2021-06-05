#include "../../includes/command.h"
#include <stdio.h>


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