#include "../../includes/command.h"

/*
** executable -> excute
*/
void		execute(t_parse *cmd)
{
	if (!cmd)
		return ;
	else
	{
		while (cmd)
		{
			// pipe(cmd->cmd.pip);
			execute_cmd(cmd->cmd);
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