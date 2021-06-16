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

void		execute(t_dlist *cmd)
{
	t_dlist		*tmp;
	t_program	*com;

	tmp = cmd;
	if (!cmd)
		return ;
	else
	{
		com = ((t_program *)(cmd->content));
		while (tmp)
		{
			pipe(((t_program*)(cmd->content))->pip);
			com->argc = arg_cnt(com->args);
			execute_cmd(*com);
			tmp = tmp->next;
			if (tmp)
				com = tmp->content;
		}
	}
}

void		execute_cmd(t_program cmd)
{
	if (cmd.command == 0)
		return ;
	else if (builtin(cmd))
		return ;
}
