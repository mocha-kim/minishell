#include "../../includes/command.h"

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
void		execute(t_list *cmd)
{
	t_list 		*tmp;
	t_command	*com;

	if (!cmd)
		return ;
	else
	{
		com = ((t_command *)(cmd->content));
		printf("com = cmd->content\n");
		// printf("%s\n", ((t_command *)(cmd->content))->command);
		// printf("cmd : %s\n", com->command);
		while (cmd)
		{
			// pipe(cmd->cmd.pip);
			com->argc = arg_cnt(com->args);
			execute_cmd(*com);
			tmp = cmd;
			cmd = cmd->next;
			free(com);
			com = cmd->content;
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