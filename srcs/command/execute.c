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
	t_list		*tmp;
	t_command	*com;

	tmp = cmd;
	if (!cmd)
		return ;
	else
	{
		com = ((t_command *)(cmd->content));
		printf("cmd : %s\n", com->command);
		while (tmp)
		{
			pipe(((t_command*)(cmd->content))->pip);
			com->argc = arg_cnt(com->args);
			execute_cmd(*com);
			printf("execute_cmd success\n");
			tmp = tmp->next;
			if (tmp)
				com = tmp->content;
		}
	}
}

void		execute_cmd(t_command cmd)
{
	printf("execute_cmd\n");
	if (cmd.command == 0)
		return ;
	else if (builtin(cmd))
		return ;
}
