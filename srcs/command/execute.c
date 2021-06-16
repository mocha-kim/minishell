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
	t_command	*com;
	int			in;
	int			out;

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
			execute_cmd(tmp);
			in = dup(0);
			out = dup(1);
			printf("execute_cmd success\n");
			close_fd(com, in, out);
			tmp = tmp->next;
			if (tmp)
				com = tmp->content;
		}
	}
}

void		execute_cmd(t_dlist *info)
{
	t_command	*cmd;

	cmd = info->content;
	printf("execute_cmd\n");
	if (cmd->command == 0)
		return ;
	else if (builtin(*cmd))
		return ;
}
