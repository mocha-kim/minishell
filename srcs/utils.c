#include "../includes/utils.h"

int		custom_putchar(int c)
{
	return (write(STD_OUT, &c, 1));
}

void	skip_whitespace(char *str, int *i)
{
	while (str[*i] != 0 && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
				|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == '\v'))
				(*i)++;
}

void	free_info(t_list **info)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *info;
	while (tmp)
	{
		if (((t_command *)(tmp->content))->command)
			free(((t_command *)(tmp->content))->command);
		while (((t_command *)(tmp->content))->args[i])
		{
			free(((t_command *)(tmp->content))->args[i]);
			i++;
		}
		if (((t_command *)(tmp->content))->args)
			free(((t_command *)(tmp->content))->args);
		if (((t_command *)(tmp->content))->option)
			free(((t_command *)(tmp->content))->option);
		tmp = tmp->next;
	}
	ft_lstclear(info, free);
}