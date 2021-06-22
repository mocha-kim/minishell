#include "../../includes/command.h"

/*
** pip[0] : read file descriptor
** pip[1] : write file descriptor
*/
void		set_pipe(t_dlist *info)
{
	t_program	*cmd;

	cmd = info->content;
	printf("set pipe: %s : %p\n", cmd->command, cmd);
	printf("flag: %d\n", cmd->flag);
	printf("current pipe in: %d, out: %d\n", cmd->pip[0], cmd->pip[1]);
	if (cmd->flag == F_PIPE || (info->prev 
	&& ((t_program*)info->prev->content)->flag == F_PIPE))
	{
		if (cmd->flag == F_PIPE)
		{
			printf("flag pipe: out %d, in: %d\n", cmd->pip[1], cmd->pip[0]);
			dup2(cmd->pip[1], 1);
			close(cmd->pip[0]);
		}
		if (info->prev && ((t_program*)info->prev->content)->flag == F_PIPE)
		{
			printf("prev pipe in: %d\n", ((t_program*)info->prev->content)->pip[0]);
			dup2(((t_program*)info->prev->content)->pip[0], 0);
		}
	}
}

void		close_fd(t_dlist *info, int in, int out)
{
	t_program	*cmd;
	t_program	*prev;

	cmd = info->content;
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	if (info->prev)
	{
		prev = info->prev->content;
		close(prev->pip[0]);
	}
	close(cmd->pip[1]);
	if (!info->next)
		close(cmd->pip[0]);
}