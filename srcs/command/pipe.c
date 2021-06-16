#include "../../includes/minishell.h"

/*
** pip[0] : read file descriptor
** pip[1] : write file descriptor
*/
void		set_pipe(t_dlist *info)
{
	t_command	*cmd;

	cmd = info->content;
	if (cmd->flag == PIPE || (info->prev 
	&& ((t_command*)info->prev->content)->flag == PIPE))
	{
		if (cmd->flag == PIPE)
			dup2(cmd->pip[1], 1);
		if (info->prev && ((t_command*)info->prev->content)->flag == PIPE)
			dup2(((t_command*)info->prev->content)->pip[0], 0);
	}
}

void		close_fd(t_dlist *info, int in, int out)
{
	t_command	*cmd;
	t_command	*prev;

	cmd = info->content;
	prev = info->prev;
	if (info->prev)
		close(prev->pip[0]);
	close(cmd->pip[1]);
	if (!info->next)
		close(cmd->pip[0]);
	dup2(in, 0);
	dup2(out, 1);
}