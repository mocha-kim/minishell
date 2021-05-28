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

int		syntax_check(t_list **lst, char *line)
{
	int		i;
	int		j;
	int		size;
	t_list	*new;

	i = 0;
	
	size = ft_strlen(line);
	while (i < size)
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (j < size && line[j] != ';')
			j++;
		if (i == j || (j + 1 < size && line[j + 1] == ';'))
		{
			ft_lstclear(lst, free);
			lst = 0;
			write(2, "bash: syntax error near unexpected token `;", 43);
			if (line[j + 1] == ';')
				write(2, ";", 1);
			write(2, "'\n", 2);
			return (-1);
		}
		new = ft_lstnew((void*)ft_substr(line, i, j - i + 1));
		ft_lstadd_back(lst, new);
		i += j;
		i++;
	}
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
	while (lst)
	{
		parse_command(*info, lst);
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp, free);
	}
	return (command);
}

