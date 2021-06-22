#include "../../includes/command.h"

int			check_redirection(t_dlist *info)
{
	t_program	*cmd;
	t_dlist		*tmp;

	cmd = info->content;
	cmd->fd[0] = 0;
	cmd->fd[1] = 1;
	tmp = info;
	while (tmp->next && cmd->flag > 0 && cmd->flag < 4)
	{
		// fd[0] == 0, fd[1] == 1이 아니면 파일 열기 전에 이미 열려있던건 close하고 ㄷ 
		if (cmd->flag == REDIR_OUT)
			cmd->fd[1] = open(((t_program*)(tmp->next->content))->command,
			O_WRONLY | O_APPEND | O_CREAT, 0644);
		else if (cmd->flag == REDIR_APP)
			cmd->fd[1] = open(((t_program*)(tmp->next->content))->command,
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else
			cmd->fd[0] = open(((t_program*)(tmp->next->content))->command,
			O_RDONLY);
		tmp = tmp->next;
	}
	return  (1);
}