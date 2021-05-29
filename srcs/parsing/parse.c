#include "../../includes/parsing.h"

int		parse_command(t_parse *info, t_list *lst)
{
	int		i;
	char	*cmd;

	i = 0;
	if (!(info = malloc(sizeof(t_parse))))
		return (0);
	cmd = (char*)lst->content;
	while (*cmd && *cmd == ' ')
		cmd++;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	info->cmd.command = ft_substr(cmd, 0, i);
	
	return (1);
}

int		parse(char *line, t_parse **info)
{
	int		command;
	t_list	*lst;
	t_list	*tmp;
	
	lst = 0;
	if (syntax_check(&lst, line) < 0)
		return (0);
	command = 0;
	*info = 0;
	while (lst)
	{
		parse_command(*info, lst);
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp, free);
	}
	return (command);
}

