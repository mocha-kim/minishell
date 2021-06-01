#include "../../includes/parsing.h"

/*
** parse command(save to info) from line
** return 0:failed 1:succeed 
*/
int		parse_command(t_parse **info, t_list *lst)
{
	int		i;
	char	*cmd;

	i = 0;
	if (!(*info = malloc(sizeof(t_parse))))
		return (0);
	cmd = (char*)lst->content;
	while (*cmd && *cmd == ' ')
		cmd++;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	(*info)->cmd.command = ft_substr(cmd, 0, i);
	(*info)->cmd.args = ft_substr(cmd, i + 1, ft_strlen(cmd) - i);
	return (1);
}

/*
** parse line(save to info)
** return 0:failed 1:succeed 
*/
int		parse(char *line, t_parse **info)
{
	t_list	*lst;
	t_list	*tmp;
	t_parse *print;

	lst = 0;
	if (syntax_check(&lst, line) < 0)
		return (0);
	while (lst)
	{
		parse_command(info, lst);
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp, free);
	}
	print = *info;
	while (print) {
		printf("cmd : %s, args : %s\n", print->cmd.command, print->cmd.args);
		print = print->next;
	}
	return (1);
}

